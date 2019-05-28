#include "random_generator.hpp"
#include <memory>
#include <time.h>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>

using namespace std;

RandomGenerator* RandomGenerator::getInstance() {
  if (RandomGenerator::instance == 0) {
      RandomGenerator::instance = new RandomGenerator();
  }

  return RandomGenerator::instance;
}

RandomGenerator::RandomGenerator() {
/*  pGenerator_ = 
    std::make_shared<
      boost::variate_generator<boost::mt19937, boost::normal_distribution<>>
      >( boost::mt19937(time(0)), boost::normal_distribution<>() )
  ;*/
}

double RandomGenerator::getDouble() {
  //return pGenerator_->distribution();
  return 0.2;
}
