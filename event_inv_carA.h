#include "event.h"

#ifndef EVENT_INV_CARA_H
#define EVENT_INV_CARA_H

class Event_inv_carA : public Event {
public:
  explicit Event_inv_carA() {};
  virtual double update_prob(double t, Population& pop);
  virtual void execute_event(Population& pop);
};

#endif
