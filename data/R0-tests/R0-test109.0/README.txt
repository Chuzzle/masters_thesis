Guide to the data format:

constants_runspec.json contains the specific numerical values of parameters used
  in this particular run, as well as the population indices. Note that if the
  variable "INPUT" is set, the population inits are not necessarily used.

events.json contains a list of possible events, with a 1 if the event was used
  in this run and a 0 if not.

event_indices.txt lists the indices of each event and the description of the
  event, as provided by the event itself. Note that this only contains
  information about events actually used in the run.

simulation_resultsX.txt contains the system states for the Xth run.
  The first column is the time index (in this case, days) and the following
  columns are the number of individuals in each population, indexed as described
  in constants_runspec.json.

simulation_results_eventcountsX.txt lists the number of events that has occurred
  at a given time slot. No time data is given, but corresponds to the timestamps
  in the simulation_results file. The indices correspond to what is given in
  event_indices.txt

The folder processed_data contains some metrics, obtained from data analysis.
