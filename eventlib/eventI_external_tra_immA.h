#include "event.h"

#ifndef EVENTI_EXTERNAL_TRA_IMMA_H
#define EVENTI_EXTERNAL_TRA_IMMA_H

class EventI_external_tra_immA : public Event{
public:
  explicit EventI_external_tra_immA(Population& pop_init, Population& pop_init_other) : Event(pop_init), pop_other(pop_init_other) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
private:
  Population& pop_other;
};

#endif
