//===----------------------------------------------------------------------===//
//                         WebServer
//
// event/event_loop_thread_pool.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "log/log.hpp"
#include "event/event_loop_thread.hpp"
#include "common/noncopyable.hpp"

#include <memory>
#include <vector>

namespace webserver {

class eventThreadPool : noncopyable {
 public:
  eventThreadPool(event* baseLoop, int numThreads);

  ~eventThreadPool() { LOG << "~eventThreadPool()"; }
  void start();

  event* getNextLoop();

 private:
  event* baseLoop_;
  bool started_;
  int numThreads_;
  int next_;
  std::vector<std::shared_ptr<eventThread>> threads_;
  std::vector<event*> loops_;
};

} // namespace webserver