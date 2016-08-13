#include "event.h"

#ifndef EVENT_REC_CARA_H
#define EVENT_REC_CARA_H

class Event_rec_carA : public Event {
public:
  explicit Event_rec_carA() {};
  virtual double update_prob(double t, Population& pop);
  virtual void execute_event(Population& pop);
}

#endif
