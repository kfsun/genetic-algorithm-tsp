#ifndef ROUTE_H_
#define ROUTE_H_

#include <iostream>
#include <vector>
#include <memory>
#include "city_collection.hpp"
#include "random_generator.hpp"
#include <algorithm>

class Route;

using RoutePtr = std::shared_ptr<Route>;

class Route {
  protected:

  private:
    std::shared_ptr<CityCollection> pcc_;
    std::vector<int> city_indice_;

  public:
    //Route() = default;
    ~Route();
    Route(std::shared_ptr<CityCollection> pcc);
    RoutePtr operator+(const Route& route);
    void mutate(double mutation_rate);

    double distance();
    void print();
};


#endif // ROUTE_H_
