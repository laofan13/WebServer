//===----------------------------------------------------------------------===//
//                         WebServer
//
// network/epoll.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "network/channel.hpp"
#include "network/http.hpp"
#include "timer/timer.hpp"

#include <sys/epoll.h>
#include <memory>
#include <unordered_map>
#include <vector>

namespace webserver {

class Epoll {
 public:
  Epoll();
  ~Epoll();
  void epoll_add(SP_Channel request, int timeout);
  void epoll_mod(SP_Channel request, int timeout);
  void epoll_del(SP_Channel request);
  std::vector<std::shared_ptr<Channel>> poll();
  std::vector<std::shared_ptr<Channel>> getEventsRequest(int events_num);
  void add_timer(std::shared_ptr<Channel> request_data, int timeout);
  int getEpollFd() { return epollFd_; }
  void handleExpired();

 private:
  static const int MAXFDS = 100000;
  int epollFd_;
  std::vector<epoll_event> events_;
  std::shared_ptr<Channel> fd2chan_[MAXFDS];
  std::shared_ptr<HttpData> fd2http_[MAXFDS];
  TimerManager timerManager_;
};


} // namespace webserver