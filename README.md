# WebServer
C++ High Performance Web Server


$BUILD_DIR/WebServer/WebServer -t 4 -p 3306 -l $LOG_FILE

$WEBBENCH_DIR/webbench -c 10000 -t 5 http://127.0.0.1:3306/