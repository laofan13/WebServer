add_library(
  webserver_eventloop
  OBJECT
  event_loop_thread_pool.cpp
  event_loop_thread.cpp
  event_loop.cpp
  thread_pool.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_eventloop>
  PARENT_SCOPE)
