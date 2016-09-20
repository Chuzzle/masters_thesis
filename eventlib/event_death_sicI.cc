#include "event_death_sicI.h"

using namespace std;

double Event_death_sicI::update_prob(double t) {
  prob = constants.get_prob("FATALITY") * pop.get_pop("INFANTS_SICK");
  return prob;
}

void Event_death_sicI::execute_event() {
  pop.decrease_pop("INFANTS_SICK");
}
