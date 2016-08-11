#include "event.h"

#ifndef "EVENT_REC_SICA_H"
#define "EVENT_REC_SICA_H"

class Event_rec_sicA : public Event {
public:
  explicit Event_rec_sicA() {};
  virtual double update_prob(double t, Population& pop);
  virtual void execute_event(Population& pop);
};


#endif
