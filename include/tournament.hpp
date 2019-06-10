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
    std::map<size_t, std::shared_ptr<Candidate>> candidates_;

  public:
    explicit Tournament(size_t size);

    void new_turn(const std::vector<std::shared_ptr<Candidate>>& candidates);
    //void add_candidate(std::shared_ptr<Candidate> pcandidate);
    void print();
};

#endif // TOURNAMENT_H_
