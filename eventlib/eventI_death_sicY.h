#include "event.h"

#ifndef EVENTI_DEATH_SICY_H
#define EVENTI_DEATH_SICY_H

class EventI_death_sicY : public Event{
public:
  explicit EventI_death_sicY(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
