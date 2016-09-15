#include "event.h"

#ifndef EVENT_AGE_IMMI_IMMY_H
#define EVENT_AGE_IMMI_IMMY_H

class Event_age_immI_immY : public Event{
public:
  explicit Event_age_immI_immY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
