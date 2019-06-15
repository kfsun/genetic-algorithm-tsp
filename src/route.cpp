#include "route.hpp"

Route::Route(std::shared_ptr<CityCollection> pcc) {
  pcc_ = pcc;
  for (size_t i {} ; i < pcc_->get_size(); i++) {
    city_indice_.push_back(i);
  }
}

void Route::mutate(double mutation_rate) {
  auto gen = RandomGenerator::getInstance();

  for (size_t i {}; i < city_indice_.size(); i++) {
    auto zz = gen->getDouble();
    if (mutation_rate > zz) {
      int new_pos = gen->getInt() % city_indice_.size();
      city_indice_[new_pos] ^= city_indice_[i];
      city_indice_[i] ^= city_indice_[new_pos];
      city_indice_[new_pos] ^= city_indice_[i];
    }
  }
}

RoutePtr Route::operator+(const Route& route) {
  auto copy_self {std::make_shared<Route>(*this)};

  // init new route to -1
  copy_self->city_indice_.assign(copy_self->city_indice_.size(), -1);
  //copy_self->pcc_->print();

  auto gen = RandomGenerator::getInstance();
  int cut1 = gen->getInt() % city_indice_.size();
  int cut2 = gen->getInt() % city_indice_.size();

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
//  std::cout << "cut1 : " << cut1 << " - cut2 : " << cut2 << std::endl;

  // copy to new route from first parent
  std::copy(this->city_indice_.begin()+cut1, this->city_indice_.begin()+cut2+1, copy_self->city_indice_.begin()+cut1);

  // copy to new route from second parent
  auto find_ptr = std::find(copy_self->city_indice_.rbegin(), copy_self->city_indice_.rend(), -1);
  while (find_ptr != copy_self->city_indice_.rend()) {
    for (size_t i {}; i < route.city_indice_.size(); i++) {
        auto a_ptr = std::find(copy_self->city_indice_.begin(), copy_self->city_indice_.end(), route.city_indice_[i]);
        if (a_ptr == copy_self->city_indice_.end()) {
          *find_ptr = route.city_indice_[i];
          break;
        } else {
          continue;
        }
    }
    find_ptr = std::find(copy_self->city_indice_.rbegin(), copy_self->city_indice_.rend(), -1);
  }

  return copy_self;
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
    std::cout << city_indice_[i] << " ; ";
  }
  std::cout << std::endl;
}
