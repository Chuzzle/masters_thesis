#include <vector>

#include "illegal_event_exception.h"
#include "pop_init.h"
#include "constants.h"

#ifndef POPULATION_H
#define POPULATION_H

class Population {
public:
  Population(Pop_init pop_init);
  int get_pop(int index);
  int move_pop(int move_from, int move_to);
  int increment_pop(int index);
  int decrease_pop(int index);
private:
  std::vector<int> populations;
};

#endif
