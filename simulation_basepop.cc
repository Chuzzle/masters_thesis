#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "simulation.h"
#include "population.h"
#include "eventlib/eventheaders.h"
#include "constants_runspec.h"

using namespace std;

int main() {
  //Population pop_init;
  Constants_runspec constants;

  ofstream res_file;
  res_file.open("data/simulation_basepop.txt");
  if(!res_file.is_open()) {
    cerr << "Coul not open the results file. If the folder 'data' does not exist, try creating it" << endl;
    return 1;
  }

  res_file << constants.get_int("NUMBER_OF_POPS") << " " << constants.get_int("NUM_DAYS") << endl;


  for (int k = 0; k != constants.get_int("NUM_RUNS"); ++k) {
    vector<Event*> events;
    vector<Population> pops;

    for (int nn = 0; nn != constants.get_int("NUMBER_OF_POPS"); ++nn) pops.push_back(Population());

    Event_birth ev1(pops[0]);
    Event_age_susI_susY ev2(pops[0]);
    Event_age_susY_susA ev3(pops[0]);
    Event_death_susA ev4(pops[0]);

    events.push_back(&ev1);
    events.push_back(&ev2);
    events.push_back(&ev3);
    events.push_back(&ev4);

    Simulation sim(pops, events);
    cout << "New simulation initialized" << endl;
    sim.simulate();
    cout << "Simulation done" << endl;

    for (int n = 0; n != constants.get_int("NUM_DAYS"); ++n) {
      res_file << n << " ";
      vector<Population> tmp = sim.get_state_at(static_cast<double>(n));
      for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
        for (int k = 0; k!= constants.get_int("NUM_POPS"); ++k) {
          res_file << iter->get_pop(k) << " ";
        }
      }
      res_file << "\n";
    }
    cout << "Results output successful" << endl;
  }
  res_file.close();
}
