#include "event.h"

#ifndef EVENT_INV_CARI_H
#define EVENT_INV_CARI_H

class Event_inv_carI : public Event {
public:
  explicit Event_inv_carI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
