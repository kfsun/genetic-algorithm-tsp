#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <iostream>
#include <vector>

class Candidate {
  protected:
    double fitness_ {-1.0};

  private:

  public:
    Candidate() = default;

    void set_fitness(double f);
    double get_fitness();
};

#endif // CANDIDATE_H_
