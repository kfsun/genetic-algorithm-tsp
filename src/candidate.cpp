#include "candidate.hpp"

using namespace std;

Candidate::Candidate(std::vector<int> chromosome) {
  chromosome_ = chromosome;
}

Candidate::Candidate() {
  int length = 10;
  for (int i {} ; i < length; i++) {
    chromosome_.push_back(i+1);
  }
}
