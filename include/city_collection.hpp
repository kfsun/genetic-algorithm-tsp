#ifndef CITY_COLLECTION_H_
#define CITY_COLLECTION_H_

#include <vector>
#include <memory>
#include "city.hpp"


class CityCollection {
  private:
    //size_t  number_of_city_ {};
    std::vector<std::shared_ptr<City>> cities_;

  public:
    CityCollection(size_t number_of_city);
    inline size_t get_size() { return cities_.size(); }

    void Print();

};

#endif //CITY_COLLECTION_H_ 
