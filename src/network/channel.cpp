#include "network/channel.hpp"

#include "network/epoll.hpp"
#include "event/event_loop.hpp"
#include "common/util.hpp"

#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <queue>

namespace webserver {

Channel::Channel(event *loop)
    : loop_(loop), events_(0), lastEvents_(0), fd_(0) {}

Channel::Channel(event *loop, int fd)
    : loop_(loop), fd_(fd), events_(0), lastEvents_(0) {}

Channel::~Channel() {
  // loop_->poller_->epoll_del(fd, events_);
  // close(fd_);
}

int Channel::getFd() { return fd_; }
void Channel::setFd(int fd) { fd_ = fd; }

void Channel::handleRead() {
  if (readHandler_) {
    readHandler_();
  }
}

void Channel::handleWrite() {
  if (writeHandler_) {
    writeHandler_();
  }
}

void Channel::handleConn() {
  if (connHandler_) {
    connHandler_();
  }
}

} // namespace webserver