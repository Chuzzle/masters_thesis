#include "event_noninv_infY_seasonal.h"

using namespace std;

double Event_noninv_infY_seasonal::update_prob(double t) {
  if (constants.is_dry(t)) {
    prob = constants.get_prob("PROB_NON_INVASION_DRY") * pop.get_pop("YOUNG_INF");
  } else {
    prob = constants.get_prob("PROB_NON_INVASION_WET") * pop.get_pop("YOUNG_INF");
  }
  return prob;
}

void Event_noninv_infY_seasonal::execute_event() {
  pop.move_pop("YOUNG_INF", "YOUNG_CARRIERS");
}

string Event_noninv_infY_seasonal::description() {
  return "Young infected becoming carrier, seasonal parameters";
}
