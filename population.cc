#include "population.h"

Population::Population(Pop_init pop_init) : populations(NUM_POPS) {
  populations[INFANTS_SUSC] = pop_init.num_infants_susc;
  populations[INFANTS_SICK] = pop_init.num_infants_sick;
  populations[INFANTS_CARRIERS] = pop_init.num_infants_carriers;
  populations[INFANTS_IMMUNE] = pop_init.num_infants_immune;

  populations[CHILDREN_SUSC] = pop_init.num_children_susc;
  populations[CHILDREN_SICK] = pop_init.num_children_sick;
  populations[CHILDREN_CARRIERS] = pop_init.num_children_carriers;
  populations[CHILDREN_IMMUNE] = pop_init.num_children_immune;

  populations[YOUNG_SUSC] = pop_init.num_young_susc;
  populations[YOUNG_SICK] = pop_init.num_young_sick;
  populations[YOUNG_CARRIERS] = pop_init.num_young_carriers;
  populations[YOUNG_IMMUNE] = pop_init.num_young_immune;

  populations[ADULT_SUSC] = pop_init.num_adult_susc;
  populations[ADULT_SICK] = pop_init.num_adult_sick;
  populations[ADULT_CARRIERS] = pop_init.num_adult_carriers;
  populations[ADULT_IMMUNE] = pop_init.num_adult_immune;
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
