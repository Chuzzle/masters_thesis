#include "event.h"

#ifndef EVENT_REC_CARY_H
#define EVENT_REC_CARY_H

class Event_rec_carY : public Event{
public:
  explicit Event_rec_carY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
