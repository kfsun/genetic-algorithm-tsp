# genetic-algorithm-tsp

Traveling salesman problem with genetic algorithm. This is a simple program for myself to pick up C++17. Please feel free to play with it if you find it is useful for you.



Below is the commands I setup cmake for building.
```
mkdir -p build/default && export CC=/usr/bin/clang && export CXX=/usr/bin/clang++ && cd build/default  && cmake -D_CMAKE_TOOLCHAIN_PREFIX=llvm- -GNinja ../.. && cd ../.. && ln -s ./build/default/compile_commands.json  compile_commands.json
```

