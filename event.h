#include <vector>
#include <random>
#include <cmath>

#include "population.h"
#include "constants_runspec.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event() {};
  virtual double update_prob(double t, Population& pop) {return 0.;};
  virtual void execute_event(Population& pop) {};
  double prob;
  Constants_runspec constants;
};

#endif
