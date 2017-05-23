#include "event.h"

#ifndef EVENTI_TRA_SUSY_H
#define EVENTI_TRA_SUSY_H

class EventI_tra_susY : public Event{
public:
  explicit EventI_tra_susY(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
