#include "event.h"

#ifndef EVENT_NONINV_INFI_H
#define EVENT_NONINV_INFI_H

class Event_noninv_infI : public Event{
public:
  explicit Event_noninv_infI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
