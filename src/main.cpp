
#include <iostream>
#include <memory>
#include <cmath>
#include "city_collection.hpp"
#include "traveling_salesman.hpp"
#include "genetic_algorithm.hpp"
#include "city_collection.hpp"
#include <stdlib.h>

//void operator delete(void * p) {
//  if (p && typeid(p) == typeid(CityCollection)) {
     //TypeWeCanHandle* myData = static_cast<TypeWeCanHandle*>(data);
//     std::cout << "Delete CityCollection" << std::endl; 
//  }
//  free(p); 
//} 
  
int main() {
  size_t total_city {30};
  auto pcities = std::make_shared<CityCollection>(total_city);

  size_t total_candidate = 100;

//double mut_rate, double cross_rate, int elit_count, size_t tour_size)
  GeneticAlgo ga {0.01, 0.9, static_cast<int>(total_candidate / 10), 10}; 

  for (size_t i {}; i < total_candidate; i++) {
    ga.add_candidate(std::make_shared<TravelingSalesman>(pcities));
  }

  size_t maxLoop {1000};
  size_t loopCount {};
  while (loopCount < maxLoop) {
    ga.evolve();
    std::cout << loopCount << ") ";
    ga.print_best_candidate();
    loopCount++;
  }

  pcities->print();

  return 0;
}
