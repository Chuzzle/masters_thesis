#include "event.h"

#ifndef EVENTI_REC_SICI_H
#define EVENTI_REC_SICI_H

class EventI_rec_sicI : public Event{
public:
  explicit EventI_rec_sicI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
