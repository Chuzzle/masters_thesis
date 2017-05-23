#include "event.h"

#ifndef EVENTI_REC_SICA_H
#define EVENTI_REC_SICA_H

class EventI_rec_sicA : public Event {
public:
  explicit EventI_rec_sicA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};


#endif
