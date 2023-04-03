add_library(
  webserver_timer
  OBJECT
  timer.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_timer>
  PARENT_SCOPE)
