#include "event.h"

#ifndef EVENT_TRA_SICA1_SUSA2_H
#define EVENT_TRA_SICA1_SUSA2_H

class Event_tra_sicA1_susA2 : public Event {
public:
  explicit Event_tra_sicA1_susA2(Population& pop_init_1, Population& pop_init_2) : Event(pop_init_1), pop_2(pop_init_2) {};
  virtual double update_prob(double t);
  virtual void execute_event();
private:
  Population& pop_2;
};

#endif
