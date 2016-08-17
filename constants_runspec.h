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
private:
  Json::Value constants;
};

#endif
