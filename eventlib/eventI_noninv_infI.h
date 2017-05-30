#include "event.h"

#ifndef EVENTI_NONINV_INFI_H
#define EVENTI_NONINV_INFI_H

class EventI_noninv_infI : public Event{
public:
  explicit EventI_noninv_infI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
