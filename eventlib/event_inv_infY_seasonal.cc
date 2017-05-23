#include "event_inv_infY_seasonal.h"

using namespace std;

double Event_inv_infY_seasonal::update_prob(double t) {
  if (constants.is_dry(t)) {
    prob = constants.get_prob("PROB_INVASION_DRY") * pop.get_pop("YOUNG_INF");
  } else {
    prob = constants.get_prob("PROB_INVASION_WET") * pop.get_pop("YOUNG_INF");
  }
  return prob;
}

void Event_inv_infY_seasonal::execute_event() {
  pop.move_pop("YOUNG_INF", "YOUNG_SICK");
}

string Event_inv_infY_seasonal::description() {
  return "Invasive disease of an infected young, seasonal parameters";
}
