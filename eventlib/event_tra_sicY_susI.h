#include "event.h"

#ifndef EVENT_TRA_SICY_SUSI_H
#define EVENT_TRA_SICY_SUSI_H

class Event_tra_sicY_susI : public Event{
public:
  explicit Event_tra_sicY_susI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
