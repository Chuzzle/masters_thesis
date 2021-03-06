#include "events_wrapper.h"

using namespace std;

Events_wrapper::Events_wrapper()  {
  ifstream inp_file;
  inp_file.open("events.json");
  if (!inp_file.is_open()) {
    cerr << "Error loading the events" << endl;
    exit(1);
  }
  Json::Reader reader;
  if (!reader.parse(inp_file, events)) {
    cerr << "Error reading the json file with events:" << reader.getFormattedErrorMessages() << endl;
    exit(1);
  }
  inp_file.close();
}

vector<Event*> Events_wrapper::initialize_events(vector<Population>& pops) {
  int event_index = 0;

  ofstream index_file;
  string path_index_file = "data/" + constants.get_string("OUTPUT_NAME") + "/events_indices.txt";
  index_file.open(path_index_file);

  if (!index_file.is_open()) {
    cerr << "Error storing event indices" << endl;
    exit(1);
  }

  for (int n = 0; n != constants.get_int("NUMBER_OF_POPS"); ++n) {
    if (events["event_age_carI_carY"].asInt()) {
      Event_age_carI_carY* ev = new Event_age_carI_carY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_age_carY_carA"].asInt()) {
      Event_age_carY_carA* ev = new Event_age_carY_carA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_age_immI_immY"].asInt()) {
      Event_age_immI_immY* ev = new Event_age_immI_immY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_age_immY_immA"].asInt()) {
      Event_age_immY_immA* ev = new Event_age_immY_immA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_age_susI_susY"].asInt()) {
      Event_age_susI_susY* ev = new Event_age_susI_susY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_age_susY_susA"].asInt()) {
      Event_age_susY_susA* ev = new Event_age_susY_susA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_birth"].asInt()) {
      Event_birth* ev = new Event_birth(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_death_carA"].asInt()) {
      Event_death_carA* ev = new Event_death_carA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_death_immA"].asInt()) {
      Event_death_immA* ev = new Event_death_immA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_death_susA"].asInt()) {
      Event_death_susA* ev = new Event_death_susA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_death_sicA"].asInt()) {
      Event_death_sicA* ev = new Event_death_sicA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_death_sicY"].asInt()) {
      Event_death_sicY* ev = new Event_death_sicY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_death_sicI"].asInt()) {
      Event_death_sicI* ev = new Event_death_sicI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_tra_susA"].asInt()) {
      Event_tra_susA* ev = new Event_tra_susA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_tra_susY"].asInt()) {
      Event_tra_susY* ev = new Event_tra_susY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_tra_susI"].asInt()) {
      Event_tra_susI* ev = new Event_tra_susI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_infI"].asInt()) {
      Event_inv_infI* ev = new Event_inv_infI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_infY"].asInt()) {
      Event_inv_infY* ev = new Event_inv_infY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_infA"].asInt()) {
      Event_inv_infA* ev = new Event_inv_infA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_noninv_infI"].asInt()) {
      Event_noninv_infI* ev = new Event_noninv_infI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_noninv_infY"].asInt()) {
      Event_noninv_infY* ev = new Event_noninv_infY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_noninv_infA"].asInt()) {
      Event_noninv_infA* ev = new Event_noninv_infA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carI_imm"].asInt()) {
      Event_rec_carI_imm* ev = new Event_rec_carI_imm(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carI_noImm"].asInt()) {
      Event_rec_carI_noImm* ev = new Event_rec_carI_noImm(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carY_imm"].asInt()) {
      Event_rec_carY_imm* ev = new Event_rec_carY_imm(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carY_noImm"].asInt()) {
      Event_rec_carY_noImm* ev = new Event_rec_carY_noImm(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carA_imm"].asInt()) {
      Event_rec_carA_imm* ev = new Event_rec_carA_imm(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carA_noImm"].asInt()) {
      Event_rec_carA_noImm* ev = new Event_rec_carA_noImm(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_carA_immPerA"].asInt()) {
      Event_rec_carA_immPerA* ev = new Event_rec_carA_immPerA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_sicI"].asInt()) {
      Event_rec_sicI* ev = new Event_rec_sicI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_sicY"].asInt()) {
      Event_rec_sicY* ev = new Event_rec_sicY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_sicA"].asInt()) {
      Event_rec_sicA* ev = new Event_rec_sicA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_tra_immA"].asInt()) {
      Event_tra_immA* ev = new Event_tra_immA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_tra_immI"].asInt()) {
      Event_tra_immI* ev = new Event_tra_immI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_tra_immY"].asInt()) {
      Event_tra_immY* ev = new Event_tra_immY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_immI"].asInt()) {
      Event_rec_immI* ev = new Event_rec_immI(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_immY"].asInt()) {
      Event_rec_immY* ev = new Event_rec_immY(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_rec_immA"].asInt()) {
      Event_rec_immA* ev = new Event_rec_immA(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_infA_seasonal"].asInt()) {
      Event_inv_infA_seasonal* ev = new Event_inv_infA_seasonal(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_infY_seasonal"].asInt()) {
      Event_inv_infY_seasonal* ev = new Event_inv_infY_seasonal(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_infI_seasonal"].asInt()) {
      Event_inv_infI_seasonal* ev = new Event_inv_infI_seasonal(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_noninv_infA_seasonal"].asInt()) {
      Event_noninv_infA_seasonal* ev = new Event_noninv_infA_seasonal(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_inv_noninfY_seasonal"].asInt()) {
      Event_noninv_infY_seasonal* ev = new Event_noninv_infY_seasonal(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
    if (events["event_noninv_infI_seasonal"].asInt()) {
      Event_noninv_infI_seasonal* ev = new Event_noninv_infI_seasonal(pops[n]);
      event_list.push_back(ev);
      index_file << event_index++ << "    " << ev->description() << endl;
    }
  }
  if (events["event_encounter"].asInt()) {
    if (constants.get_int("NUMBER_OF_POPS") < 2) throw Illegal_event_exception();
    Event_encounter* ev = new Event_encounter(pops[0], pops[1]);
    Event_external_tra_susA* ev1 = new Event_external_tra_susA(pops[0], pops[1]);
    Event_external_tra_susY* ev2 = new Event_external_tra_susY(pops[0], pops[1]);
    Event_external_tra_susI* ev3 = new Event_external_tra_susI(pops[0], pops[1]);

    Event_external_tra_immA* ev4 = new Event_external_tra_immA(pops[0], pops[1]);
    Event_external_tra_immY* ev5 = new Event_external_tra_immY(pops[0], pops[1]);
    Event_external_tra_immI* ev6 = new Event_external_tra_immI(pops[0], pops[1]);

    Event_external_tra_susA* ev7 = new Event_external_tra_susA(pops[1], pops[0]);
    Event_external_tra_susY* ev8 = new Event_external_tra_susY(pops[1], pops[0]);
    Event_external_tra_susI* ev9 = new Event_external_tra_susI(pops[1], pops[0]);

    Event_external_tra_immA* ev10 = new Event_external_tra_immA(pops[1], pops[0]);
    Event_external_tra_immY* ev11 = new Event_external_tra_immY(pops[1], pops[0]);
    Event_external_tra_immI* ev12 = new Event_external_tra_immI(pops[1], pops[0]);

    event_list.push_back(ev);
    index_file << event_index++ << "    " << ev->description() << endl;
    event_list.push_back(ev1);
    index_file << event_index++ << "    " << ev1->description() << endl;
    event_list.push_back(ev2);
    index_file << event_index++ << "    " << ev2->description() << endl;
    event_list.push_back(ev3);
    index_file << event_index++ << "    " << ev3->description() << endl;
    event_list.push_back(ev4);
    index_file << event_index++ << "    " << ev4->description() << endl;
    event_list.push_back(ev5);
    index_file << event_index++ << "    " << ev5->description() << endl;
    event_list.push_back(ev6);
    index_file << event_index++ << "    " << ev6->description() << endl;
    event_list.push_back(ev7);
    index_file << event_index++ << "    " << ev7->description() << endl;
    event_list.push_back(ev8);
    index_file << event_index++ << "    " << ev8->description() << endl;
    event_list.push_back(ev9);
    index_file << event_index++ << "    " << ev9->description() << endl;
    event_list.push_back(ev10);
    index_file << event_index++ << "    " << ev10->description() << endl;
    event_list.push_back(ev11);
    index_file << event_index++ << "    " << ev11->description() << endl;
    event_list.push_back(ev12);
    index_file << event_index++ << "    " << ev12->description() << endl;
  }
  index_file.close();
  return event_list;
}

void Events_wrapper::delete_events() {
  for_each(event_list.begin(), event_list.end(), [] (Event* ev) {delete ev;});
}
