#include "event.h"

#ifndef EVENT_TRA_CARY_SUSA_H
#define EVENT_TRA_CARY_SUSA_H

class Event_tra_carY_susA : public Event{
public:
  explicit Event_tra_carY_susA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
