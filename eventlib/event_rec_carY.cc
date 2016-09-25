#include "event_rec_carY.h"

using namespace std;

double Event_rec_carY::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CAR") * pop.get_pop("YOUNG_CARRIERS");
  return prob;
}

void Event_rec_carY::execute_event() {
  pop.move_pop("YOUNG_CARRIERS", "YOUNG_IMMUNE");
}
