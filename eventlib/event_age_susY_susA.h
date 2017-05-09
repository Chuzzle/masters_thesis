#include "event.h"

#ifndef EVENT_AGE_SUSY_SUSA_H
#define EVENT_AGE_SUSY_SUSA_H

class Event_age_susY_susA : public Event{
public:
  explicit Event_age_susY_susA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
