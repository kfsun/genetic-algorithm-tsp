#ifndef GENETIC_ALGORITHM_H_
#define GENETIC_ALGORITHM_H_

#include <iostream>
#include <vector>
#include <memory>
#include "candidate.hpp"
#include "tournament.hpp"

class GeneticAlgo {
  private:
    double mutation_rate {0.001};
    double crossover_rate {0.9};
    int elitism_count {2};

    std::vector<std::shared_ptr<Candidate>> candidates;
    std::unique_ptr<Tournament> ptournament;

  public:
    GeneticAlgo(double mut_rate, double cross_rate, int elit_count, size_t tour_size);

    void add_candidate(std::shared_ptr<Candidate> pcandidate);

  private:
    void gen_tournament();
};

#endif // GENETIC_ALGORITHM_H_
