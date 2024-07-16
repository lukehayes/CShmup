cmake_minimum_required(VERSION 3.2)
project(CGame)

# Variables.
#
set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "CGame")
set(CMAKE_C_FLAGS  "-Wall -fno-strict-aliasing")
 
# Add debugging option.
#
option(DEV_DEBUG "Enter debug mode" 0)
if (DEV_DEBUG)
  add_definitions(-DDEV_DEBUG)
endif()

find_package(raylib 5 REQUIRED)

# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})

# Create the final binary.
# 
add_executable(${BIN_NAME} main.c ${SRC_FILES})

# Create the final binary.
# 
add_subdirectory(src)


target_link_libraries(${BIN_NAME} raylib)

# Build the CGame library.
# 
target_link_libraries(${BIN_NAME} CGameLib)

