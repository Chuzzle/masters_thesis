#include "event.h"

#ifndef EVENTI_TRA_IMMI_H
#define EVENTI_TRA_IMMI_H

class EventI_tra_immI : public Event{
public:
  explicit EventI_tra_immI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
