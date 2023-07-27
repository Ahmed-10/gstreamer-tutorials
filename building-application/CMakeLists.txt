cmake_minimum_required(VERSION 3.2)

project(gstreamer-app VERSION 0.1 LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_GSTREAMER REQUIRED gstreamer-1.0)


set(Includes ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${PKG_GSTREAMER_INCLUDE_DIRS})
set(Libs ${PKG_GSTREAMER_LDFLAGS})

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
message(SOURCES)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Includes})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Libs})