//===----------------------------------------------------------------------===//
//                         WebServer
//
// event/event_loop_thread.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "event/event_loop.hpp"
#include "common/condition.hpp"
#include "common/mutex_lock.hpp"
#include "common/thread.hpp"
#include "common/noncopyable.hpp"

namespace webserver {

class eventThread : noncopyable {
 public:
  eventThread();
  ~eventThread();
  event* startLoop();

 private:
  void threadFunc();
  event* loop_;
  bool exiting_;
  Thread thread_;
  MutexLock mutex_;
  Condition cond_;
};

} // namespace webserver