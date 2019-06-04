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

    inline std::shared_ptr<Candidate> get_candidate(size_t offset) {return candidates_[offset]; }
    inline size_t get_size() { return candidates_.size(); }

};

#endif // CANDIDATE_COLLECTION_H_
