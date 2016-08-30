#include "event.h"

#ifndef EVENT_REC_SICA_H
#define EVENT_REC_SICA_H

class Event_rec_sicA : public Event {
public:
  explicit Event_rec_sicA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};


#endif
