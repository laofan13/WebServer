add_library(
  webserver_common
  OBJECT
  count_down_latch.cpp
  file_util.cpp
  thread.cpp
  thread_pool.cpp
  util.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_common>
  PARENT_SCOPE)
