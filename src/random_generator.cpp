#include "random_generator.hpp"
#include <memory>
#include <time.h>
#include <cmath>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/uniform_int.hpp>

using namespace std;

RandomGenerator* RandomGenerator::instance = 0;

RandomGenerator* RandomGenerator::getInstance() {
  if (instance == 0) {
      instance = new RandomGenerator();
  }

  return instance;
}

RandomGenerator::RandomGenerator() {
  //pGenerator_ = std::make_shared<
  //  boost::variate_generator<boost::mt19937, boost::normal_distribution<>>
  //  >( boost::mt19937(time(0)), boost::normal_distribution<>() )
  //;

  pGenerator_ = std::make_shared<
    boost::variate_generator<boost::mt19937, boost::uniform_real<>>
    >( boost::mt19937(time(0)), boost::uniform_real<>(0,1) )
  ;

  pIntGenerator_ = std::make_shared<
    boost::variate_generator<boost::mt19937, boost::uniform_int<>>
    >( boost::mt19937(time(0)), boost::uniform_int<>(0, 999999) )
  ;
}

double RandomGenerator::getInt() {
  return (*pIntGenerator_)();
}

double RandomGenerator::getDouble() {
  return (*pGenerator_)();
}
