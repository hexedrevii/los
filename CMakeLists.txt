cmake_minimum_required(VERSION 3.10)
project(los LANGUAGES CXX VERSION 1.0)

add_executable(${PROJECT_NAME}
  los/main.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE
  los
)
