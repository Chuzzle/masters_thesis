#include "event.h"

#ifndef EVENTI_REC_CARA_IMMPERA_H
#define EVENTI_REC_CARA_IMMPERA_H

class EventI_rec_carA_immPerA : public Event{
public:
  explicit EventI_rec_carA_immPerA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
