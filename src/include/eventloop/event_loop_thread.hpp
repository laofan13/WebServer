//===----------------------------------------------------------------------===//
//                         WebServer
//
// eventloop/event_loop_thread.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "eventloop/event_loop.hpp"
#include "common/condition.hpp"
#include "common/mutex_lock.hpp"
#include "common/thread.hpp"
#include "common/noncopyable.hpp"

namespace webserver {

class EventLoopThread : noncopyable {
 public:
  EventLoopThread();
  ~EventLoopThread();
  EventLoop* startLoop();

 private:
  void threadFunc();
  EventLoop* loop_;
  bool exiting_;
  Thread thread_;
  MutexLock mutex_;
  Condition cond_;
};

} // namespace webserver