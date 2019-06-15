#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <iostream>
#include <vector>
#include <memory>
#include "route.hpp"

class Candidate;

using CandidatePtr = std::shared_ptr<Candidate>;

class Candidate {
  protected:
    double fitness_ {-1.0};

  private:

  public:
    Candidate() = default;
    virtual ~Candidate() = default;

    virtual void calculate_fitness() = 0;
    void set_fitness(double f);
    double get_fitness();

    virtual RoutePtr crossover_with(const CandidatePtr pCandidate) = 0;

    virtual void print() = 0;
};

#endif // CANDIDATE_H_
