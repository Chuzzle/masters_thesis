#include "event.h"

#ifndef EVENTI_DEATH_SICA_H
#define EVENTI_DEATH_SICA_H

class EventI_death_sicA : public Event {
public:
  explicit EventI_death_sicA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
