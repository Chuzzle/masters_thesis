#include "event.h"

#ifndef EVENT_AGE_CARI_CARY_H
#define EVENT_AGE_CARI_CARY_H

class Event_age_carI_carY : public Event{
public:
  explicit Event_age_carI_carY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
