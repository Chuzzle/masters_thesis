#include "event_newday.h"

double Event_newday::generate_time(double t, Population& pop) {
  return ceil(t)-t;
}

void Event_newday::execute_event(Population& pop) {
  return;
}
