
#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

class RandomGenerator {
  private:
    static RandomGenerator* instance;
    RandomGenerator();

  public:
    static RandomGenerator* getInstance();
};

#endif // RANDOM_GENERATOR_H_
