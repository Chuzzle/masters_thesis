#include "event.h"

#ifndef EVENT_EXTERNAL_TRA_SUSA_H
#define EVENT_EXTERNAL_TRA_SUSA_H

class Event_external_tra_susA : public Event{
public:
  explicit Event_external_tra_susA(Population& pop_init, Population& pop_init_other) : Event(pop_init), pop_other(pop_init_other) {};
  virtual std::string description();
  virtual double update_prob(double t);
  virtual void execute_event();
private:
  Population& pop_other;
};

#endif
