import numpy as np
import matplotlib.pyplot as plt
import sys
import os
import errno
import json
import itertools
import copy

# The run-method currently reads data from file and produces an average from all runs (over all sub-populations seperately). The std:s between simulation runs is also iteratively calculated.
# It then plots the averages, grouped by disease status.

def run(pars):
    # The input parameter should be the name of the super folder which holds the simulation results
    directory_name = pars[0]


    here_dir = os.path.dirname(os.path.relpath(__file__))
    data_directory = here_dir + '/../data/' + directory_name

    # Read the constants from the interesting directory. Should correspond to the constants for the simulation run in question
    constants = read_constants(data_directory)

    # Create some sort of aggregate data. Data structure is: Full data is a list of lists, where the outermost layer signifies the run in question,
    # each sub-list splits into the relevant populations and below that is an np.array which holds the values themselves
    base_mat = np.zeros((constants['NUM_POPS'], constants['NUM_DAYS']))
    base_list = [np.copy(base_mat) for _ in xrange(constants['NUMBER_OF_POPS'])]
    full_data = [copy.deepcopy(base_list) for _ in xrange(constants['NUM_RUNS'])]

    events_list = []

    num_events = file_len(data_directory + '/events_indices.txt')

    for n in xrange(constants['NUM_RUNS']):
        event_data = read_events_file(constants, data_directory, n, num_events)
        events_list.append(event_data)

    daily_events = [np.diff(events) for events in events_list]
    daily_events_average = sum(daily_events)/float(constants['NUM_DAYS'])
    write_to_file(data_directory, constants, 'daily_events_ave', daily_events_average)

    # Averages is an average over the different runs. It is a list of np.arrays, each list element being one of the populations included in the run
    averages = copy.deepcopy(base_list)
    # std_devs is formatted as the averages list above
    std_devs = copy.deepcopy(base_list)
    average_ratio = copy.deepcopy(base_list)

    # This reads the data from file into the structures we've defined above. Return value is formatted as above.
    for n in xrange(constants['NUM_RUNS']):
    #for n in xrange(10):
        temp_data = read_data_file(constants, data_directory, n)
        for k in xrange(constants['NUMBER_OF_POPS']):
            full_data[n][k] = np.copy(temp_data[k])
            averages[k] += temp_data[k]
            std_devs[k] += np.square(temp_data[k])
            average_ratio[k] += temp_data[k]/np.sum(temp_data[k], 0, dtype = np.float)


    # Here the averages and std_devs are calculated from the data, and then written to file

    averages[:] = [ave/float(constants['NUM_RUNS']) for ave in averages]
    average_ratio[:] = [ave_rat/float(constants['NUM_RUNS']) for ave_rat in average_ratio]
    std_devs[:] = [(std_dev - np.square(ave) * constants['NUM_RUNS'])/float((constants['NUM_RUNS'] - 1)) for std_dev, ave in zip(std_devs, averages)]

    for index in xrange(constants['NUMBER_OF_POPS']):
        outp_file_ave = 'averages' + str(index) + '.txt'
        outp_file_stddev = 'std_devs' + str(index) + '.txt'
        outp_file_ratios = 'ratios' + str(index) + '.txt'

        write_to_file(data_directory, constants, outp_file_ave, averages[index])
        write_to_file(data_directory, constants, outp_file_stddev, std_devs[index])
        write_to_file(data_directory, constants, outp_file_ratios, average_ratio[index])

    # The dictionary below connects the string holding the name of the population to the index it has in the data structure. Allows for a more generic plot function.
    # TODO: change this section if vaccination is implemented.
    nonzero_pop_indices = {"I, Susceptible" : constants['INFANTS_SUSC'], "I, Infected" : constants['INFANTS_INF'], "I, Sick" : constants['INFANTS_SICK'], "I, Carriers" : constants['INFANTS_CARRIERS'], "I, Immune" : constants['INFANTS_IMMUNE'], "Y, Susceptible" : constants['YOUNG_SUSC'], "Y, Infected" : constants['YOUNG_INF'], "Y, Sick" : constants['YOUNG_SICK'], "Y, Carriers" : constants['YOUNG_CARRIERS'], "Y, Immune" : constants['YOUNG_IMMUNE'], "A, Susceptible" : constants['ADULT_SUSC'], "A, Infected" : constants['ADULT_INF'], "A, Sick" : constants['ADULT_SICK'], "A, Carriers" : constants['ADULT_CARRIERS'], "A, Immune" : constants['ADULT_IMMUNE']}

    # Construct an array holding all integer numbers for days in the dry season, after year five

    day_indices = np.arange(5*365, constants['NUM_DAYS'])
    dry_days = day_indices[day_indices%365 > constants['DRY_START']]
    dry_days = dry_days[dry_days%365 < constants['DRY_END']]

    wet_days = day_indices[(day_indices - constants['DRY_START'])%365 > constants['DRY_END'] - constants['DRY_START']]

    dry_ave_base = np.zeros((constants['NUM_POPS'],1))
    dry_aves = [np.copy(dry_ave_base) for _ in xrange(constants['NUMBER_OF_POPS'])]
    wet_aves = [np.copy(dry_ave_base) for _ in xrange(constants['NUMBER_OF_POPS'])]

    # for index in xrange(constants['NUMBER_OF_POPS']):
    #     dry_aves[index] = np.sum(averages[index][:,dry_days],1)
    #     dry_aves[index] /= np.size(dry_days)
    #
    #     wet_aves[index] = np.sum(averages[index][:,wet_days],1)
    #     wet_aves[index] /= np.size(wet_days)
    #     print np.size(wet_days)

    # write_to_file(directory_name, constants, 'dry_data', dry_aves)
    # write_to_file(directory_name, constants, 'wet_data', wet_aves)

    # The plot_pop function produces a plot of a single population, as guided by the index data in the indices dictionary.
    for n in xrange(constants['NUMBER_OF_POPS']):
        plot_str = 'Standard deviation of the averages, population ' + str(n)
        plot_pop(constants, std_devs[n], nonzero_pop_indices, plot_str)

    # Plot some raw data. This is to determine whether there seems to be a significant difference between runs,which would motivate a different grouping strategy.
    for n in xrange(constants['NUMBER_OF_POPS']):
        for k in xrange(constants['NUM_RUNS']):
        #for k in xrange(10):
            raw_data_str = 'Raw data'
            plot_pop(constants, full_data[k][n], nonzero_pop_indices, raw_data_str, legend = False)
        plot_pop(constants, averages[n], nonzero_pop_indices, 'Average data' + str(n))

    grouped_averages = []
    grouped_ratios = []

    # Here, we group the average data over each population by disease status and subsequently plot them.
    for n in xrange(constants['NUMBER_OF_POPS']):
        group_ave, indices_ave = group_by_disease(constants, averages[n])
        grouped_averages.append(group_ave)
        plot_pop(constants, group_ave, indices_ave, 'Results grouped by disease status' + str(n))
        group_ratio, indices_ratio = group_by_disease(constants, average_ratio[n])
        grouped_ratios.append(group_ratio)
        plot_pop(constants, group_ratio, indices_ratio, 'Ratios grouped by disease status' + str(n))


    # Plot the groups and ratios of immune as grouped by age, for each population.
    immune_indices = {"Infants" : constants['INFANTS_IMMUNE'], "Young" : constants['YOUNG_IMMUNE'], "Adult" : constants['ADULT_IMMUNE']}
    for n in xrange(constants['NUMBER_OF_POPS']):
        plot_pop(constants, average_ratio[n], immune_indices, 'Ratios of immune by age, pop ' + str(n))

    #TODO: Use the existing framework to store the results I want. Seperate files for each data point? A seperate key?

    #TODO: Create a plot with only sick individuals
    sick_indices = {"Infants" : constants['INFANTS_SICK'], "Young" : constants['YOUNG_SICK'], "Adult" : constants['ADULT_SICK']}
    for n in xrange(constants['NUMBER_OF_POPS']):
        plot_pop(constants, averages[n], sick_indices, 'Average number of sick by age, pop ' + str(n))

    #TODO: Construct data structure for dry/wet seasons.

    plt.show()

