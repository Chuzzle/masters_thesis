#include "event_encounter.h"

using namespace std;

// double Event_encounter::update_prob(double t) {
//   if (!is_active) {
//     prob = constants.is_dry(t)*constants.get_prob("PROB_ENCOUNTER");
//   } else {
//     prob = (!constants.is_dry(t))*constants.get_prob("PROB_DISENGAGE")
//   }
//   return prob;
// }

double Event_encounter::update_prob(double t) {
  if (!constants.is_encountered() && constants.is_dry(t)) this->execute_event();
  else if (!constants.is_dry(t) && constants.is_encountered()) this->execute_event();
  return prob = 0;
}

void Event_encounter::execute_event() {
  constants.encounter_active = !constants.encounter_active;
}
