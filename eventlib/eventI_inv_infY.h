#include "event.h"

#ifndef EVENTI_INV_INFY_H
#define EVENTI_INV_INFY_H

class EventI_inv_infY : public Event{
public:
  explicit EventI_inv_infY(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
