#include <iostream>
#include "random_generator.hpp"
//  #include <time.h>
//  #include <boost/random/normal_distribution.hpp>
//  #include <boost/random/mersenne_twister.hpp>
//  #include <boost/random/variate_generator.hpp>

using namespace std;

int main() {

//    boost::variate_generator<boost::mt19937, boost::normal_distribution<> >
//      generator(boost::mt19937(time(0)),
//                boost::normal_distribution<>());
  
//    double r = generator();
  auto p = RandomGenerator::getInstance();
  cout << "R = " << p->getDouble() << endl;
  //  cout << "R = " << r << endl;

  cout << "hello!!!" << endl;
  return 0;
}
