#include "event.h"

#ifndef EVENT_REC_CARY_IMM_H
#define EVENT_REC_CARY_IMM_H

class Event_rec_carY_imm : public Event{
public:
  explicit Event_rec_carY_imm(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
