#include "event_rec_sicY.h"

using namespace std;

double Event_rec_sicY::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_SICA") * pop.get_pop("YOUNG_SICK");
  return prob;
}

void Event_rec_sicY::execute_event() {
  pop.move_pop("YOUNG_SICK", "YOUNG_IMMUNE");
}
