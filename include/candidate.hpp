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
    virtual ~Candidate() = default;

    virtual void calculate_fitness() = 0;
    void set_fitness(double f);
    double get_fitness();

    virtual void print() = 0;
};

#endif // CANDIDATE_H_
