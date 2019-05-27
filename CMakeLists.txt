#project(pear)
#add_executable(${PROJECT_NAME} "main.cpp")

# cd build/default && cmake -GNinja ../..

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cheeseburger)

#add_library(chucknorris
#  include/ChuckNorris.hpp
#  src/ChuckNorris.cpp
#)

#target_include_directories(
#  chucknorris
#  PUBLIC
#    "include"
#)

add_executable(cpp_demo
  src/main.cpp
)

#target_link_libraries(cpp_demo chucknorris)
