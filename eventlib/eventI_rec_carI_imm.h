#include "event.h"

#ifndef EVENTI_REC_CARI_IMM_H
#define EVENTI_REC_CARI_IMM_H

class EventI_rec_carI_imm : public Event{
public:
  explicit EventI_rec_carI_imm(Population& pop_init) : Event(pop_init) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
};

#endif
