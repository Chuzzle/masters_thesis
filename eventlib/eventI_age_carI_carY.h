#include "event.h"

#ifndef EVENTI_AGE_CARI_CARY_H
#define EVENTI_AGE_CARI_CARY_H

class EventI_age_carI_carY : public Event{
public:
  explicit EventI_age_carI_carY(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
