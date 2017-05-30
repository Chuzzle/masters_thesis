#include "event.h"

#ifndef EVENTI_TRA_SUSI_H
#define EVENTI_TRA_SUSI_H

class EventI_tra_susI : public Event{
public:
  explicit EventI_tra_susI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
