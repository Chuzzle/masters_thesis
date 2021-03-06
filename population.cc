#include "population.h"

using namespace std;

Population::Population() : constants(), populations(constants.get_int("NUM_POPS")) {
  populations[constants.get_int("INFANTS_SUSC")] = constants.get_int("INIT_infants_susc");
  populations[constants.get_int("INFANTS_INF")] = constants.get_int("INIT_infants_inf");
  populations[constants.get_int("INFANTS_SICK")] = constants.get_int("INIT_infants_sick");
  populations[constants.get_int("INFANTS_CARRIERS")] = constants.get_int("INIT_infants_carriers");
  populations[constants.get_int("INFANTS_IMMUNE")] = constants.get_int("INIT_infants_immune");
  populations[constants.get_int("INFANTS_IMMUNE_PER")] = constants.get_int("INIT_infants_immune_per");

  populations[constants.get_int("YOUNG_SUSC")] = constants.get_int("INIT_young_susc");
  populations[constants.get_int("YOUNG_INF")] = constants.get_int("INIT_young_inf");
  populations[constants.get_int("YOUNG_SICK")] = constants.get_int("INIT_young_sick");
  populations[constants.get_int("YOUNG_CARRIERS")] = constants.get_int("INIT_young_carriers");
  populations[constants.get_int("YOUNG_IMMUNE")] = constants.get_int("INIT_young_immune");
  populations[constants.get_int("YOUNG_IMMUNE_PER")] = constants.get_int("INIT_young_immune_per");

  populations[constants.get_int("ADULT_SUSC")] = constants.get_int("INIT_adult_susc");
  populations[constants.get_int("ADULT_INF")] = constants.get_int("INIT_adult_inf");
  populations[constants.get_int("ADULT_SICK")] = constants.get_int("INIT_adult_sick");
  populations[constants.get_int("ADULT_CARRIERS")] = constants.get_int("INIT_adult_carriers");
  populations[constants.get_int("ADULT_IMMUNE")] = constants.get_int("INIT_adult_immune");
  populations[constants.get_int("ADULT_IMMUNE_PER")] = constants.get_int("INIT_adult_immune_per");
}

int Population::get_pop (string index) {
  int ind = constants.get_int(index);
  return populations[ind];
}

int Population::get_pop (int index) {
  return populations[index];
}

int Population::get_total_pop() {
  int sum = 0;
  for_each(populations.begin(), populations.end(), [&] (int n) {sum += n;});
  return sum;
}

int Population::increment_pop (string index) {
  int ind = constants.get_int(index);
  return ++populations[ind];
}

int Population::decrease_pop (string index) {
  int ind = constants.get_int(index);
  if (populations[ind] == 0) throw Illegal_event_exception();
  return --populations[ind];
}

int Population::get_infected() {
  int returnval = this->get_pop("INFANTS_SICK") + this->get_pop("YOUNG_SICK") + this->get_pop("ADULT_SICK");
  return returnval;
}

int Population::get_carriers() {
  int returnval = this->get_pop("INFANTS_CARRIERS") + this->get_pop("INFANTS_INF");
  returnval += this->get_pop("YOUNG_CARRIERS") + this->get_pop("YOUNG_INF");
  returnval += this->get_pop("ADULT_CARRIERS") + this->get_pop("ADULT_INF");
  return returnval;
}

int Population::get_infected_invasive() {
  int returnval = this->get_pop("INFANTS_SICK_INVASIVE") + this->get_pop("YOUNG_SICK_INVASIVE") + this->get_pop("ADULT_SICK_INVASIVE");
  return returnval;
}


int Population::get_carriers_invasive() {
  int returnval = this->get_pop("INFANTS_CARRIERS_INVASIVE") + this->get_pop("INFANTS_INF_INVASIVE");
  returnval += this->get_pop("YOUNG_CARRIERS_INVASIVE") + this->get_pop("YOUNG_INF_INVASIVE");
  returnval += this->get_pop("ADULT_CARRIERS_INVASIVE") + this->get_pop("ADULT_INF_INVASIVE");
  return returnval;
}

int Population::move_pop (string move_from, string move_to) {
  int mv_from = constants.get_int(move_from);
  int mv_to = constants.get_int(move_to);
  if (--populations[mv_from] < 0) {
    populations[mv_from] = 0;
    throw Illegal_event_exception();
  }
  return ++populations[mv_to];
}
