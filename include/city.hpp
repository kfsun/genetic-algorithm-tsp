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

    inline int getX() {
      return x;
    }

    inline int getY() {
      return y;
    }

    double distance_from(City& city);
};

#endif // RANDOM_GENERATOR_H_
