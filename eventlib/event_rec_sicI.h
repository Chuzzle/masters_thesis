#include "event.h"

#ifndef EVENT_REC_SICI_H_H
#define EVENT_REC_SICI_H

class Event_rec_sicI : public Event{
public:
  explicit Event_rec_sicI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
