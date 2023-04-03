add_library(
  webserver_event
  OBJECT
  event_loop_thread_pool.cpp
  event_loop_thread.cpp
  event_loop.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_event>
  PARENT_SCOPE)
