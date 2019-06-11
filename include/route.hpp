#ifndef ROUTE_H_
#define ROUTE_H_

#include <iostream>
#include <vector>
#include <memory>
#include "city_collection.hpp"
#include "random_generator.hpp"

class Route {
  protected:

  private:
    std::shared_ptr<CityCollection> pcc_;
    std::vector<int> city_indice_;

  public:
    //Route() = default;
    Route(std::shared_ptr<CityCollection> pcc);
    //Route(std::shared_ptr<CityCollection> pcc, std::vector<int> indice);
    //std::vector<int> gen_randam_part();
    //Route& operator+(const Route& route);
    std::shared_ptr<Route> operator+(const Route& route);

    double distance();
    void print();
};

#endif // ROUTE_H_
