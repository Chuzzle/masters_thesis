from __future__ import division
import numpy as np
import matplotlib.pyplot as plt
import sys
import os
import errno
import json
import itertools
import copy
import statsmodels.tsa.stattools as st

def run(pars):
    dir_name = pars[0]

    dir_here = os.path.dirname(os.path.relpath(__file__))
    dir_data = dir_here + "/../data/" + dir_name

    constants = read_constants(dir_data)

    base_mat = np.zeros((constants['NUM_POPS'], constants['NUM_DAYS']))

    raw_data = np.array([np.copy(base_mat) for _ in xrange(constants['NUM_RUNS'])])

    average_pops = np.copy(base_mat)

    dir_pop_data = dir_data + '/simulation_results'
    for n in xrange(constants['NUM_RUNS']):
        raw_data[n] = read_data_file(constants, dir_pop_data, n, constants['NUM_POPS'], include_0 = False)
    ###################TODO: Plot the full data, and save the plot

    nonzero_pop_indices = np.array([constants['INFANTS_SUSC'], constants['INFANTS_INF'], constants['INFANTS_SICK'], constants['INFANTS_IMMUNE'], constants['INFANTS_CARRIERS'],
                        constants['YOUNG_SUSC'], constants['YOUNG_INF'], constants['YOUNG_SICK'], constants['YOUNG_IMMUNE'], constants['YOUNG_CARRIERS'],
                        constants['ADULT_SUSC'], constants['ADULT_INF'], constants['ADULT_SICK'], constants['ADULT_IMMUNE'], constants['YOUNG_CARRIERS']])

    plt.figure('Raw data for all runs')
    plt.hold(True)
    time = np.arange(constants['NUM_DAYS'])

    for n in xrange(constants['NUM_RUNS']):
        data_pl = raw_data[n]
        for k in nonzero_pop_indices:
            plt.plot(time, data_pl[k,:])

    dir_processed_data = dir_data + '/processed_data'
    try:
        os.makedirs(dir_processed_data)
    except OSError as exception:
        if exception.errno != errno.EEXIST:
            raise

    plt.savefig(dir_processed_data + '/raw_data.pdf')
    #####################

    #####################TODO: Make an average of all runs, save it. Only save the non-zero pops
    average_pops = np.mean(raw_data[:,nonzero_pop_indices,:], axis = 0)

    # Write the averages to file
    with open(dir_processed_data + '/average_data.txt', 'w') as output_file:
        np.savetxt(output_file, average_pops, fmt = '%12.5f')
    #####################

    #####################TODO: Find ratios of sick-related subgroups, irrespective of age, save it

    grouped_disease_ratio = np.zeros([constants['NUM_RUNS'], 3, constants['NUM_DAYS']])
    for k in xrange(constants['NUM_RUNS']):
        for n in xrange(constants['NUM_DAYS']):
            grouped_disease_ratio[k][0][n] = (np.sum(raw_data[[k],[constants['INFANTS_SICK'], constants['ADULT_SICK'], constants['YOUNG_SICK']],[n]])/
                                            np.sum(raw_data[[k],:,[n]]))
            grouped_disease_ratio[k][1][n] = (np.sum(raw_data[[k],[constants['INFANTS_IMMUNE'], constants['YOUNG_IMMUNE'], constants['ADULT_IMMUNE']],[n]])/
                                            np.sum(raw_data[[k],:,[n]]))
            grouped_disease_ratio[k][2][n] = (np.sum(raw_data[[k],[constants['INFANTS_CARRIERS'], constants['YOUNG_CARRIERS'], constants['ADULT_CARRIERS']],[n]])/
                                            np.sum(raw_data[[k],:,[n]]))

    grouped_disease_ave = np.mean(grouped_disease_ratio, 0)

    with open(dir_processed_data + '/average_disease_ratios.txt', 'w') as output_file:
        np.savetxt(output_file, grouped_disease_ave, fmt = '%12.5f')

    #####################

    #####################TODO: Find ratios of sub-pops in different age groups, save it

    infant_ratios = np.zeros([constants['NUM_RUNS'], 3, constants['NUM_DAYS']])
    young_ratios = np.zeros([constants['NUM_RUNS'], 3, constants['NUM_DAYS']])
    adult_ratios = np.zeros([constants['NUM_RUNS'], 3, constants['NUM_DAYS']])

    for k in xrange(constants['NUM_RUNS']):
        for n in xrange(constants['NUM_DAYS']):
            infant_ratios[k][0][n] = raw_data[k][constants['INFANTS_SICK']][n]
            infant_ratios[k][1][n] = raw_data[k][constants['INFANTS_IMMUNE']][n]
            infant_ratios[k][2][n] = raw_data[k][constants['INFANTS_CARRIERS']][n]
            infant_ratios[[k],:,[n]] /= (np.sum(raw_data[[k],[constants['INFANTS_INF'], constants['INFANTS_CARRIERS'],
                                    constants['INFANTS_IMMUNE'], constants['INFANTS_SICK'], constants['INFANTS_SUSC']],[n]]))
            young_ratios[k][0][n] = raw_data[k][constants['YOUNG_SICK']][n]
            young_ratios[k][1][n] = raw_data[k][constants['YOUNG_IMMUNE']][n]
            young_ratios[k][2][n] = raw_data[k][constants['YOUNG_CARRIERS']][n]
            young_ratios[[k],:,[n]] /= (np.sum(raw_data[[k],[constants['YOUNG_INF'], constants['YOUNG_CARRIERS'],
                                    constants['YOUNG_IMMUNE'], constants['YOUNG_SICK'], constants['YOUNG_SUSC']],[n]]))

            adult_ratios[k][0][n] = raw_data[k][constants['ADULT_SICK']][n]
            adult_ratios[k][1][n] = raw_data[k][constants['ADULT_IMMUNE']][n]
            adult_ratios[k][2][n] = raw_data[k][constants['ADULT_CARRIERS']][n]
            adult_ratios[[k],:,[n]] /= (np.sum(raw_data[[k],[constants['ADULT_INF'], constants['ADULT_CARRIERS'],
                                    constants['ADULT_IMMUNE'], constants['ADULT_SICK'], constants['ADULT_SUSC']],[n]]))
    infant_ratios_ave = np.mean(infant_ratios, 0)
    young_ratios_ave = np.mean(young_ratios, 0)
    adult_ratios_ave = np.mean(adult_ratios, 0)

    # print to file
    with open(dir_processed_data + '/average_disease_ratios_infants.txt', 'w') as output_file:
        np.savetxt(output_file, infant_ratios_ave, fmt = '%12.5f')

    with open(dir_processed_data + '/average_disease_ratios_young.txt', 'w') as output_file:
        np.savetxt(output_file, young_ratios_ave, fmt = '%12.5f')

    with open(dir_processed_data + '/average_disease_ratios_adults.txt', 'w') as output_file:
        np.savetxt(output_file, adult_ratios_ave, fmt = '%12.5f')

    ################################

    ################################TODO: count the weekly incidence rates
    dir_event_data = dir_data + '/simulation_results_eventcounts'
    num_events = file_length(dir_data + '/events_indices.txt')
    base_mat_events = np.zeros((num_events, constants['NUM_DAYS']))
    raw_events_data = np.array([np.copy(base_mat_events) for _ in xrange(constants['NUM_RUNS'])])
    for n in xrange(constants['NUM_RUNS']):
        raw_events_data[[n],:,:] = read_data_file(constants, dir_event_data, n, num_events)

    raw_events_data = np.diff(raw_events_data, axis = 2)
    events_ave = np.mean(raw_events_data[:,:,1999:], 0)
    with open(dir_processed_data + '/average_daily_event_data.txt', 'w') as output_file:
        np.savetxt(output_file, events_ave, fmt = '%12.5f')

    #TODO: Produce weekly data points

    #TODO Create separate data sets for dry/wet season
    time_events = np.arange(2000, constants['NUM_DAYS'])
    # remove the first year of data
    dry_indices = np.logical_and((time_events % 365) < constants['DRY_END'], (time_events % 365) > constants['DRY_START'])
    wet_indices = np.logical_not(dry_indices)

    dry_data = events_ave[:, dry_indices]
    wet_data = events_ave[:, wet_indices]

    dry_ave = np.mean(dry_data, 1)
    wet_ave = np.mean(wet_data, 1)

    #Save mean daily incidence rate for different seasons
    with open(dir_processed_data + '/average_daily_events_dry.txt', 'w') as output_file:
        np.savetxt(output_file, dry_ave, fmt = '%12.5f')

    with open(dir_processed_data + '/average_daily_events_wet.txt', 'w') as output_file:
        np.savetxt(output_file, wet_ave, fmt = '%12.5f')

    # Find weekly incidence
    ave_weekly_incidence = np.transpose(np.array([np.sum(events_ave[:,k-7:k], axis = 1) for k in xrange(7, events_ave.shape[1])]))
    ave_weekly_incidence_ratio = ave_weekly_incidence/np.sum(average_pops[:,2007:], axis = 0) * 1e5
    ave_ave_weekly_incidence_ratio = np.mean(ave_weekly_incidence_ratio, axis = 1)

    with open(dir_processed_data + '/average_weekly_events_ratio.txt', 'w') as output_file:
        np.savetxt(output_file, ave_weekly_incidence_ratio, fmt = '%12.5f')

    with open(dir_processed_data + '/time_average_weekly_incidence_ratio.txt', 'w') as output_file:
        np.savetxt(output_file, ave_ave_weekly_incidence_ratio, fmt = '%12.5f')

    # Summing seven numbers reduces the humber of data points by 6
    ave_weekly_incidence_ratio_dry = ave_weekly_incidence_ratio[:, dry_indices[7:]]
    ave_weekly_incidence_ratio_wet = ave_weekly_incidence_ratio[:, wet_indices[7:]]

    with open(dir_processed_data + '/average_weekly_events_ratio_dry.txt', 'w') as output_file:
        np.savetxt(output_file, ave_weekly_incidence_ratio_dry, fmt = '%12.5f')

    with open(dir_processed_data + '/average_weekly_events_ratio_wet.txt', 'w') as output_file:
        np.savetxt(output_file, ave_weekly_incidence_ratio_wet, fmt = '%12.5f')

    #Also save the average of the weekly incidence ratios for the different seasons.
    ave_ave_weekly_incidence_ratio_wet = np.mean(ave_weekly_incidence_ratio_wet, axis = 1)
    ave_ave_weekly_incidence_ratio_dry = np.mean(ave_weekly_incidence_ratio_dry, axis = 1)

    with open(dir_processed_data + '/time_average_weekly_incidence_ratios_dry.txt', 'w') as output_file:
        np.savetxt(output_file, ave_ave_weekly_incidence_ratio_dry, fmt = '%12.5f')

    with open(dir_processed_data + '/time_average_weekly_incidence_ratios_wet.txt', 'w') as output_file:
        np.savetxt(output_file, ave_ave_weekly_incidence_ratio_wet, fmt = '%12.5f')

    # Calculate standard deviations of dependent measures (such as my weekly incidence rates)
    num_samples_all = ave_weekly_incidence_ratio.shape[1]
    max_lags_all = np.floor(num_samples_all/4)

    num_samples_dry = ave_weekly_incidence_ratio_dry.shape[1]
    max_lags_dry = np.floor(num_samples_dry/4)

    num_samples_wet = ave_weekly_incidence_ratio_wet.shape[1]
    max_lags_wet = np.floor(num_samples_wet/4)

    variance_weekly_incidence_ratio = np.array([np.sum(st.acovf(ave_weekly_incidence_ratio[k,:])[:max_lags_all]) for k in xrange(num_events)])
    variance_weekly_incidence_ratio /= num_samples_all

    variance_weekly_incidence_ratio_wet = np.array([np.sum(st.acovf(ave_weekly_incidence_ratio_wet[k,:])[:max_lags_wet]) for k in xrange(num_events)])
    variance_weekly_incidence_ratio_wet /= num_samples_wet

    variance_weekly_incidence_ratio_dry = np.array([np.sum(st.acovf(ave_weekly_incidence_ratio_dry[k,:])[:max_lags_dry]) for k in xrange(num_events)])
    variance_weekly_incidence_ratio_dry /= num_samples_dry

    with open(dir_processed_data + '/var_weekly_incidence_mean.txt', 'w') as output_file:
        np.savetxt(output_file, variance_weekly_incidence_ratio, fmt = '%12.5f')

    with open(dir_processed_data + '/var_weekly_incidence_mean_dry.txt', 'w') as output_file:
        np.savetxt(output_file, variance_weekly_incidence_ratio_dry, fmt = '%12.5f')

    with open(dir_processed_data + '/var_weekly_incidence_mean_wet.txt', 'w') as output_file:
        np.savetxt(output_file, variance_weekly_incidence_ratio_wet, fmt = '%12.5f')

def read_constants(dir_name):
    with open(dir_name + '/constants_runspec.json') as parameters_file:
        constants = json.load(parameters_file)
    return constants

def read_data_file(constants, target_name, sim_number, datapts_number, include_0 = True):

    return_data = np.zeros((datapts_number, constants['NUM_DAYS']), dtype = np.int)
    file_name = target_name + str(sim_number) + '.txt'
    with open(file_name) as data_file:
        for n in xrange(constants['NUM_DAYS']):
            data_string = data_file.readline()
            data = data_string.split()
            if not include_0:
                data = data[1:]
            data = np.array(data, dtype = np.int)
            if not include_0:
                for k in xrange(constants['NUMBER_OF_POPS']):
                    return_data[:,n] += data[k*datapts_number:(k+1)*datapts_number]
            else:
                return_data[:,n] = data
    return return_data

def file_length(target_name):
    with open(target_name) as file:
        for i,l in enumerate(file):
            pass
    return i+1

if __name__ == '__main__':
    run(sys.argv[1:])
