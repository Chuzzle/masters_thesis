#include "event_noninv_infI_seasonal.h"

using namespace std;

double Event_noninv_infI_seasonal::update_prob(double t) {
  if (constants.is_dry(t)) {
    prob = constants.get_prob("PROB_NON_INVASION_DRY") * pop.get_pop("INFANTS_INF");
  } else {
    prob = constants.get_prob("PROB_NON_INVASION_WET") * pop.get_pop("INFANTS_INF");
  }
  return prob;
}

void Event_noninv_infI_seasonal::execute_event() {
  pop.move_pop("INFANTS_INF", "INFANTS_CARRIERS");
}

string Event_noninv_infI_seasonal::description() {
  return "Infant infected becoming carrier, seasonal parameters";
}
