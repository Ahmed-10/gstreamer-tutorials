cmake_minimum_required(VERSION 3.2)

project(gstreamer-rtsp-server VERSION 0.1 LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_GSTREAMER REQUIRED gstreamer-1.0)
pkg_search_module(PKG_GSTREAMER_RTSP REQUIRED gstreamer-rtsp-server-1.0)

set(Includes ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PKG_GSTREAMER_INCLUDE_DIRS} ${PKG_GSTREAMER_RTSP_INCLUDE_DIRS})
set(Libs ${PKG_GSTREAMER_LDFLAGS} ${PKG_GSTREAMER_RTSP_LDFLAGS})

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Includes})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Libs})