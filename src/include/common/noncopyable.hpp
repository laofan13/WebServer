//===----------------------------------------------------------------------===//
//                         WebServer
//
// common/noncopyable.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

namespace webserver {

class noncopyable {
 protected:
  noncopyable() {}
  ~noncopyable() {}

 private:
  noncopyable(const noncopyable&);
  const noncopyable& operator=(const noncopyable&);
};

} // namespace webserver