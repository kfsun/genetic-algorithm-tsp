#include "genetic_algorithm.hpp"

GeneticAlgo::GeneticAlgo(double mut_rate, double cross_rate, int elit_count, size_t tour_size) :
  mutation_rate_ {mut_rate},
  crossover_rate_ {cross_rate},
  elitism_count_ {elit_count},
  ptournament_ {std::make_unique<Tournament>(tour_size)} {
}

void GeneticAlgo::add_candidate(std::shared_ptr<Candidate> pcandidate) {
  candidates_.push_back(pcandidate);
}

void GeneticAlgo::gen_tournament() {
  if (candidates_.empty()) {
    return;
  }

  ptournament_->new_turn(candidates_);
}
