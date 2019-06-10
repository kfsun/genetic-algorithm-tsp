#include "candidate.hpp"

//Candidate::Candidate() {
//}

void Candidate::set_fitness(double f) {
  fitness_ = f;
}

double Candidate::get_fitness() {
  calculate_fitness();
  return fitness_;
}

