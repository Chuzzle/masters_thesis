#include "event_inv_infA_seasonal.h"

using namespace std;

double Event_inv_infA_seasonal::update_prob(double t) {
  if (constants.is_dry(t)) {
    prob = constants.get_prob("PROB_INVASION_DRY") * pop.get_pop("ADULT_INF");
  } else {
    prob = constants.get_prob("PROB_INVASION_WET") * pop.get_pop("ADULT_INF");
  }
  return prob;
}

void Event_inv_infA_seasonal::execute_event() {
  pop.move_pop("ADULT_INF", "ADULT_SICK");
}

string Event_inv_infA_seasonal::description() {
  return "Invasive disease on an infected adult, seasonal parameters";
}
