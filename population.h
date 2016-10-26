#include <vector>
#include <string>
#include <algorithm>

#include "illegal_event_exception.h"
#include "constants_runspec.h"

#ifndef POPULATION_H
#define POPULATION_H

class Population {
public:
  explicit Population();
  Population(std::vector<int> initializer) : populations(initializer) {};

  int get_pop(std::string index);
  int get_pop(int index);
  int get_total_pop();
  int get_infectuous();

  int move_pop(std::string move_from, std::string move_to);
  int increment_pop(std::string index);
  int decrease_pop(std::string index);
private:
  Constants_runspec constants;
  std::vector<int> populations;
};

#endif
