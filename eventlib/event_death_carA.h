#include "event.h"

#ifndef EVENT_DEATH_CARA_H
#define EVENT_DEATH_CARA_H

class Event_death_carA : public Event{
public:
  explicit Event_death_carA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
