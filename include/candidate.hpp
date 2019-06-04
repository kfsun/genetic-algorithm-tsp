#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <iostream>
#include <vector>

using namespace std;

class Candidate {
  private:
    std::vector<int> chromosome_;
    double fitness_ {-1.0};

  public:
    Candidate(size_t chromosome_size);
    Candidate(std::vector<int> chromosome);

    void set_fitness(double f);
    double get_fitness();

    size_t get_chromosome_length();
    void copy_chromosome(std::vector<int>& chromosome);
    void set_gene(size_t offset, int gene);
    int get_gene(size_t offset);
    bool contains(int gene);

    void Print();
};

#endif // CANDIDATE_H_
