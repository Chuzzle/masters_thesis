#include <vector>
#include <string>

#include "illegal_event_exception.h"
#include "constants_runspec.h"

#ifndef POPULATION_H
#define POPULATION_H

class Population {
public:
  Population();

  int get_pop(std::string index);
  int move_pop(std::string move_from, std::string move_to);
  int get_pop(int index);
  int increment_pop(std::string index);
  int decrease_pop(std::string index);
private:
  Constants_runspec constants;
  std::vector<int> populations;
};

#endif
