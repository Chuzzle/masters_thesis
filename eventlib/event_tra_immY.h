#include "event.h"

#ifndef EVENT_TRA_IMMY_H_H
#define EVENT_TRA_IMMY_H

class Event_tra_immY : public Event{
public:
  explicit Event_tra_immY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
