#include "event.h"

#ifndef EVENTI_TRA_SUSA_H
#define EVENTI_TRA_SUSA_H

class EventI_tra_susA : public Event{
public:
  explicit EventI_tra_susA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
