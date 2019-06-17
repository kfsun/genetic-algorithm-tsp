#ifndef GENETIC_ALGORITHM_H_
#define GENETIC_ALGORITHM_H_

#include <iostream>
#include <vector>
#include <memory>
#include "random_generator.hpp"
#include "candidate.hpp"
#include "tournament.hpp"
#include "route.hpp"
#include "traveling_salesman.hpp"

class GeneticAlgo {
  private:
    double mutation_rate_ {0.001};
    double crossover_rate_ {0.9};
    int elitism_count_ {2};

    std::vector<CandidatePtr> candidates_;
    std::unique_ptr<Tournament> ptournament_;
    std::vector<RoutePtr> new_routes_;

  public:
    GeneticAlgo(double mut_rate, double cross_rate, int elit_count, size_t tour_size);
    void evolve();
    void add_candidate(CandidatePtr pcandidate);
    CandidatePtr gen_tournament();
    void print_best_candidate();

  private:
    void sort_candidate();
    void crossover();
    void mutate();
    void select_elitism();
};

#endif // GENETIC_ALGORITHM_H_
