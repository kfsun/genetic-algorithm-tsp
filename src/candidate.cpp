#include "candidate.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Candidate::Candidate(std::vector<int> chromosome) {
  chromosome_ = chromosome;
}

Candidate::Candidate(size_t chromosome_size) {
  for (size_t i {} ; i < chromosome_size; i++) {
    chromosome_.push_back(i);
  }
}

void Candidate::set_fitness(double f) {
  fitness_ = f;
}

double Candidate::get_fitness() {
  return fitness_;
}

size_t Candidate::get_chromosome_length() {
  return chromosome_.size();
}

void Candidate::copy_chromosome(std::vector<int>& chromosome) {
  chromosome = chromosome_;
}

void Candidate::set_gene(size_t offset, int gene) {
  chromosome_[offset] = gene;
}

int Candidate::get_gene(size_t offset) {
  return chromosome_[offset];
}

bool Candidate::contains(int gene) {
  std::vector<int>::iterator it = std::find(chromosome_.begin(), chromosome_.end(), gene);
  return (it != chromosome_.end());
}

void Candidate::Print() {
  if (chromosome_.size() == 0) {
    std::cout << "zero size chromosome" << std::endl;
    return;
  }

  for (auto item : chromosome_) {
    std::cout << item << " -> ";
  }
  std::cout << std::endl;
}
