#include "event.h"

#ifndef EVENT_BIRTH_H
#define EVENT_BIRTH_H

class Event_birth : public Event{
public:
  explicit Event_birth(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
