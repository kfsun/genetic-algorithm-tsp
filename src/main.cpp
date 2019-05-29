#include <iostream>
#include "random_generator.hpp"

using namespace std;

int main() {
  auto p = RandomGenerator::getInstance();

  for (int i {}; i < 1000; i++) {
  cout << "R = " << p->getDouble() << endl;
  }

  cout << "hello!!!" << endl;
  return 0;
}
