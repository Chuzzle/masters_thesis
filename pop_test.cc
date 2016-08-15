#include <iostream>

#include "population.h"
#include "constants_runspec.h"

using namespace std;

int main() {
  Population pop;
  Constants_runspec constants;

  cout << pop.get_pop(constants.get_int("INFANTS_SUSC")) << endl;
  cout << pop.get_pop(constants.get_int("YOUNG_SUSC")) << endl;

  pop.move_pop(constants.get_int("INFANTS_SUSC"), constants.get_int("YOUNG_SUSC"));

  cout << pop.get_pop(constants.get_int("INFANTS_SUSC")) << endl;
  cout << pop.get_pop(constants.get_int("YOUNG_SUSC")) << endl;

  pop.decrease_pop(constants.get_int("INFANTS_SUSC"));

  cout << pop.get_pop(constants.get_int("INFANTS_SUSC")) << endl;

  pop.increment_pop(constants.get_int("INFANTS_SUSC"));

  cout << pop.get_pop(constants.get_int("INFANTS_SUSC")) << endl;

  try {
    pop.decrease_pop(constants.get_int("INFANTS_SICK"));
  } catch(Illegal_event_exception &error) {
    cout << "Illegal event" << endl;
  }
  cout << pop.get_pop(constants.get_int("INFANTS_SICK")) << endl;

  try{
    pop.move_pop(constants.get_int("INFANTS_SICK"), constants.get_int("INFANTS_SUSC"));
  } catch(Illegal_event_exception &error) {
    cout << "Illegal event 2" << endl;
  }
  cout << pop.get_pop(constants.get_int("INFANTS_SICK")) << endl;
  cout << pop.get_pop(constants.get_int("INFANTS_SUSC")) << endl;

}
