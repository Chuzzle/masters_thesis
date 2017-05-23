#include "event.h"

#ifndef EVENTI_DEATH_CARA_H
#define EVENTI_DEATH_CARA_H

class EventI_death_carA : public Event{
public:
  explicit EventI_death_carA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
