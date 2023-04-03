add_library(
  webserver_server
  OBJECT
  server.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_server>
  PARENT_SCOPE)
