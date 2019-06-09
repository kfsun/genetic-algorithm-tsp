#ifndef GENETIC_ALGORITHM_H_
#define GENETIC_ALGORITHM_H_

#include <iostream>
#include <vector>
#include <memory>
#include "candidate.hpp"

using namespace std;

class GeneticAlgo {
  private:
    double mutation_rate {0.001};
    double crossover_rate {0.9};
    int elitism_count {2};
    int tournament_size {0};

    std::vector<std::shared_ptr<Candidate>> candidates;

  public:
    inline GeneticAlgo(double mut_rate, double cross_rate, int elit_count, int tour_size) :
      mutation_rate {mut_rate}, crossover_rate {cross_rate}, elitism_count {elit_count}, tournament_size {tour_size} {}

    void add_candidate(std::shared_ptr<Candidate> pcandidate);
};

#endif // GENETIC_ALGORITHM_H_
