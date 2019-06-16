#include <vector>
#include <memory>
#include "city_collection.hpp"
#include "city.hpp"
#include "random_generator.hpp"


CityCollection::CityCollection(size_t number_of_city) {
  auto gen = RandomGenerator::getInstance();
  for (size_t i {}; i < number_of_city; i++) {
    cities_.push_back(
      std::make_shared<City>(gen->getInt(), gen->getInt())
    );
  }
}

CityCollection::~CityCollection() {
  std::cout << "deleting city collection object" << std::endl;
}

std::shared_ptr<City> CityCollection::get_city(size_t offset) {
  return cities_[offset];
}

void CityCollection::print() {
  for (auto c : cities_) {
    std::cout << "c { " << c->getX() << " , " << c->getY() << " }" << std::endl;
  }
}

