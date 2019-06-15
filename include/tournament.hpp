#ifndef TOURNAMENT_H_
#define TOURNAMENT_H_

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "candidate.hpp"
#include "random_generator.hpp"

class Tournament {
  private:
    size_t size_;
    std::map<size_t, CandidatePtr> candidates_;

  public:
    explicit Tournament(size_t size);

    CandidatePtr new_turn(const std::vector<CandidatePtr>& candidates);
    void print();
};

#endif // TOURNAMENT_H_
