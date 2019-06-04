
#include <iostream>
#include <memory>
#include "city_collection.hpp"
#include "candidate.hpp"

int main() {
  int total_city = 100;
  auto pcc = std::make_shared<CityCollection>(total_city);

  //pcc->Print();
  Candidate n {pcc->get_size()};
  n.Print();

  return 0;
}
