#include "event.h"

#ifndef EVENT_DEATH_SUSA_H
#define EVENT_DEATH_SUSRA_H

class Event_death_susA : public Event{
public:
  explicit Event_death_susA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
