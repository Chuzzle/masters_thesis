#include "constants_runspec.h"

using namespace std;

bool Constants_runspec::encounter_active = false;

Constants_runspec::Constants_runspec() {
  ifstream inp_stream;
  inp_stream.open("constants_runspec.json");
  if (!inp_stream.is_open()) {
    cerr << "Error loading constants";
    exit(1);
  }
  Json::Reader reader;
  if (!reader.parse(inp_stream, constants, false)) {
    cerr << "Error reading constants." << reader.getFormattedErrorMessages() << endl;
    exit(1);
  }
  inp_stream.close();
}

int Constants_runspec::get_int(string key) {
  if (constants.isMember(key) && constants[key].isInt()) {
    return constants[key].asInt();
  }
  cerr << "Error in the constants formatting; note that all indices and initial populations must be integers." << endl;
  exit(1);
}

double Constants_runspec::get_prob(string key) {
  if (constants.isMember(key) && constants[key].isDouble()) return constants[key].asDouble();
  cerr << "Error in the constants formatting; note that all probabilities must be doubles." << endl;
  exit(1);
}

int Constants_runspec::is_dry(double t) {
  while (t > 365.0) t -= 365.;
  return (t > this->get_prob("DRY_START")) && (t < this->get_prob("DRY_END"));
}

string Constants_runspec::get_string(string key) {
  if (constants.isMember(key) && constants[key].isString()) {
    return constants[key].asString();
  }
  cerr << "Error in the constants formatting; check your string formats." << endl;
  exit(1);
}
