#include "event.h"

#ifndef EVENT_REC_CARA_IMMPERA_H
#define EVENT_REC_CARA_IMMPERA_H

class Event_rec_carA_immPerA : public Event{
public:
  explicit Event_rec_carA_immPerA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
