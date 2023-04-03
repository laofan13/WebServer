//===----------------------------------------------------------------------===//
//                         WebServer
//
// common/file_util.hpp
//
//
//===----------------------------------------------------------------------===//
#pragma once

#include "common/noncopyable.hpp"

#include <string>

namespace webserver {

class AppendFile : noncopyable {
 public:
  explicit AppendFile(std::string filename);
  ~AppendFile();
  // append 会向文件写
  void append(const char *logline, const size_t len);
  void flush();

 private:
  size_t write(const char *logline, size_t len);
  FILE *fp_;
  char buffer_[64 * 1024];
};

} // namespace webserver