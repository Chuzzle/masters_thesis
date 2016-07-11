#include "population.h"

Population::Population() : populations(NUM_POPS) {
  populations[INFANTS_SUSC] = INIT_infants_susc;
  populations[INFANTS_SICK] = INIT_infants_sick;
  populations[INFANTS_CARRIERS] = INIT_infants_carriers;
  populations[INFANTS_IMMUNE] = INIT_infants_immune;

  populations[CHILDREN_SUSC] = INIT_children_susc;
  populations[CHILDREN_SICK] = INIT_children_sick;
  populations[CHILDREN_CARRIERS] = INIT_children_carriers;
  populations[CHILDREN_IMMUNE] = INIT_children_immune;

  populations[YOUNG_SUSC] = INIT_young_susc;
  populations[YOUNG_SICK] = INIT_young_sick;
  populations[YOUNG_CARRIERS] = INIT_young_carriers;
  populations[YOUNG_IMMUNE] = INIT_young_immune;

  populations[ADULT_SUSC] = INIT_adult_susc;
  populations[ADULT_SICK] = INIT_adult_sick;
  populations[ADULT_CARRIERS] = INIT_adult_carriers;
  populations[ADULT_IMMUNE] = INIT_adult_immune;
}

int Population::get_pop (int index) {
  return populations[index];
}

int Population::increment_pop (int index) {
  return ++populations[index];
}

int Population::decrease_pop (int index) {
  if (populations[index] == 0) throw Illegal_event_exception();
  return --populations[index];
}

int Population::move_pop (int move_from, int move_to) {
  if (--populations[move_from] < 0) {
    populations[move_from] = 0;
    throw Illegal_event_exception();
  }
  return ++populations[move_to];
}
