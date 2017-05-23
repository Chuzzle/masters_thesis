#include "event.h"

#ifndef EVENT_NONINV_INFY_SEASONAL_H
#define EVENT_NONINV_INFY_SEASONAL_H

class Event_noninv_infY_seasonal : public Event{
public:
  explicit Event_noninv_infY_seasonal(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
