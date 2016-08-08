#include <cmath>

#include "event.h"

#ifndef EVENT_NEWDAY_H
#define EVENT_NEWDAY_H

class Event_newday : public Event {
public:
  explicit Event_newday() {};
  virtual double generate_time(double t, Population& pop);
  virtual void execute_event(Population& pop);
};

#endif
