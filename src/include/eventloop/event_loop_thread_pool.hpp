//===----------------------------------------------------------------------===//
//                         WebServer
//
// eventloop/event_loop_thread_pool.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "log/log.hpp"
#include "eventloop/event_loop_thread.hpp"
#include "common/noncopyable.hpp"

#include <memory>
#include <vector>

namespace webserver {

class EventLoopThreadPool : noncopyable {
 public:
  EventLoopThreadPool(EventLoop* baseLoop, int numThreads);

  ~EventLoopThreadPool() { LOG << "~EventLoopThreadPool()"; }
  void start();

  EventLoop* getNextLoop();

 private:
  EventLoop* baseLoop_;
  bool started_;
  int numThreads_;
  int next_;
  std::vector<std::shared_ptr<EventLoopThread>> threads_;
  std::vector<EventLoop*> loops_;
};

} // namespace webserver