#include "event.h"

#ifndef EVENT_INV_INFY_H
#define EVENT_INV_INFY_H

class Event_inv_infY : public Event{
public:
  explicit Event_inv_infY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
