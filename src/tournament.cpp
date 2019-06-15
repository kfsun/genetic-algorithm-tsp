#include "tournament.hpp"

Tournament::Tournament(size_t size) {
  size_ = size;
}

CandidatePtr Tournament::new_turn(const std::vector<CandidatePtr>& candidates) {
  candidates_.clear();

  auto gen = RandomGenerator::getInstance();

  double best_fitness {};
  size_t key {};
  while (candidates_.size() < size_) {
    int y = gen->getInt() % candidates.size();
    candidates_[y] = candidates[y];

    double current_fitness = candidates_[y]->get_fitness();
    if (current_fitness > best_fitness) {
      best_fitness = current_fitness;
      key = y;
    }
  }

  return candidates_[key];
}

void Tournament::print() {
  for (auto const& [key, val] : candidates_) {
    std::cout << "key = " << key << std::endl;
    val->print();
  }
}

