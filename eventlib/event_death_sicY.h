#include "event.h"

#ifndef EVENT_DEATH_SICY_H
#define EVENT_DEATH_SICY_H

class Event_death_sicY : public Event{
public:
  explicit Event_death_sicY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
