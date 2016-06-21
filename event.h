#include

#ifndef EVENT_H
#define EVENT_H

class Event {
public:
  explicit Event();
  double virtual find_rate();
  void virtual execute_event();
private:
  int num_Events = 0;
  std::vector<double> timestamps;
}

#endif
