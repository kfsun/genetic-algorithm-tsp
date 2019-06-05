
#include <iostream>
#include <memory>
#include "city_collection.hpp"
//#include "candidate.hpp"
#include "route.hpp"

int main() {
  int total_city = 5;
  auto pcc = std::make_shared<CityCollection>(total_city);

  pcc->Print();
  //Candidate n {pcc->get_size()};
  //n.Print();
  Route r {pcc};

  r.print();
  std::cout << "route distance = " << r.distance() << std::endl;
  return 0;
}
