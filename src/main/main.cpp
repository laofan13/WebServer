#include "server/server.hpp"

#include "log/log.hpp"

#include <getopt.h>
#include <string>

using namespace webserver;

int main(int argc, char *argv[]) {
  int threadNum = 4;
  int port = 80;
  std::string logPath = "./WebServer.log";

  // parse args
  int opt;
  const char *str = "t:l:p:";
  while ((opt = getopt(argc, argv, str)) != -1) {
    switch (opt) {
      case 't': {
        threadNum = atoi(optarg);
        break;
      }
      case 'l': {
        logPath = optarg;
        if (logPath.size() < 2 || optarg[0] != '/') {
          printf("logPath should start with \"/\"\n");
          abort();
        }
        break;
      }
      case 'p': {
        port = atoi(optarg);
        break;
      }
      default:
        break;
    }
  }
  webserver::Logger::setLogFileName(logPath);
// STL库在多线程上应用
#ifndef _PTHREADS
  LOG << "_PTHREADS is not defined !";
#endif
  webserver::EventLoop mainLoop;
  webserver::Server myHTTPServer(&mainLoop, threadNum, port);
  myHTTPServer.start();
  mainLoop.loop();
  return 0;
}