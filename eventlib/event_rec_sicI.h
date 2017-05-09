#include "event.h"

#ifndef EVENT_REC_SICI_H
#define EVENT_REC_SICI_H

class Event_rec_sicI : public Event{
public:
  explicit Event_rec_sicI(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
