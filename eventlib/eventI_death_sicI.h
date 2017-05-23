#include "event.h"

#ifndef EVENTI_DEATH_SICI_H
#define EVENTI_DEATH_SICI_H

class EventI_death_sicI : public Event{
public:
  explicit EventI_death_sicI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
