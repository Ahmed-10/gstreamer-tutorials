cmake_minimum_required(VERSION 3.2)

if(NOT VERSION)
    message("warning: version variable must be set determine the project for build")
    message("setting VERSION to 1")
    set(VERSION 1)
endif()

project(basic-tutorial VERSION 0.1 LANGUAGES C)

find_package(PkgConfig REQUIRED)
pkg_search_module(PKG_GSTREAMER REQUIRED gstreamer-1.0)
if(VERSION EQUAL 5)
    pkg_search_module(PKG_GSTREAMERVIDEO REQUIRED gstreamer-video-1.0)
    pkg_search_module(GTK REQUIRED gtk+-3.0)
endif()

if(VERSION EQUAL 8)
    pkg_search_module(PKG_GSTREAMERAUDIO REQUIRED gstreamer-audio-1.0)
endif()

set(Includes 
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PKG_GSTREAMER_INCLUDE_DIRS}
    ${PKG_GSTREAMERVIDEO_INCLUDE_DIRS}
    ${PKG_GSTREAMERAUDIO_INCLUDE_DIRS}
    ${GTK_INCLUDE_DIRS}
)
set(Libs ${PKG_GSTREAMER_LDFLAGS} ${PKG_GSTREAMERVIDEO_LDFLAGS} ${PKG_GSTREAMERAUDIO_LDFLAGS} ${GTK_LDFLAGS})

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}-${VERSION}/main.c)
target_include_directories(${PROJECT_NAME} PRIVATE ${Includes})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Libs})