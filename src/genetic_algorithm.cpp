#include "genetic_algorithm.hpp"

GeneticAlgo::GeneticAlgo(double mut_rate, double cross_rate, int elit_count, size_t tour_size) :
  mutation_rate {mut_rate},
  crossover_rate {cross_rate},
  elitism_count {elit_count},
  ptournament {std::make_unique<Tournament>(tour_size)} {
}

void GeneticAlgo::add_candidate(std::shared_ptr<Candidate> pcandidate) {
  candidates.push_back(pcandidate);
}

void GeneticAlgo::gen_tournament() {
  if (candidates.empty()) {
    return;
  }

}
