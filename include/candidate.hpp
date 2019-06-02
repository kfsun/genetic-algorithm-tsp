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
    Candidate();
    Candidate(std::vector<int> chromosome);

    void get_a_copy_of_chromosome(std::vector<int>& chromosome);
    size_t get_chromosome_length();
    void Print();
};

#endif // CANDIDATE_H_
