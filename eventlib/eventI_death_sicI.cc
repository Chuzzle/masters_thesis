#include "eventI_death_sicI.h"

using namespace std;

double EventI_death_sicI::update_prob(double t) {
  prob = constants.get_prob("FATALITY") * pop.get_pop("INFANTS_SICK_INVASIVE");
  return prob;
}

void EventI_death_sicI::execute_event() {
  pop.decrease_pop("INFANTS_SICK_INVASIVE");
}

string EventI_death_sicI::description() {
  return "Death of a sick infant of the invasive strain";
}
