add_subdirectory(main)
add_subdirectory(common)
add_subdirectory(event)
add_subdirectory(log)
add_subdirectory(network)
add_subdirectory(server)
add_subdirectory(timer)

# add_library(webserver STATIC ${ALL_OBJECT_FILES})
add_executable(webserver ${ALL_OBJECT_FILES})

set(WEBSERVER_LIBS
        webserver_main
        webserver_common
        webserver_event
        webserver_log
        webserver_network
        webserver_server
        webserver_timer
        )

find_package(Threads REQUIRED)

set(WEBSERVER_THIRDPARTY_LIBS
        Threads::Threads
        )

target_link_libraries(
        webserver
        ${WEBSERVER_LIBS}
        ${WEBSERVER_THIRDPARTY_LIBS})

target_include_directories(
        webserver PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
