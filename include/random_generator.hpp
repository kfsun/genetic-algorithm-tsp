
#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <memory>
#include <time.h>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>

using namespace std;

class RandomGenerator {
  private:
    static RandomGenerator* instance;
//    shared_ptr<boost::variate_generator<boost::mt19937, boost::normal_distribution<>>> pGenerator_;
    shared_ptr<boost::variate_generator<boost::mt19937, boost::uniform_real<>>> pGenerator_;

    RandomGenerator();

  public:
    static RandomGenerator* getInstance();
    double getDouble();
};

#endif // RANDOM_GENERATOR_H_
