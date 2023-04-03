//===----------------------------------------------------------------------===//
//                         WebServer
//
// server/server.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "network/channel.hpp"
#include "event/event_loop.hpp"
#include "event/event_loop_thread_pool.hpp"

#include <memory>

namespace webserver {

class Server {
 public:
  Server(event *loop, int threadNum, int port);
  ~Server() {}
  event *getLoop() const { return loop_; }
  void start();
  void handNewConn();
  void handThisConn() { loop_->updatePoller(acceptChannel_); }

 private:
  event *loop_;
  int threadNum_;
  std::unique_ptr<eventThreadPool> eventThreadPool_;
  bool started_;
  std::shared_ptr<Channel> acceptChannel_;
  int port_;
  int listenFd_;
  static const int MAXFDS = 100000;
};

} // namespace webserver