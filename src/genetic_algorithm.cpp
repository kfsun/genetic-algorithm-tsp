#include "genetic_algorithm.hpp"

void GeneticAlgo::add_candidate(std::shared_ptr<Candidate> pcandidate) {
  candidates.push_back(pcandidate);
}

