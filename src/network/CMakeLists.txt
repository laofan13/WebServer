add_library(
  webserver_network
  OBJECT
  channel.cpp
  epoll.cpp
  http.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_network>
  PARENT_SCOPE)
