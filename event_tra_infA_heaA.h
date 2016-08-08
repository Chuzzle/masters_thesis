#include "event.h"

#ifndef EVENT_TRA_INFA_HEAA_H
#define EVENT_TRA_INFA_HEAA_H

class Event_tra_infA_heaA : public Event {
public:
  explicit Event_tra_infA_heaA() {};
  virtual double generate_time(double t, Population& pop);
  virtual void execute_event(Population& pop);
private:
  std::default_random_engine generator;
  std::uniform_real_distribution<double> dist(0.0, 1.0);
};

#endif
