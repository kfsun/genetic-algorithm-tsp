#ifndef CITY_H_
#define CITY_H_

#include <iostream>

using namespace std;

class City {
  private:
    int x {}, y {};

  public:
    City() = default;
    City(int init_x, int init_y);
};

#endif // RANDOM_GENERATOR_H_
