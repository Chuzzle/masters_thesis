#include "event_death_sicY.h"

using namespace std;

double Event_death_sicY::update_prob(double t) {
  prob = constants.get_prob("FATALITY") * pop.get_pop("YOUNG_SICK");
  return prob;
}

void Event_death_sicY::execute_event() {
  pop.decrease_pop("YOUNG_SICK");
}
