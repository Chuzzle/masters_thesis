#include <vector>
#include <random>
#include <cmath>

#include "population.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event() {};
  virtual double update_prob(double t, Population& pop) {prob = 0.; return prob;};
  virtual void execute_event(Population& pop) {};
  double prob;
};

#endif
