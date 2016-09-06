#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "simulation.h"
#include "event_tra_sicA_susA.h"
#include "event_tra_carA_susA.h"
#include "event_rec_sicA.h"
#include "event_rec_carA.h"
#include "event_inv_carA.h"
#include "event_death_sicA.h"

#include "event_encounter.h"
#include "event_tra_carA1_susA2.h"
#include "event_tra_sicA1_susA2.h"

#include "population.h"
#include "constants_runspec.h"

using namespace std;

int main() {
  Population tmp, pop_init;
  vector<Simulation> sims;

  Constants_runspec constants;

  for (int n = 0; n != constants.get_int("NUM_RUNS"); ++n) {
    vector<Event*> events;
    Population pop(pop_init);
    Population pop2(pop_init);

    Event_tra_carA_susA ev1(pop);
    Event_inv_carA ev2(pop);
    Event_tra_sicA_susA ev3(pop);
    Event_rec_carA ev4(pop);
    Event_rec_sicA ev5(pop);
    Event_death_sicA ev6(pop);

    Event_tra_carA_susA ev7(pop2);
    Event_inv_carA ev8(pop2);
    Event_tra_sicA_susA ev9(pop2);
    Event_rec_carA ev10(pop2);
    Event_rec_sicA ev11(pop2);
    Event_death_sicA ev12(pop2);

    Event_encounter ev13(pop, pop2);
    Event_tra_carA1_susA2 ev14(pop, pop2);
    Event_tra_carA1_susA2 ev15(pop2, pop);
    Event_tra_sicA1_susA2 ev16(pop, pop2);
    Event_tra_sicA1_susA2 ev17(pop2, pop);

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
    events.push_back(&ev13);
    events.push_back(&ev14);
    events.push_back(&ev15);
    events.push_back(&ev16);
    events.push_back(&ev17);

    sims.push_back(Simulation(pop, events));
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
