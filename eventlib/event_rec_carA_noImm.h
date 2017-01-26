#include "event.h"

#ifndef EVENT_REC_CARA_NOIMM_H
#define EVENT_REC_CARA_NOIMM_H

class Event_rec_carA_noImm : public Event{
public:
  explicit Event_rec_carA_noImm(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
