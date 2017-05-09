#include "event.h"

#ifndef EVENT_AGE_IMMY_IMMA_H
#define EVENT_AGE_IMMY_IMMA_H

class Event_age_immY_immA : public Event{
public:
  explicit Event_age_immY_immA(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
