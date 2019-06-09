#ifndef TRAVELING_SALESMAN_H_
#define TRAVELING_SALESMAN_H_

#include <iostream>
#include <vector>
#include "candidate.hpp"
#include "route.hpp"

class TravelingSalesman : public Candidate {
  private:
    Route& my_route_; 
//    std::vector<size_t> city_indice_;

  public:
//    explicit TravelingSalesman(size_t number_of_city);
//    explicit TravelingSalesman(std::vector<size_t>& indice);
    TravelingSalesman(Route& r);

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
