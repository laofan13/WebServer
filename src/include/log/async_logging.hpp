//===----------------------------------------------------------------------===//
//                         WebServer
//
// log/async_logging.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "log/log_stream.hpp"
#include "common/count_down_latch.hpp"
#include "common/mutex_lock.hpp"
#include "common/thread.hpp"
#include "common/noncopyable.hpp"

#include <functional>
#include <string>
#include <vector>
namespace webserver {

class AsyncLogging : noncopyable {
 public:
  AsyncLogging(const std::string basename, int flushInterval = 2);
  ~AsyncLogging() {
    if (running_) stop();
  }
  void append(const char* logline, int len);

  void start() {
    running_ = true;
    thread_.start();
    latch_.wait();
  }

  void stop() {
    running_ = false;
    cond_.notify();
    thread_.join();
  }

 private:
  void threadFunc();
  typedef FixedBuffer<kLargeBuffer> Buffer;
  typedef std::vector<std::shared_ptr<Buffer>> BufferVector;
  typedef std::shared_ptr<Buffer> BufferPtr;
  const int flushInterval_;
  bool running_;
  std::string basename_;
  Thread thread_;
  MutexLock mutex_;
  Condition cond_;
  BufferPtr currentBuffer_;
  BufferPtr nextBuffer_;
  BufferVector buffers_;
  CountDownLatch latch_;
};

} // namespace webserver