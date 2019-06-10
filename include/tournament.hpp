#ifndef TOURNAMENT_H_
#define TOURNAMENT_H_

#include <iostream>
#include <vector>
#include <memory>
#include "candidate.hpp"

class Tournament {
  private:
    size_t size_;
    std::vector<std::shared_ptr<Candidate>> candidates;

  public:
    explicit Tournament(size_t size);

    void new_turn();
    //void add_candidate(std::shared_ptr<Candidate> pcandidate);
};

#endif // TOURNAMENT_H_
