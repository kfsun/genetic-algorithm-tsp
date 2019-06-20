#include "traveling_salesman.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

TravelingSalesman::TravelingSalesman(std::shared_ptr<CityCollection> pcc) : my_route_{std::make_shared<Route>(pcc)} {
}

void TravelingSalesman::calculate_fitness() {
  set_fitness(1 / my_route_->distance());
}

void TravelingSalesman::print() {
  std::cout << "TravelingSalesman route: ";
  my_route_->print();
  std::cout << "  distance: " << std::fixed << my_route_->distance() << std::endl;
  std::cout << "  fitness: " << std::fixed << std::setprecision(40) << fitness_ << std::endl;
}

RoutePtr TravelingSalesman::get_copy_of_route() {
  return std::make_shared<Route>(*(my_route_));
}

RoutePtr TravelingSalesman::crossover_with(const CandidatePtr pCandidate) {
  if (pCandidate == nullptr) {
    std::cout << "nullptr received in crossover_with" << std::endl;
    return nullptr;
  }

  auto p_another_salesman = std::dynamic_pointer_cast<TravelingSalesman>(pCandidate);
  if (p_another_salesman) {
    auto new_route = *my_route_ + *(p_another_salesman->my_route_);
    return new_route;
  }
  return nullptr;
}

