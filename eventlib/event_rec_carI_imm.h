#include "event.h"

#ifndef EVENT_REC_CARI_IMM_H
#define EVENT_REC_CARI_IMM_H

class Event_rec_carI_imm : public Event{
public:
  explicit Event_rec_carI_imm(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
