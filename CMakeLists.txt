cmake_minimum_required(VERSION 3.11)
project(xdash VERSION 0.0.1 
    DESCRIPTION "Nifty little graphical dash for X11"
    LANGUAGES CXX)

add_compile_options(-Wall -Wextra -W -Wshadow -Wformat -fexceptions)
set(CMAKE_CXX_FLAGS_DEBUG "-g -pipe")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -pipe")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# set(CAIRO_INCLUDE_DIR "/usr/include/cairo")

find_package(X11 REQUIRED) 
find_package(Cairo REQUIRED)

message(STATUS "Fetching SimpleIni")
include(FetchContent)
FetchContent_Declare(
        SimpleIni
        GIT_REPOSITORY https://github.com/brofield/simpleini.git
        GIT_TAG v4.22
        GIT_SHALLOW TRUE
        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(SimpleIni)

include_directories(src)
include_directories(build/third_party/simpleini)
include_directories(${Cairo_INCLUDE_DIRS})
include_directories("/usr/include/cairo")

#file(GLOB SOURCES "src/*.cpp")

set(SOURCES
    "src/appds.cpp"
    "src/config.cpp"
    "src/logger.cpp"
    "src/main.cpp"
    "src/trigger.cpp"
    "src/overlay.cpp"
 #   "src/xdash.cpp"
    )

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${X11_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${Cairo_LIBRARIES})
target_link_libraries(${PROJECT_NAME} "-lcairo")
