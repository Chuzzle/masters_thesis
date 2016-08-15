#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "utf8.h"
#include "simulation.h"
#include "event_tra_sicA_susA.h"
#include "event_tra_carA_susA.h"
#include "event_rec_sicA.h"
#include "event_rec_carA.h"
#include "event_inv_carA.h"
#include "population.h"
#include "constants.h"
#include "constants_runspec.h"

using namespace std;

int main() {
  Population pop, tmp;
  vector<Simulation> sims;
  vector<Event*> events;
  Event_tra_carA_susA ev1;
  Event_inv_carA ev2;
  Event_tra_sicA_susA ev3;
  Event_rec_carA ev4;
  Event_rec_sicA ev5;
  Constants_runspec constants;

  events.push_back(&ev1);
  events.push_back(&ev2);
  events.push_back(&ev3);
  events.push_back(&ev4);
  events.push_back(&ev5);

  for (int n = 0; n != constants.get_int("NUM_RUNS"); ++n) {
    sims.push_back(Simulation(pop, events));
    cout << "New simulation initialized." << endl;
    sims[n].simulate();
    cout << "Simulation done." << endl;
  }

  //Write results to a file in the data directory
  ofstream res_file;
  res_file.open("data/simulation_run_first.txt");
  if(!res_file.is_open()) {
      cerr << "Could not open results file." << endl;
      return 1;
  }
  for (auto it = sims.begin(); it != sims.end(); ++it) {
    for (int n = 0; n != constants.get_int("NUM_DAYS"); ++n) {
      tmp = it->get_state_at(static_cast<double>(n));
      res_file << n << " ";
      for (int k = 0; k!= constants.get_int("NUM_POPS"); ++k) {
        res_file << tmp.get_pop(k) << " ";
      }
      res_file << "\n";
    }
  }
  res_file.close();
  cout << "File output sucessful." << endl;
}
