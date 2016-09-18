#include "event.h"

#ifndef EVENT_INV_CARA_H
#define EVENT_INV_CARA_H

class Event_inv_carA : public Event {
public:
  explicit Event_inv_carA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
