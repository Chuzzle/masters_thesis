#include "event.h"

#ifndef EVENT_DEATH_SICA_H
#define EVENT_DEATH_SICA_H

class Event_death_sicA : public Event {
public:
  explicit Event_death_sicA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
