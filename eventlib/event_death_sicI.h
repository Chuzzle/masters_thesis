#include "event.h"

#ifndef EVENT_DEATH_SICI_H
#define EVENT_DEATH_SICI_H

class Event_death_sicI : public Event{
public:
  explicit Event_death_sicI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
