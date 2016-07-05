#include <cmath>

#include "event.h"

class Event_newday : Event {
  double generate_time(double t, Population& pop) {
    return ceil(t)-t;
  }

  void execute_event(double t, Population& pop) {
    return;
  }
};
