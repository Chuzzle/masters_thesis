#include "event.h"

#ifndef EVENT_TRA_SICI_SUSI_H
#define EVENT_TRA_SICI_SUSI_H

class Event_tra_sicI_susI : public Event{
public:
  explicit Event_tra_sicI_susI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
