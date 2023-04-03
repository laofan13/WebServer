#include "event/event_loop_thread_pool.hpp"

namespace webserver {
  
eventThreadPool::eventThreadPool(event *baseLoop, int numThreads)
    : baseLoop_(baseLoop), started_(false), numThreads_(numThreads), next_(0) {
  if (numThreads_ <= 0) {
    LOG << "numThreads_ <= 0";
    abort();
  }
}

void eventThreadPool::start() {
  baseLoop_->assertInLoopThread();
  started_ = true;
  for (int i = 0; i < numThreads_; ++i) {
    std::shared_ptr<eventThread> t(new eventThread());
    threads_.push_back(t);
    loops_.push_back(t->startLoop());
  }
}

event *eventThreadPool::getNextLoop() {
  baseLoop_->assertInLoopThread();
  assert(started_);
  event *loop = baseLoop_;
  if (!loops_.empty()) {
    loop = loops_[next_];
    next_ = (next_ + 1) % numThreads_;
  }
  return loop;
}

} // namespace webserver