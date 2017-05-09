#include "event.h"

#ifndef EVENT_REC_CARY_NOIMM_H
#define EVENT_REC_CARY_NOIMM_H

class Event_rec_carY_noImm : public Event{
public:
  explicit Event_rec_carY_noImm(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
