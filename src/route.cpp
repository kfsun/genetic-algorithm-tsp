#include "route.hpp"

Route::Route(size_t number_of_city) {
  for (size_t i {} ; i < number_of_city; i++) {
    city_indice_.push_back(i);
  }
}

Route::Route(std::vector<int> city_indice) {
  city_indice_ = city_indice;
}

double Route::distance() {
  if (city_indice_.empty()) {
    return 0;
  }

      double totalDistance = 0;
//    for (int cityIndex = 0; cityIndex + 1 < this.route.length; cityIndex++) {
//      totalDistance += this.route[cityIndex].distanceFrom(this.route[cityIndex + 1]);
//    }
 //   totalDistance += this.route[this.route.length - 1].distanceFrom(this.route[0]);
 //   this.distance = totalDistance;
    return totalDistance;

}
