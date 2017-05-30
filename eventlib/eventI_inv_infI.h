#include "event.h"

#ifndef EVENTI_INV_INFI_H
#define EVENTI_INV_INFI_H

class EventI_inv_infI : public Event{
public:
  explicit EventI_inv_infI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
