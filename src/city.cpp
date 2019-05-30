#include "city.hpp"
#include <cmath>

using namespace std;

City::City(int init_x, int init_y) {
  x = init_x;
  y = init_y;
}

double City::DistanceFrom(City& city) {
  double deltaXSq = pow((city.getX() - getX()), 2);
  double deltaYSq = pow((city.getY() - getY()), 2);

  return sqrt(abs(deltaXSq + deltaYSq));
}
