#include <map>
#include <string>
#include <fstream>
#include <iostream>

#include "/usr/include/jsoncpp/json/json.h"

#ifndef CONSTANTS_RUNSPEC_H
#define CONSTANTS_RUNSPEC_H

class Constants_runspec {
public:
  Constants_runspec();
  double get_prob(std::string key);
  int get_int(std::string key);
  int is_dry(double t);
  bool is_encountered() {return encounter_active;};
  friend class Event_encounter;
private:
  Json::Value constants;
  bool encounter_active = false;
};

#endif
