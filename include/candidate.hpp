#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <iostream>
#include <vector>

using namespace std;

class Candidate {
  private:
    std::vector<int> chromosome_;
    double fitness_ {-1.0};

  public:
    Candidate() = default;
    Candidate(int init_x, int init_y);


};

#endif // CANDIDATE_H_
