#ifndef TRAVELING_SALESMAN_H_
#define TRAVELING_SALESMAN_H_

#include <iostream>
#include <vector>
#include <memory>
#include "city_collection.hpp"
#include "candidate.hpp"
#include "route.hpp"

class TravelingSalesman : public Candidate {
  private:
    std::unique_ptr<Route> my_route_; 

  public:
    TravelingSalesman(std::shared_ptr<CityCollection> pcc);

    void calculate_fitness() override;
    void print();
//    size_t get_chromosome_length();
//    void copy_chromosome(std::vector<int>& chromosome);
//    void set_gene(size_t offset, int gene);
//    int get_gene(size_t offset);
//    bool contains(int gene);

//    void Print();
};

#endif // TRAVELING_SALESMAN_H_
