#include "tournament.hpp"

Tournament::Tournament(size_t size) {
  size_ = size;
}

void Tournament::new_turn(const std::vector<std::shared_ptr<Candidate>>& candidates) {
  candidates_.clear();

  auto gen = RandomGenerator::getInstance();

  while (candidates_.size() < size_) {
    int y = gen->getInt() % candidates.size();
    std::cout << "y :" << y << std::endl;
    candidates_[y] = candidates[y];
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

