
#include <iostream>
#include "city_collection.hpp"
#include <memory>

int main() {
  auto pcc = std::make_shared<CityCollection>(100);

  pcc->Print();
  return 0;
}
