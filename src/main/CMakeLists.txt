add_library(
  webserver_main
  OBJECT
  main.cpp
)
set(ALL_OBJECT_FILES
  ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:webserver_main>
  PARENT_SCOPE)
