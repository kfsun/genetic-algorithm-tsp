#include "traveling_salesman.hpp"
#include <iostream>
#include <algorithm>

TravelingSalesman::TravelingSalesman(std::shared_ptr<CityCollection> pcc) : my_route_{std::make_unique<Route>(pcc)} {
}

void TravelingSalesman::calculate_fitness() {
  set_fitness(1 / my_route_->distance());
}

void TravelingSalesman::print() {
  std::cout << "TravelingSalesman route: ";
  my_route_->print();
  std::cout << "  distance: " << my_route_->distance() << std::endl;
  std::cout << "  fitness: " << this->fitness_ << std::endl;
}

std::shared_ptr<Route> TravelingSalesman::crossover_with(const std::shared_ptr<Candidate> pCandidate) {
  auto psalesman = std::dynamic_pointer_cast<TravelingSalesman>(pCandidate);
  if (psalesman) {
//        std::cout << "Downcasted pointer says: ";
//        downcastedPtr->f();
  }
  return nullptr;
}

std::shared_ptr<Route> TravelingSalesman::mutate_with(const std::shared_ptr<Candidate> pCandidate) {
  return nullptr;
}

/*
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
*/
