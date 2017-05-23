#include "event.h"

#ifndef EVENTI_AGE_CARY_CARA_H
#define EVENTI_AGE_CARY_CARA_H

class EventI_age_carY_carA : public Event{
public:
  explicit EventI_age_carY_carA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
