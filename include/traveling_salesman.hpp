#ifndef TRAVELING_SALESMAN_H_
#define TRAVELING_SALESMAN_H_

#include <iostream>
#include <vector>
#include "candidate.hpp"

using namespace std;

class TravelingSalesman : public Candidate {
  private:
    std::vector<int> chromosome_;

  public:
    TravelingSalesman(size_t chromosome_size);
    TravelingSalesman(std::vector<int> chromosome);

    size_t get_chromosome_length();
    void copy_chromosome(std::vector<int>& chromosome);
    void set_gene(size_t offset, int gene);
    int get_gene(size_t offset);
    bool contains(int gene);

    void Print();
};

#endif // TRAVELING_SALESMAN_H_
