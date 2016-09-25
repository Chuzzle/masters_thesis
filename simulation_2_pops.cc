#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "simulation.h"
#include "eventlib/eventheaders.h"

#include "population.h"
#include "constants_runspec.h"

using namespace std;

int main() {
  Population pop_init;
  vector<Simulation> sims;

  Constants_runspec constants;

  for (int n = 0; n != constants.get_int("NUM_RUNS"); ++n) {
    vector<Event*> events;
    vector<Population> pops;
    pops.push_back(Population());
    pops.push_back(Population());

    Event_tra_carA_susA ev1(pops[0]);
    Event_inv_carA ev2(pops[0]);
    Event_tra_sicA_susA ev3(pops[0]);
    Event_rec_carA ev4(pops[0]);
    Event_rec_sicA ev5(pops[0]);
    Event_death_sicA ev6(pops[0]);
    Event_tra_carA_susA ev7(pops[1]);
    Event_inv_carA ev8(pops[1]);
    Event_tra_sicA_susA ev9(pops[1]);
    Event_rec_carA ev10(pops[1]);
    Event_rec_sicA ev11(pops[1]);
    Event_death_sicA ev12(pops[1]);

    events.push_back(&ev1);
    events.push_back(&ev2);
    events.push_back(&ev3);
    events.push_back(&ev4);
    events.push_back(&ev5);
    events.push_back(&ev6);
    events.push_back(&ev7);
    events.push_back(&ev8);
    events.push_back(&ev9);
    events.push_back(&ev10);
    events.push_back(&ev11);
    events.push_back(&ev12);

    Event_encounter ev13(pops[0], pops[1]);
    Event_tra_carA1_susA2 ev14(pops[0], pops[1]);
    Event_tra_carA1_susA2 ev15(pops[1], pops[0]);
    Event_tra_sicA1_susA2 ev16(pops[0], pops[1]);
    Event_tra_sicA1_susA2 ev17(pops[1], pops[0]);

    events.push_back(&ev13);
    events.push_back(&ev14);
    events.push_back(&ev15);
    events.push_back(&ev16);
    events.push_back(&ev17);

    sims.push_back(Simulation(pops, events));
    cout << "New simulation initialized." << endl;
    sims[n].simulate();
    cout << "Simulation done." << endl;
  }

  //Write results to a file in the data directory
  ofstream res_file;
  res_file.open("data/simulation_2_pops.txt");
  if(!res_file.is_open()) {
      cerr << "Could not open results file. If the folder 'data' does not exist, try creating it in this directory." << endl;
      return 1;
  }
  res_file << constants.get_int("NUMBER_OF_POPS") << " ";
  res_file << constants.get_int("NUM_DAYS") << endl;

  vector<Population> tmp;

  for (auto it = sims.begin(); it != sims.end(); ++it) {
    for (int n = 0; n != constants.get_int("NUM_DAYS"); ++n) {
      res_file << n << " ";
      tmp = it->get_state_at(static_cast<double>(n));
      for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        for (int k = 0; k!= constants.get_int("NUM_POPS"); ++k) {
          res_file << it->get_pop(k) << " ";
        }
      }
      res_file << "\n";
    }
  }
  res_file.close();
  cout << "File output sucessful." << endl;
}