def read_constants(directory_name):
    with open(directory_name + '/constants_runspec.json') as parameters_file:
        constants = json.load(parameters_file)
    return constants

def read_data_file(constants, directory_name, number):
    base_mat = np.zeros((constants['NUM_POPS'], constants['NUM_DAYS']), dtype = np.int)
    return_data = [np.copy(base_mat) for _ in xrange(constants['NUMBER_OF_POPS'])]
    # return_data = [np.zeros((constants['NUM_POPS'], constants['NUM_DAYS']), dtype = np.int)] * constants['NUMBER_OF_POPS']
    file_name = directory_name + '/simulation_results' + str(number) + '.txt'
    with open(file_name) as data_file:
        for n in xrange(constants['NUM_DAYS']):
            data_string = data_file.readline()
            data = (data_string.split())[1:]
            data = np.array(data, dtype = np.int)
            for k in xrange(constants['NUMBER_OF_POPS']):
                return_data[k][:,n] = data[k*constants['NUM_POPS']:(k + 1)*constants['NUM_POPS']]
    return return_data

def read_events_file(constants, directory_name, number, num_events):
    # Determine the number of events

    return_data = np.zeros((num_events, constants['NUM_DAYS']), dtype = np.int)
    events_file = directory_name + '/simulation_results' + str(number) + '_eventcounts.txt'
    with open(events_file) as ev_file:
        for n in xrange(constants['NUM_DAYS']):
            data_string = ev_file.readline()
            data = data_string.split()
            data = np.array(data, dtype = np.int)
            return_data[:,n] = data
    return return_data

