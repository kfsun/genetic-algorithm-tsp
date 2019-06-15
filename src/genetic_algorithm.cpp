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

  new_routes_.clear();

  crossover();
  mutate();

  //assign new route to salesman
  int i = 0;
  for (auto c : this->candidates_) {
    auto psalesman = std::dynamic_pointer_cast<TravelingSalesman>(c);
    if (psalesman) {
//      psalesman->set_new_route(this->new_routes_[i]);
      i++;
    }
  }

  sort_candidate();
}

void GeneticAlgo::crossover() {
  if (candidates_.empty()) {
    return;
  }

  for (size_t i {1}; i < candidates_.size(); i++) {
    new_routes_.push_back(
      candidates_[i-1]->crossover_with(candidates_[i])
    );
  }

  new_routes_.push_back(
    candidates_[candidates_.size()-1]->crossover_with(candidates_[0])
  );
}

void GeneticAlgo::mutate() {
  if (candidates_.empty()) {
    return;
  }

  for (auto r : new_routes_) {
    r->mutate(this->mutation_rate_);
  }
}

