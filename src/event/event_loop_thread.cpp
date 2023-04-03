#include "event/event_loop_thread.hpp"

#include <functional>

namespace webserver {

eventThread::eventThread()
    : loop_(NULL),
      exiting_(false),
      thread_(std::bind(&eventThread::threadFunc, this), "eventThread"),
      mutex_(),
      cond_(mutex_) {}

eventThread::~eventThread() {
  exiting_ = true;
  if (loop_ != NULL) {
    loop_->quit();
    thread_.join();
  }
}

event* eventThread::startLoop() {
  assert(!thread_.started());
  thread_.start();
  {
    MutexLockGuard lock(mutex_);
    // 一直等到threadFun在Thread里真正跑起来
    while (loop_ == NULL) cond_.wait();
  }
  return loop_;
}

void eventThread::threadFunc() {
  event loop;

  {
    MutexLockGuard lock(mutex_);
    loop_ = &loop;
    cond_.notify();
  }

  loop.loop();
  // assert(exiting_);
  loop_ = NULL;
}

} // namespace webserver