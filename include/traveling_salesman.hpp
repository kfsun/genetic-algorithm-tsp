#ifndef TRAVELING_SALESMAN_H_
#define TRAVELING_SALESMAN_H_

#include <iostream>
#include <vector>
#include <memory>
#include "city_collection.hpp"
#include "candidate.hpp"
#include "route.hpp"

class TravelingSalesman : public Candidate {
  private:
    RoutePtr my_route_; 

  public:
    TravelingSalesman(std::shared_ptr<CityCollection> pcc);

    inline void set_new_route(RoutePtr pnew_route) {
      //my_route_ = pnew_route;
    }

    RoutePtr get_copy_of_route();

    void calculate_fitness() override;
    RoutePtr crossover_with(const CandidatePtr pCandidate) override;

    void print() override;
};

#endif // TRAVELING_SALESMAN_H_
