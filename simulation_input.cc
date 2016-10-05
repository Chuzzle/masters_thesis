#include <istream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

#include "simulation.h"
#include "population.h"
#include "eventlib/eventheaders.h"
#include "constants_runspec.h"

using namespace std;

int main() {
  Constants_runspec constants;

  ofstream res_file;
  res_file.open("data/simulation_input.txt");
  if(!res_file.is_open())  {
    cerr << "Could not open the results file. If the folder 'data' does not exist, try creating it" << endl;
    return 1;
  }
  res_file << constants.get_int("NUMBER_OF_POPS") << " ";
  res_file << constants.get_int("NUM_DAYS") << endl;

  // Read the results from a previous simulation -> should probably just find the last line
  vector<int> initial_pops(constants.get_int("NUMBER_OF_POPS") * constants.get_int("NUM_POPS"));

  ifstream inp_file;
  inp_file.open("data/simulation_agedist_bigpop.txt");
  if(!inp_file.is_open()) {
    cerr << "Error opening the input file." << endl;
    return 1;
  }

  inp_file.seekg(-2, ios_base::end);
  char ch;
  inp_file.get(ch);
  while (ch != '\n') {
    inp_file.seekg(-2, ios_base::cur);
    inp_file.get(ch);
  }

  int k;
  inp_file >> k;
  for (int n = 0; n != constants.get_int("NUMBER_OF_POPS") * constants.get_int("NUM_POPS"); ++n) {
    inp_file >> k;
    initial_pops[n] = k;
  }

  inp_file.close();

  for (int n = 0; n != constants.get_int("NUM_RUNS"); ++n) {
    vector<Event*> events;
    vector<Population> pops;
    for (int nn = 0; nn!= constants.get_int("NUMBER_OF_POPS"); ++nn) pops.push_back(Population(initial_pops));

    Event_age_carI_carY ev1(pops[0]);
    Event_age_carY_carA ev2(pops[0]);
    Event_age_immI_immY ev3(pops[0]);
    Event_age_immY_immA ev4(pops[0]);
    Event_age_susI_susY ev5(pops[0]);
    Event_age_susY_susA ev6(pops[0]);
    
    Event_birth ev7(pops[0]);
    Event_death_carA ev8(pops[0]);
    Event_death_susA ev9(pops[0]);
    Event_death_immA ev10(pops[0]);
    Event_death_sicA ev11(pops[0]);
    Event_death_sicI ev12(pops[0]);
    Event_death_sicY ev13(pops[0]);

    Event_tra_susA ev14(pops[0]);
    Event_tra_susI ev15(pops[0]);
    Event_tra_susY ev16(pops[0]);
    Event_inv_infA ev17(pops[0]);
    Event_inv_infY ev18(pops[0]);
    Event_inv_infI ev19(pops[0]);
    Event_noninv_infA ev20(pops[0]);
    Event_noninv_infI ev21(pops[0]);
    Event_noninv_infY ev22(pops[0]);
    Event_rec_carA ev23(pops[0]);
    Event_rec_carY ev24(pops[0]);
    Event_rec_carI ev25(pops[0]);
    Event_rec_sicA ev26(pops[0]);
    Event_rec_sicY ev27(pops[0]);
    Event_rec_sicI ev28(pops[0]);

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
    events.push_back(&ev18);
    events.push_back(&ev19);
    events.push_back(&ev20);
    events.push_back(&ev21);
    events.push_back(&ev22);
    events.push_back(&ev23);
    events.push_back(&ev24);
    events.push_back(&ev25);
    events.push_back(&ev26);
    events.push_back(&ev27);
    events.push_back(&ev28);

    Simulation sim(pops, events);
    cout << "New simulation initialized." << endl;
    sim.simulate();
    cout << "Simulation done." << endl;

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
  //   Event_age_susI_susY ev5(pops[0]);
  //   Event_age_susY_susA ev6(pops[0]);
  //
  res_file.close();
}
