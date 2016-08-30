#include "event.h"

#ifndef EVENT_DEATH_SICA_H
#define EVENT_DEATH_SICA_H

class Event_death_sicA : public Event {
public:
  explicit Event_death_sicA() {};
  virtual double update_prob(double t, Population& pop);
  virtual void execute_event(Population& pop);
}

#endif
