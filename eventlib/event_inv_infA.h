#include "event.h"

#ifndef EVENT_INV_INFA_H
#define EVENT_INV_INFA_H

class Event_inv_infA : public Event{
public:
  explicit Event_inv_infA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
