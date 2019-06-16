#ifndef CITY_COLLECTION_H_
#define CITY_COLLECTION_H_

#include <vector>
#include <memory>
#include "city.hpp"


class CityCollection {
  private:
    std::vector<std::shared_ptr<City>> cities_;

  public:
    explicit CityCollection(size_t number_of_city);
    ~CityCollection();
    inline size_t get_size() { return cities_.size(); }
    std::shared_ptr<City> get_city(size_t offset);

    void print();

};

#endif //CITY_COLLECTION_H_ 
