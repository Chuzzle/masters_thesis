#ifndef CONSTANTS_H
#define CONSTANTS_H

enum {  //Indices of all populations included in the model
  INFANTS_SUSC = 1,
  INFANTS_SICK = 2,
  INFANTS_CARRIERS = 3,
  INFANTS_IMMUNE = 4,
  INFANTS_VACC = 5,

  CHILDREN_SUSC = 6,
  CHILDREN_SICK = 7,
  CHILDREN_CARRIERS = 8,
  CHILDREN_IMMUNE = 9,
  CHILDREN_VACC = 10,

  YOUNG_SUSC = 11,
  YOUNG_SICK = 12,
  YOUNG_CARRIERS = 13,
  YOUNG_IMMUNE = 14,
  YOUNG_VACC = 15,

  ADULT_SUSC = 16,
  ADULT_SICK = 17,
  ADULT_CARRIERS = 18,
  ADULT_IMMUNE = 19,
  ADULT_VACC = 20,

  NUM_POPS = 21,

  NUM_DAYS = 365 //Number of days for which the simulation will be run
};

const bool VACCINE = false;
const bool LOAD_CLIMATE = false;

#endif
