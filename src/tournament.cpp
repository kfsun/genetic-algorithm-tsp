#include "tournament.hpp"

Tournament::Tournament(size_t size) {
  size_ = size;
}

void Tournament::new_turn(const std::vector<std::shared_ptr<Candidate>>& candidates) {
  candidates_.clear();

  auto gen = RandomGenerator::getInstance();

  double best_fitness {};
  while (candidates_.size() < size_) {
    int y = gen->getInt() % candidates.size();
    candidates_[y] = candidates[y];
    double current_fitness = candidates_[y]->get_fitness();
    if (current_fitness > best_fitness) {
      best_fitness = current_fitness;
    }
  }
}

void Tournament::print() {
  for (auto const& [key, val] : candidates_) {
    std::cout << "key = " << key << std::endl;
    val->print();
  }
}

/*
void Tournament::add_candidate(std::shared_ptr<Candidate> pcandidate) {
  if (candidates_.size() < size_) {
    candidates_.push_back(pcandidate);
  }
}
*/

