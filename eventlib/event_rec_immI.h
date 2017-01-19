#include "event.h"

#ifndef EVENT_REC_IMMI_H
#define EVENT_REC_IMMI_H

class Event_rec_immI : public Event{
public:
  explicit Event_rec_immI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
