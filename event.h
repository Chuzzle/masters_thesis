#include <vector>
#include <random>
#include <cmath>

#include "population.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event() {};
  virtual double generate_time(double t, Population& pop) {return 0.;};
  virtual void execute_event(Population& pop) {};
};

#endif
