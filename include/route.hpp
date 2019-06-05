#ifndef ROUTE_H_
#define ROUTE_H_

#include <vector>
#include <memory>
#include "city_collection.hpp"

class Route {
  protected:

  private:
    shared_ptr<CityCollection> pcc_;
    std::vector<int> city_indice_;

  public:
    //Route() = default;
    Route(shared_ptr<CityCollection> pcc);
    Route(shared_ptr<CityCollection> pcc, std::vector<int> city_indice);

    double distance();
    void print();
};

#endif // ROUTE_H_
