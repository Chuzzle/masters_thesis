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
  string output_file_name = constants.get_string("OUTPUT_FILE");
  res_file.open("data/" + output_file_name + ".txt");
  if(!res_file.is_open())  {
    cerr << "Could not open the results file. If the folder 'data' does not exist, try creating it" << endl;
    return 1;
  }
  res_file << constants.get_int("NUMBER_OF_POPS") << " ";
  res_file << constants.get_int("NUM_DAYS") << endl;

  for (int n = 0; n != constants.get_int("NUM_RUNS"); ++n) {
    vector<Event*> events;
    vector<Population> pops;
    for (int nn = 0; nn!= constants.get_int("NUMBER_OF_POPS"); ++nn) pops.push_back(Population());

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

    Event_encounter ev29(pops[0], pops[1]);
    Event_external_tra_susA ev30(pops[0], pops[1]);
    Event_external_tra_susI ev31(pops[0], pops[1]);
    Event_external_tra_susY ev32(pops[0], pops[1]);

    Event_age_carI_carY ev33(pops[1]);
    Event_age_carY_carA ev34(pops[1]);
    Event_age_immI_immY ev35(pops[1]);
    Event_age_immY_immA ev36(pops[1]);
    Event_age_susI_susY ev37(pops[1]);
    Event_age_susY_susA ev38(pops[1]);

    Event_birth ev39(pops[1]);
    Event_death_carA ev40(pops[1]);
    Event_death_susA ev41(pops[1]);
    Event_death_immA ev42(pops[1]);
    Event_death_sicA ev43(pops[1]);
    Event_death_sicI ev44(pops[1]);
    Event_death_sicY ev45(pops[1]);

    Event_tra_susA ev46(pops[1]);
    Event_tra_susI ev47(pops[1]);
    Event_tra_susY ev48(pops[1]);
    Event_inv_infA ev49(pops[1]);
    Event_inv_infY ev50(pops[1]);
    Event_inv_infI ev51(pops[1]);
    Event_noninv_infA ev52(pops[1]);
    Event_noninv_infI ev53(pops[1]);
    Event_noninv_infY ev54(pops[1]);
    Event_rec_carA ev55(pops[1]);
    Event_rec_carY ev56(pops[1]);
    Event_rec_carI ev57(pops[1]);
    Event_rec_sicA ev58(pops[1]);
    Event_rec_sicY ev59(pops[1]);
    Event_rec_sicI ev60(pops[1]);

    Event_external_tra_susA ev61(pops[1], pops[0]);
    Event_external_tra_susI ev62(pops[1], pops[0]);
    Event_external_tra_susY ev63(pops[1], pops[0]);

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
    events.push_back(&ev29);
    events.push_back(&ev30);
    events.push_back(&ev31);
    events.push_back(&ev32);
    events.push_back(&ev33);
    events.push_back(&ev34);
    events.push_back(&ev35);
    events.push_back(&ev36);
    events.push_back(&ev37);
    events.push_back(&ev38);
    events.push_back(&ev39);
    events.push_back(&ev40);
    events.push_back(&ev41);
    events.push_back(&ev42);
    events.push_back(&ev43);
    events.push_back(&ev44);
    events.push_back(&ev45);
    events.push_back(&ev46);
    events.push_back(&ev47);
    events.push_back(&ev48);
    events.push_back(&ev49);
    events.push_back(&ev50);
    events.push_back(&ev51);
    events.push_back(&ev52);
    events.push_back(&ev53);
    events.push_back(&ev54);
    events.push_back(&ev55);
    events.push_back(&ev56);
    events.push_back(&ev57);
    events.push_back(&ev58);
    events.push_back(&ev59);
    events.push_back(&ev60);
    events.push_back(&ev61);
    events.push_back(&ev62);
    events.push_back(&ev63);

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
  res_file.close();
}
//   ofstream res_file;
//   res_file.open("data/simulation_agedist_2_pops.txt");
//   if(!res_file.is_open())  {
//     cerr << "Could not open the results file. If the folder 'data' does not exist, try creating it" << endl;
//     return 1;
//   }
//   res_file << constants.get_int("NUMBER_OF_POPS") << " ";
//   res_file << constants.get_int("NUM_DAYS") << endl;
//
//   vector<Population> tmp;
//
//   for (auto it = sims.begin(); it != sims.end(); ++it) {
//     for (int n = 0; n != constants.get_int("NUM_DAYS"); ++n) {
//       res_file << n << " ";
//       tmp = it->get_state_at(static_cast<double>(n));
//       for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
//         for (int k = 0; k!= constants.get_int("NUM_POPS"); ++k) {
//           res_file << iter->get_pop(k) << " ";
//         }
//       }
//       res_file << "\n";
//     }
//   }
//   res_file.close();
//   cout << "File output sucessful." << endl;
// }
