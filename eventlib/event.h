#include <vector>
#include <random>
#include <cmath>

#include "../population.h"
#include "../constants_runspec.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event(Population& pop_init) : pop(pop_init) {};
  virtual std::string description() {return "";};
  virtual double update_prob(double t) {return 0.;};
  virtual void execute_event() {};
  virtual ~Event() {};
  double prob;
  Constants_runspec constants;
  Population& pop;
};

#endif
