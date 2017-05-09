#include "event_rec_carI_noImm.h"

using namespace std;

double Event_rec_carI_noImm::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_CARI_NOIMM") * pop.get_pop("INFANTS_CARRIERS");
  return prob;
}

void Event_rec_carI_noImm::execute_event() {
  pop.move_pop("INFANTS_CARRIERS", "INFANTS_SUSC");
}

string Event_rec_carI_noImm::description() {
  return "Infant carrier losing carriage and becoming susceptible";
}
