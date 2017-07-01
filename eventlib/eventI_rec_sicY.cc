#include "eventI_rec_sicY.h"

using namespace std;

double EventI_rec_sicY::update_prob(double t) {
  prob = constants.get_prob("PROB_REC_SIC") * pop.get_pop("YOUNG_SICK_INVASIVE");
  return prob;
}

void EventI_rec_sicY::execute_event() {
  pop.move_pop("YOUNG_SICK_INVASIVE", "YOUNG_IMMUNE");
}

string EventI_rec_sicY::description() {
  return "Sick young of the invasive strain recovering and gaining immunity";
}
