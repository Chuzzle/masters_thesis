#include "event.h"

#ifndef EVENT_DEATH_IMMA_H
#define EVENT_DEATH_IMMA_H

class Event_death_immA : public Event{
public:
  explicit Event_death_immA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
