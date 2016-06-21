#include <vector>

#include "Population.h"

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event();
  double virtual find_rate(double t, Population& pop);
  void virtual execute_event(double t, Population& pop);
private:
  int num_Events = 0;
  std::vector<double> timestamps;
}

#endif
