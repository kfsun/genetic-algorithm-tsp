#project(pear)
#add_executable(${PROJECT_NAME} "main.cpp")

# export CC=/usr/bin/clang && export CXX=/usr/bin/clang++ && cd build/default  && cmake -D_CMAKE_TOOLCHAIN_PREFIX=llvm- -GNinja ../..
# ln -s ./build/default/compile_commands.json  compile_commands.json

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cheeseburger)

add_library(cheeseburgerlib
  include/random_generator.hpp
  src/random_generator.cpp
  include/city.hpp
  src/city.cpp
)

target_include_directories(
  cheeseburgerlib
  PUBLIC
    "include"
)

add_executable(cpp_demo
  src/main.cpp
)

target_link_libraries(cpp_demo cheeseburgerlib)
