#include "event.h"

#ifndef EVENT_TRA_CARI_SUSA_H_H
#define EVENT_TRA_CARI_SUSA_H

class Event_tra_carI_susA : public Event{
public:
  explicit Event_tra_carI_susA(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
