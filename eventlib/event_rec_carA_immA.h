#include "event.h"

#ifndef EVENT_REC_CARA_IMMA_H
#define EVENT_REC_CARA_IMMA_H

class Event_rec_carA_immA : public Event {
public:
  explicit Event_rec_carA_immA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
