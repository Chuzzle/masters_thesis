#include "event.h"

#ifndef EVENT_TRA_IMMI_H
#define EVENT_TRA_IMMI_H

class Event_tra_immI : public Event{
public:
  explicit Event_tra_immI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
