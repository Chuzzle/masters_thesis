#include "event.h"

#ifndef "EVENT_TRA_CARA_SUSA_H"
#define "EVENT_TRA_CARA_SUSA_H"

class Event_tra_carA_susA : public Event {
public:
  explicit Event_tra_carA_susA() {};
  virtual double update_prob(double t, Population& pop);
  virtual void execute_event(Population& pop);
}

#endif
