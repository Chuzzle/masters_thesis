#include "event.h"

#ifndef EVENT_TRA_CARY_SUSY_H
#define EVENT_TRA_CARY_SUSY_H

class Event_tra_carY_susY : public Event{
public:
  explicit Event_tra_carY_susY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
