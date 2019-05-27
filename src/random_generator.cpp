#include "random_generator.hpp"

RandomGenerator* RandomGenerator::getInstance() {
  if (instance == 0) {
    instance = new RandomGenerator();
  }

  return instance;
}

RandomGenerator::RandomGenerator() {
}
