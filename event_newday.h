#include <cmath>

#include "event.h"

#ifndef EVENT_NEWDAY_H
#define EVENT_NEWDAY_H

class Event_newday : public Event {
public:
  double generate_time(double t, Population& pop);
  void execute_event(Population& pop);
};

#endif
