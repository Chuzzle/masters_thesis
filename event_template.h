#include "event.h"

#ifndef EVENTNAME_H
#define EVENTNAME_H

class EVENTNAME : public Event{
public:
  explicit EVENTNAME(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
