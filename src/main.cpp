
#include <iostream>
#include <memory>
#include "city_collection.hpp"
#include "traveling_salesman.hpp"
#include "route.hpp"
#include "genetic_algorithm.hpp"
#include "random_generator.hpp"

int main() {
  size_t total_city {10};
  auto pcities = std::make_shared<CityCollection>(total_city);

  GeneticAlgo ga {0.001, 0.9, 2, 5}; 

  size_t total_candidate = 5;
//  std::vector<std::shared_ptr<TravelingSalesman>> salesmen;
  for (size_t i {}; i < total_candidate; i++) {
    ga.add_candidate(std::make_shared<TravelingSalesman>(pcities));
//    salesmen.push_back(
//      std::make_shared<TravelingSalesman>(pcities)
//    );
  }

  //size_t maxLoop {10000};
  size_t maxLoop {1};
  size_t loopCount {};
  while (loopCount < maxLoop) {
    ga.evolve();
    loopCount++;
  }

  //ga.sort_candidate();
  //ga.gen_tournament();

//  for (auto person : salesmen) {
//    person->calculate_fitness();
//    person->print();
//  }

  return 0;
}
