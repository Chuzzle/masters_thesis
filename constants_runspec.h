// Holds the run-specific constants. If you wish to make a run with different settings, this is what you should change.
#include <map>
#include <string>

#include "constants.h"

#ifndef CONSTANTS_RUNSPEC_H
#define CONSTANTS_RUNSPEC_H

// Time for which to run the simulation
const int NUM_DAYS = 10;

// Various booleans on some settings
const bool VACCINE = false;
const bool LOAD_CLIMATE = false;

// Population initializers
// struct POP_INIT
enum {
  INIT_infants_susc = 0,
  INIT_infants_sick = 0,
  INIT_infants_carriers = 0,
  INIT_infants_immune = 0,

  INIT_children_susc = 0,
  INIT_children_sick = 0,
  INIT_children_carriers = 0,
  INIT_children_immune = 0,

  INIT_young_susc = 0,
  INIT_young_sick = 0,
  INIT_young_carriers = 0,
  INIT_young_immune = 0,

  INIT_adult_susc = 100,
  INIT_adult_sick = 1,
  INIT_adult_carriers = 0,
  INIT_adult_immune = 0
};

// Probabilities in this run
const double PROB_TRA_SICA_SUSA = 0.001;

#endif
