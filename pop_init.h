#ifndef POP_INIT_H
#define POP_INIT_H

struct Pop_init {
  int num_infants_susc = 100;
  int num_infants_sick = 0;
  int num_infants_carriers = 0;
  int num_infants_immune = 0;

  int num_children_susc = 0;
  int num_children_sick = 0;
  int num_children_carriers = 0;
  int num_children_immune = 0;

  int num_young_susc = 50;
  int num_young_sick = 0;
  int num_young_carriers = 0;
  int num_young_immune = 0;

  int num_adult_susc = 100;
  int num_adult_sick = 0;
  int num_adult_carriers = 0;
  int num_adult_immune = 0;
};

#endif
