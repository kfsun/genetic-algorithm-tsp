
#include <iostream>
#include <memory>
#include "city_collection.hpp"
#include "traveling_salesman.hpp"
#include "route.hpp"
#include "genetic_algorithm.hpp"
#include "random_generator.hpp"

int main() {
  size_t total_city = 5;
  auto pcities = std::make_shared<CityCollection>(total_city);

  GeneticAlgo ga {0.001, 0.9, 2, 5}; 

  size_t total_candidate = 10;
//  std::vector<std::shared_ptr<TravelingSalesman>> salesmen;
  for (size_t i {}; i < total_candidate; i++) {
    ga.add_candidate(std::make_shared<TravelingSalesman>(pcities));
//    salesmen.push_back(
//      std::make_shared<TravelingSalesman>(pcities)
//    );
  }

  auto gen = RandomGenerator::getInstance();
  int rx = gen->getInt();
  int range = 20;
  std::cout << "rx : " << rx << std::endl;
  int v = rx % range;
  std::cout << "range : " << range << std::endl;
  std::cout << "v : " << v << std::endl;
//  double q = x / static_cast<double>(gen->getMaxInt() + 1);
//  std::cout << gen->getMaxInt() << " : " << x << " : " << q << std::endl;
//   inline static double random(double biased_factor) {
//    double biased = (RAND_MAX + 1u) / biased_factor;
//    return static_cast<double>(rand() / biased);


//  for (auto person : salesmen) {
//    person->calculate_fitness();
//    person->print();
//  }

  return 0;
}
