#include "event.h"

#ifndef EVENT_AGE_CARY_CARA_H
#define EVENT_AGE_CARY_CARA_H

class Event_age_carY_carA : public Event{
public:
  explicit Event_age_carY_carA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
