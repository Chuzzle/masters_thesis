#include <map>
#include <vector>

#include "constants_runspec.h"
#include "population.h"

class Simulation {
public:
  Simulation(Population& pop, std::vector<Event>& ev);
  int simulate();
  Population get_state_at(double t);
private:
  Population& pop;
  std::map<double, Population> snaps;
  std::vector<int> event_count;
  bool done = false;
};
