#include <vector>
#include <memory>
#include "candidate_collection.hpp"
#include "candidate.hpp"

CandidateCollection::CandidateCollection(size_t num_of_candidate, size_t num_of_city) {
  for (size_t i {}; i < num_of_candidate; i++) {
    candidates_.push_back(
      std::make_shared<Candidate>(num_of_city)
    );
  }
}