def write_to_file(directory_name, constants, output_file_name, data):
    full_path =  directory_name + '/processed_data'
    try:
        os.makedirs(full_path)
    except OSError as exception:
        if exception.errno != errno.EEXIST:
            raise

    with open(full_path + '/' + output_file_name, 'w') as output_file:
        np.savetxt(output_file, data, fmt = '%12.5f')

    output_file.close()

def group_by_disease(constants, data_set):
    grouped = np.zeros((5,constants['NUM_DAYS']))
    result_indices = {'sick' : 0, 'susceptible' : 1, 'infected' : 2, 'carriers' : 3, 'immune' : 4}

    sick_indices = np.array([constants['INFANTS_SICK'], constants['YOUNG_SICK'], constants['ADULT_SICK']])
    susceptible_indices = np.array([constants['INFANTS_SUSC'], constants['YOUNG_SUSC'], constants['ADULT_SUSC']])
    infected_indices = np.array([constants['INFANTS_INF'], constants['YOUNG_INF'], constants['ADULT_INF']])
    carrier_indices = np.array([constants['INFANTS_CARRIERS'], constants['YOUNG_CARRIERS'], constants['ADULT_CARRIERS']])
    immune_indices = np.array([constants['INFANTS_IMMUNE'], constants['YOUNG_IMMUNE'], constants['ADULT_IMMUNE']])
    for n in xrange(constants['NUM_DAYS']):
        grouped[result_indices['sick'], n] = np.sum(data_set[sick_indices, n])
        grouped[result_indices['susceptible'], n] = np.sum(data_set[susceptible_indices, n])
        grouped[result_indices['infected'], n] = np.sum(data_set[infected_indices, n])
        grouped[result_indices['carriers'], n] = np.sum(data_set[carrier_indices, n])
        grouped[result_indices['immune'], n] = np.sum(data_set[immune_indices, n])
    return grouped, result_indices

def plot_pop(constants, data, indices, title_string, legend = True):
    plt.figure(title_string)
    plt.hold(True)
    time = np.arange(constants['NUM_DAYS'])
    if legend:
        for name, index in indices.iteritems():
            plt.plot(time, data[index,:], label = name)
        plt.legend()
    else:
        for index in indices.itervalues():
            plt.plot(time, data[index,:])
    #plt.legend()

def file_len(f):
    with open(f) as file:
        for i,l in enumerate(file):
            pass
    return i+1

if __name__ == '__main__':
    run(sys.argv[1:])
