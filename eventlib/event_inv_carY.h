#include "event.h"

#ifndef EVENT_INV_CARY_H
#define EVENT_INV_CARY_H

class Event_inv_carY : public Event {
public:
  explicit Event_inv_carY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
