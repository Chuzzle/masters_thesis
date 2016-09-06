#include "event.h"

#ifndef EVENT_ENCOUNTER_H
#define EVENT_ENCOUNTER_H

class Event_encounter : public Event {
public:
  explicit Event_encounter(Population& pop_init, Population& pop_init_2) : Event(pop_init), second_pop(pop_init_2) {};
  virtual double update_prob(double t);
  virtual void execute_event();
  Population& second_pop;
};

#endif
