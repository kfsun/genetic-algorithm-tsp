#ifndef CANDIDATE_H_
#define CANDIDATE_H_

#include <iostream>

using namespace std;

class Candidate {
  private:
    int x {}, y {};

  public:
    Candidate() = default;
    Candidate(int init_x, int init_y);

    inline int getX() {
      return x;
    }

    inline int getY() {
      return y;
    }

};

#endif // CANDIDATE_H_
