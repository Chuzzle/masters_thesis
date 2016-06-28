#include <vector>

#include "Population.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event();
  double virtual find_rate(double t, Population& pop);
  double virtual generate_time(double t, Population& pop);
}

#endif
