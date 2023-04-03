add_library(
  webserver_log
  OBJECT
  async_logging.cpp
  log_file.cpp
  log_stream.cpp
  log.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_log>
  PARENT_SCOPE)
