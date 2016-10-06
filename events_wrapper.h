#include <vector>
#include <fstream>
#include <algorithm>

#include "/usr/include/jsoncpp/json/json.h"

#include "population.h"
#include "eventlib/eventheaders.h"
#include "constants_runspec.h"

#ifndef EVENTS_WRAPPER_H
#define EVENTS_WRAPPER_H

class Events_wrapper {
public:
  Events_wrapper();
  std::vector<Event*> initialize_events(std::vector<Population>& pops);
  ~Events_wrapper() {delete_events();};
private:
  void delete_events();
  Events_wrapper(const Events_wrapper&) = delete;
  Events_wrapper& operator=(const Events_wrapper&) = delete;
  Json::Value events;
  std::vector<Event*> event_list;
  Constants_runspec constants;
};

#endif
