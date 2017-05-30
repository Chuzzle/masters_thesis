#include "eventI_rec_sicI.h"

using namespace std;

double EventI_rec_sicI::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_SIC") * pop.get_pop("INFANTS_SICK_INVASIVE");
  return prob;
}

void EventI_rec_sicI::execute_event() {
  pop.move_pop("INFANTS_SICK_INVASIVE", "INFANTS_IMMUNE_PER");
}

string EventI_rec_sicI::description() {
  return "Sick infant of the invasive strain recovering an gaining permanent immunity";
}
