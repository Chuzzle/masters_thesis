#include "event.h"

#ifndef EVENT_REC_CARI_H
#define EVENT_REC_CARI_H

class Event_rec_carI : public Event{
public:
  explicit Event_rec_carI(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
