#include "event.h"

#ifndef EVENT_REC_CARA_IMM_H
#define EVENT_REC_CARA_IMM_H

class Event_rec_carA_imm : public Event {
public:
  explicit Event_rec_carA_imm(Population& pop_init) : Event(pop_init) {};
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
