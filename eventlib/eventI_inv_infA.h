#include "event.h"

#ifndef EVENTI_INV_INFA_H
#define EVENTI_INV_INFA_H

class EventI_inv_infA : public Event{
public:
  explicit EventI_inv_infA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
