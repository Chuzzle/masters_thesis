#include "event.h"

#ifndef EVENT_REC_CARA_H
#define EVENT_REC_CARA_H

class Event_rec_carA : public Event {
public:
  explicit Event_rec_carA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
