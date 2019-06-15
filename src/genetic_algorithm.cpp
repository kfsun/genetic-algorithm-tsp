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

std::shared_ptr<Candidate> GeneticAlgo::gen_tournament() {
  if (candidates_.empty()) {
    return nullptr;
  }

  return ptournament_->new_turn(candidates_);
}

void GeneticAlgo::sort_candidate() {
	std::sort(
    candidates_.begin(),
    candidates_.end(),
			[](const std::shared_ptr<Candidate> l, const std::shared_ptr<Candidate> r) {
				return l->get_fitness() < r->get_fitness();
			});
}

void GeneticAlgo::print_best_candidate() {
  sort_candidate();
  candidates_[0]->print();
}

void GeneticAlgo::select_elitism() {
  sort_candidate();

  for (size_t i {}; i < elitism_count_; i++) {
    auto psalesman = std::dynamic_pointer_cast<TravelingSalesman>(candidates_[i]);
    if (psalesman) {
      new_routes_.push_back(
        psalesman->get_copy_of_route()
      );
    }
  }
}

void GeneticAlgo::evolve() {
  // new routes will be stored in the vector
  // and assign to salesman later on.
  new_routes_.clear();

  sort_candidate();

  select_elitism();
  crossover();
  mutate();

  //assign new route to salesman
  int i = 0;
  for (auto c : this->candidates_) {
    auto psalesman = std::dynamic_pointer_cast<TravelingSalesman>(c);
    if (psalesman) {
      psalesman->set_new_route(this->new_routes_[i]);
      i++;
    }
  }
}

void GeneticAlgo::crossover() {
  if (candidates_.empty()) {
    return;
  }

  for (int i {elitism_count_}; i < candidates_.size(); i++) {
    auto pnew_route = candidates_[i]->crossover_with(this->gen_tournament());
    if (pnew_route != nullptr) {
      new_routes_.push_back(pnew_route);
    } else {
      std::cout << "crossover got a nullptr" << std::endl;
    }
  }
}

void GeneticAlgo::mutate() {
  if (new_routes_.empty()) {
    return;
  }

  for (auto r : new_routes_) {
    r->mutate(this->mutation_rate_);
  }
}

