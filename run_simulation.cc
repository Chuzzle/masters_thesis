#include <istream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <typeinfo>

#define BOOST_NO_CXX11_SCOPED_ENUMS
#include <boost/filesystem.hpp>
#undef BOOST_NO_CXX11_SCOPED_ENUMS

#include "simulation.h"
#include "population.h"
#include "constants_runspec.h"
#include "events_wrapper.h"

using namespace std;

Constants_runspec constants;

vector<int> read_population() {
  vector<int> initial_pops(constants.get_int("NUM_POPS"));

  ifstream inp_file;
  string input_file_name = constants.get_string("INPUT_FILE");
  inp_file.open("data/" + input_file_name + ".txt");
  if(!inp_file.is_open()) {
    cerr << "Error opening the input file." << endl;
    exit(1);
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
  for (int n = 0; n != constants.get_int("NUM_POPS"); ++n) {
    inp_file >> k;
    initial_pops[n] = k;
  }

  inp_file.close();
  return initial_pops;
}

void print_res(Simulation& sim, string dir_path, int simulation_index) {
  ofstream res_file;
  string full_path = dir_path + "/simulation_results" + to_string(simulation_index) + ".txt";
  res_file.open(full_path);
  if (!res_file.is_open()) {
    cerr << "Error opening the results file, exiting." << endl;
    exit(1);
  }
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
  res_file.close();
}

int main() {

  string dir_path = "data/" + constants.get_string("OUTPUT_NAME");
  //boost::filesystem::path dir_path = "data/" + dir_path_str;
  if(boost::filesystem::is_directory(dir_path)) {
    cerr << "This simulation already exists, delete it to continue" << endl;
    exit(1);
  }
  if (!boost::filesystem::create_directory(dir_path)) {
    cerr << "Error creating directory, exiting." << endl;
    exit(1);
  }

  boost::filesystem::copy_file("constants_runspec.json", dir_path + "/constants_runspec.json");
  boost::filesystem::copy_file("events.json", dir_path + "/events.json");


  // Set up the output structure

  // If I want input, read from file
  Population pop_init;
  if (constants.get_int("INPUT")) {
    vector<int> initial_pops = read_population();
    pop_init = Population(initial_pops);
  }

  // Run simulation
  for (int n = 0; n != constants.get_int("NUM_RUNS"); ++n) {
      // Initialize populations
      vector<Population> pops;
      for (int n = 0; n!= constants.get_int("NUMBER_OF_POPS"); ++n) pops.push_back(Population(pop_init));

      //Initialize events
      Events_wrapper ev;
      vector<Event*> event_pointers = ev.initialize_events(pops);
      Simulation sim(pops, event_pointers);
      sim.simulate();
      print_res(sim, dir_path, n);
  }
}
