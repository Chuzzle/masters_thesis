#include <vector>

#include "population.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event();
  double virtual generate_time(double t, Population& pop);
  double virtual execute_event(double t, Population& pop);
}

#endif
