#include "event.h"

#ifndef EVENT_INV_INFI_H
#define EVENT_INV_INFI_H

class Event_inv_infI : public Event{
public:
  explicit Event_inv_infI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
