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
  ptournament_->print();
}

void GeneticAlgo::sort_candidate() {
	std::sort(
    candidates_.begin(),
    candidates_.end(),
			[](const std::shared_ptr<Candidate> l, const std::shared_ptr<Candidate> r) {
				return l->get_fitness() < r->get_fitness();
			});
}

void GeneticAlgo::evolve() {
  sort_candidate();
  crossover();
  mutate();
}

void GeneticAlgo::crossover() {
  if (candidates_.empty()) {
    return;
  }

  for (size_t i {1}; i < candidates_.size(); i++) {
    auto p1 = candidates_[i-1];
    auto p2 = candidates_[i];

  }
}

void GeneticAlgo::mutate() {
  if (candidates_.empty()) {
    return;
  }
}

