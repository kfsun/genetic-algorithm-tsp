
#include <iostream>
#include <memory>
#include "city_collection.hpp"
#include "traveling_salesman.hpp"
#include "route.hpp"

int main() {
  size_t total_city = 5;
  auto pcities = std::make_shared<CityCollection>(total_city);

  size_t total_candidate = 10;
  std::vector<std::shared_ptr<TravelingSalesman>> salesmen;
  for (size_t i {}; i < total_candidate; i++) {
    auto proute = std::make_shared<Route>(pcities);
    salesmen.push_back(std::make_shared<TravelingSalesman>(*proute));
  }
  
  for (auto person : salesmen) {
    person->calculate_fitness();
    person->print();
  }

  //pcc->print();
  //Candidate n {pcc->get_size()};
  //n.Print();
  //Route r {pcc};

  //TravelingSalesman a {r};
  //a.calculate_fitness();
  //a.print();

  //r.print();
  return 0;
}
