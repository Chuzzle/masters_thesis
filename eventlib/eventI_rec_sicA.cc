#include "eventI_rec_sicA.h"

using namespace std;

double EventI_rec_sicA::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_SIC") * pop.get_pop("ADULT_SICK_INVASIVE");
  return prob;
}

void EventI_rec_sicA::execute_event() {
  pop.move_pop("ADULT_SICK_INVASIVE", "ADULT_IMMUNE");
}

string EventI_rec_sicA::description() {
  return "Sick adult of the invasive strain recovering and gaining immunity";
}
