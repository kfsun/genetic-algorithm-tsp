#ifndef ROUTE_H_
#define ROUTE_H_

#include <vector>

class Route {
  protected:

  private:
    std::vector<int> city_indice_;

  public:
    //Route() = default;
    Route(size_t number_of_city);
    Route(std::vector<int> city_indice);

    double distance();
};

#endif // ROUTE_H_
