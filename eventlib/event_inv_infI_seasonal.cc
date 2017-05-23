#include "event_inv_infI_seasonal.h"

using namespace std;

double Event_inv_infI_seasonal::update_prob(double t) {
  if (constants.is_dry(t)) {
    prob = constants.get_prob("PROB_INVASION_DRY") * pop.get_pop("INFANTS_INF");
  } else {
    prob = constants.get_prob("PROB_INVASION_WET") * pop.get_pop("INFANTS_INF");
  }
  return prob;
}

void Event_inv_infI_seasonal::execute_event() {
  pop.move_pop("INFANTS_INF", "INFANTS_SICK");
}

string Event_inv_infI_seasonal::description() {
  return "Invasive disease of an infected infant, seasonal parameters";
}
