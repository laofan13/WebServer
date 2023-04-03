//===----------------------------------------------------------------------===//
//                         WebServer
//
// common/count_down_latch.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "common/condition.hpp"
#include "common/mutex_lock.hpp"
#include "common/noncopyable.hpp"

namespace webserver {

class CountDownLatch : noncopyable {
 public:
  explicit CountDownLatch(int count);
  void wait();
  void countDown();

 private:
  mutable MutexLock mutex_;
  Condition condition_;
  int count_;
};

} // namespace webserver