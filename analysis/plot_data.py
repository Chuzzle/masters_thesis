from __future__ import division
import numpy as np
import matplotlib.pyplot as plt
import sys
import os
import errno
import json
import copy
import process_data

def run(pars):
    dir_name = pars[0]
    dir_here = os.path.dirname(os.path.relpath(__file__))
    dir_top = dir_here + '/../data/' + dir_name
    dir_data = dir_top + '/processed_data'

    if not os.path.isdir(dir_data):
        print 'No directory for the processed data found, running the data processing script. This may take a few moments.'
        process_data.run(pars)

    constants = process_data.read_constants(dir_top)

    #TODO: Read the processed data from file
        # Use the function from process_data

    num_nonzero_pops = 15
    num_disease_statuses = 3

    pop_ave = read_processed(constants, dir_data + '/average_data', num_nonzero_pops)
    disease_rat = read_processed(constants, dir_data + '/average_disease_ratios', num_disease_statuses)
    disease_rat_adults = read_processed(constants, dir_data + '/average_disease_ratios_adults', num_disease_statuses)
    disease_rat_young = read_processed(constants, dir_data + '/average_disease_ratios_young', num_disease_statuses)
    disease_rat_infants = read_processed(constants, dir_data + '/average_disease_ratios_infants', num_disease_statuses)

    #TODO: Plot the processed data
    if len(pars) > 1:
        show_plots = pars[1]
    else:
        show_plots = False

    # Setup indices for plotting

    time_axis = np.arange(constants['NUM_DAYS'])
    pop_ave_indices = zip(['I, susceptible', 'I, infected', 'I, sick', 'I, immune', 'I, carriers',
                            'Y, Susceptible', 'Y, infected', 'Y, sick', 'Y, immune', 'Y, carriers',
                            'A, susceptible', 'A, infected', 'A, sick', 'A, immune', 'A, carriers'], xrange(num_nonzero_pops))

    disease_indices = zip(['Sick', 'Immune', 'Carriers'], xrange(num_disease_statuses))

    #TODO: Plot population averages

    fig_ave = 'Averages over all populations'
    plt.figure(fig_ave)
    plt.hold(True)

    for title, ind in pop_ave_indices:
        plt.plot(time_axis, pop_ave[ind,:], label = title)
    plt.legend()

    #TODO: Plot ratios of disease, irrespective of age
    fig_disease = 'Average ratio of disease within all populations and age groups'
    plt.figure(fig_disease)
    plt.hold(True)
    for title, ind in disease_indices:
        plt.plot(time_axis, disease_rat[ind,:], label = title)
    plt.legend()

    #TODO: Plot ratios of disease for different ages
    # Adult
    fig_adult = 'Average ratio of disease among adults'
    plt.figure(fig_adult)
    plt.hold(True)

    for title, ind in disease_indices:
        plt.plot(time_axis, disease_rat_adults[ind,:], label = title)

    plt.legend()

    # Young
    fig_young = 'Average ratio of disease amoung young'
    plt.figure(fig_young)
    plt.hold(True)

    for title, ind in disease_indices:
        plt.plot(time_axis, disease_rat_young[ind,:], label = title)

    plt.legend()

    # Infants
    fig_infants = 'Average ratio of disease among infants'
    plt.figure(fig_infants)
    plt.hold('True')

    for title, ind in disease_indices:
        plt.plot(time_axis, disease_rat_infants[ind,:], label = title)

    plt.legend()

    #TODO: Plot the disease incidence rate in different age groups in the same figure

    #TODO: Save the figures to a dedicated subdirectory
    dir_figs = dir_data + '/figures'
    try:
        os.makedirs(dir_figs)
    except OSError as exception:
        if exception.errno != errno.EEXIST:
            raise

    plt.figure(fig_ave)
    plt.savefig(dir_figs + '/plotted_aves.pdf')

    plt.figure(fig_disease)
    plt.savefig(dir_figs + '/plotted_disease.pdf')

    plt.figure(fig_adult)
    plt.savefig(dir_figs + '/plotted_disease_adults.pdf')

    plt.figure(fig_young)
    plt.savefig(dir_figs + '/plotted_disease_young.pdf')

    plt.figure(fig_infants)
    plt.savefig(dir_figs + '/plotted_disease_infants.pdf')


    if show_plots:
        plt.show()

def read_processed(constants, target_name, num_pops):
    return_data = np.zeros((num_pops, constants['NUM_DAYS']))
    with open(target_name + '.txt') as input_file:
        for k in xrange(num_pops):
            data_str = input_file.readline()
            data = np.array(data_str.split())
            return_data[k,:] = data

    return return_data


    return_data = np.zeros((datapts_number, constants['NUM_DAYS']), dtype = np.int)
    if not processed_data:
        file_name = target_name + str(sim_number) + '.txt'
    else:
        file_name = target_name + '.txt'
    with open(file_name) as data_file:
        for n in xrange(constants['NUM_DAYS']):
            data_string = data_file.readline()
            data = data_string.split()
            if not include_0:
                data = data[1:]
            data = np.array(data, dtype = np.float)
            for k in xrange(constants['NUMBER_OF_POPS']):
                return_data[:,n] += data[k*datapts_number:(k+1)*datapts_number]
    return return_data

if __name__ == '__main__':
    run(sys.argv[1:])
