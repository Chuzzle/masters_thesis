#include "event.h"

#ifndef EVENT_REC_SICY_H
#define EVENT_REC_SICY_H

class Event_rec_sicY : public Event{
public:
  explicit Event_rec_sicY(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
