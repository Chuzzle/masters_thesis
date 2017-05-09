#include "event.h"

#ifndef EVENT_AGE_SUSI_SUS_H
#define EVENT_AGE_SUSI_SUS_H

class Event_age_susI_susY : public Event {
public:
  explicit Event_age_susI_susY(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
