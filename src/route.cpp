#include <iostream>
#include "route.hpp"

Route::Route(shared_ptr<CityCollection> pcc) {
  pcc_ = pcc;
  for (size_t i {} ; i < pcc_->get_size(); i++) {
    city_indice_.push_back(i);
  }
}

Route::Route(shared_ptr<CityCollection> pcc, std::vector<int> city_indice) {
  pcc_ = pcc;
  city_indice_ = city_indice;
}

double Route::distance() {
  if (city_indice_.empty()) {
    return 0;
  }

  double total_distance = 0;
  for (size_t i {}; i + 1 < city_indice_.size(); i++) {
    auto c1 = pcc_->get_city(city_indice_[i]);
    auto c2 = pcc_->get_city(city_indice_[i+1]);
    total_distance += c1->distance_from(*c2);
  }

  auto c1 = pcc_->get_city(city_indice_.size() - 1);
  auto c2 = pcc_->get_city(city_indice_[0]);
  total_distance += c1->distance_from(*c2);

  return total_distance;
}

void Route::print() {
  for (size_t i {}; i < city_indice_.size(); i++) {
    std::cout << city_indice_[i] << " ; " << std::endl;
  }
}
