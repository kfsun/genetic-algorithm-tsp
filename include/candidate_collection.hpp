#ifndef CANDIDATE_COLLECTION_H_
#define CANDIDATE_COLLECTION_H_

#include <vector>
#include <memory>
#include "candidate.hpp"

class CandidateCollection {
  private:
    std::vector<std::shared_ptr<Candidate>> candidates_;

  public:
    CandidateCollection(size_t num_of_candidate, size_t num_of_city);


};

#endif // CANDIDATE_COLLECTION_H_
