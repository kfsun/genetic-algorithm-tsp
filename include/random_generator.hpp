
#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <memory>
#include <time.h>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/variate_generator.hpp>
#include <boost/random/uniform_real.hpp>
#include <boost/random/uniform_int.hpp>

using namespace std;

// https://www.boost.org/doc/libs/1_59_0/libs/random/example/random_demo.cpp
// https://www.boost.org/doc/libs/1_43_0/doc/html/boost_random/tutorial.html
class RandomGenerator {
  private:
    static RandomGenerator* instance;
//    shared_ptr<boost::variate_generator<boost::mt19937, boost::normal_distribution<>>> pGenerator_;
    shared_ptr<boost::variate_generator<boost::mt19937, boost::uniform_real<>>> pGenerator_;
    shared_ptr<boost::variate_generator<boost::mt19937, boost::uniform_int<>>> pIntGenerator_;

    RandomGenerator();

  public:
    static RandomGenerator* getInstance();
    double getDouble();
    double getInt();
};

#endif // RANDOM_GENERATOR_H_
