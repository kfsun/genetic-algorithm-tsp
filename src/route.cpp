#include "route.hpp"

Route::Route(std::shared_ptr<CityCollection> pcc) {
  pcc_ = pcc;
  for (size_t i {} ; i < pcc_->get_size(); i++) {
    city_indice_.push_back(i);
  }
}

std::shared_ptr<Route> Route::operator+(const Route& route) {
//  D* pd2 = new D(*pd1); //pd1 points to D object
//  Route copy{*this};
//  return copy;

  auto copy_self {std::make_shared<Route>(*this)};
  // init new route to -1
  copy_self->city_indice_.assign(copy_self->city_indice_.size(), -1);
  //copy_self->pcc_->print();

  auto gen = RandomGenerator::getInstance();
  int cut1 = gen->getInt() % city_indice_.size();
  int cut2 = gen->getInt() % city_indice_.size();
//  pd1->print();
//  auto pd2 {std::make_shared<Route>(*pd1)};
//  pd2->print();
//    double best_fitness {};
  while (cut1 == cut2) {
    cut2 = gen->getInt() % city_indice_.size();
//    int y = gen->getInt() % candidates.size();
//    candidates_[y] = candidates[y];
//    double current_fitness = candidates_[y]->get_fitness();
//    if (current_fitness > best_fitness) {
//      best_fitness = current_fitness;
//    }
  }

  if (cut1 > cut2) {
    cut1 ^= cut2;
    cut2 ^= cut1;
    cut1 ^= cut2;
  }
  std::cout << "cut1 : " << cut1 <<std::endl;
  std::cout << "cut2 : " << cut2 <<std::endl;

  // copy to new route from first parent
  std::copy(this->city_indice_.begin()+cut1, this->city_indice_.begin()+cut2+1, copy_self->city_indice_.begin()+cut1);

  // copy to new route from second parent
  auto find_ptr = std::find(copy_self->city_indice_.rbegin(), copy_self->city_indice_.rend(), -1);
  while (find_ptr != copy_self->city_indice_.rend()) {
    *find_ptr = 999;
    find_ptr = std::find(copy_self->city_indice_.rbegin(), copy_self->city_indice_.rend(), -1);
  }

  /*for (size_t i {}; i < city_indice_.size(); i++) {
    if (i >= cut1 && i <= cut2) {
      continue;
    }
    std::cout << "on " << i << std::endl;

    for (int j {static_cast<int>(city_indice_.size()) - 1}; j > -1; j--) {
      std::cout << route.city_indice_[j] ;
    }
    std::cout << std::endl;
  }*/

  return copy_self;
}

//Route::Route(std::shared_ptr<CityCollection> pcc, std::vector<int> city_indice) {
//  pcc_ = pcc;
//  city_indice_ = city_indice;
//}

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
    std::cout << city_indice_[i] << " ; ";
  }
  std::cout << std::endl;
}
