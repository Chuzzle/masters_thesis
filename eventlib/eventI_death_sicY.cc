#include "eventI_death_sicY.h"

using namespace std;

double EventI_death_sicY::update_prob(double t) {
  prob = constants.get_prob("FATALITY") * pop.get_pop("YOUNG_SICK_INVASIVE");
  return prob;
}

void EventI_death_sicY::execute_event() {
  pop.decrease_pop("YOUNG_SICK_INVASIVE");
}

string EventI_death_sicY::description() {
  return "Death of a sick young of the invasive strain";
}
