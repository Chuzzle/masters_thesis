#include "event.h"

#ifndef EVENTI_TRA_IMMY_H_H
#define EVENTI_TRA_IMMY_H

class EventI_tra_immY : public Event{
public:
  explicit EventI_tra_immY(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
