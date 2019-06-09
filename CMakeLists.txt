#project(pear)
#add_executable(${PROJECT_NAME} "main.cpp")

# export CC=/usr/bin/clang && export CXX=/usr/bin/clang++ && cd build/default  && cmake -D_CMAKE_TOOLCHAIN_PREFIX=llvm- -GNinja ../..
# ln -s ./build/default/compile_commands.json  compile_commands.json

cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(cheeseburger)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(CMAKE_VERBOSE_MAKEFILE ON)


add_library(cheeseburgerlib
  include/random_generator.hpp
  src/random_generator.cpp
  include/city.hpp
  src/city.cpp
  include/city_collection.hpp
  src/city_collection.cpp
  include/route.hpp
  src/route.cpp
  include/traveling_salesman.hpp
  src/traveling_salesman.cpp
  include/candidate.hpp
  src/candidate.cpp
  include/genetic_algorithm.hpp
  src/genetic_algorithm.cpp
  #include/candidate_collection.hpp
  #src/candidate_collection.cpp
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
