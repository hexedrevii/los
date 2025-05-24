cmake_minimum_required(VERSION 3.10)
project(los LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME}
  los/main.cpp
  los/user.cpp

  los/release.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  los
)
