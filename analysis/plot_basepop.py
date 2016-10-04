from __future__ import division
import numpy as np
import sys
import os.path
import matplotlib.pyplot as plt
import json
import read_data

def main(argv):
    file_loc = os.path.dirname(os.path.relpath(__file__))
    with open(file_loc + '/../constants_runspec.json') as constants_file:
        constants = json.load(constants_file)
    data_file = open(file_loc + '/../data/' + argv[0])
    data = read_data.read_data_multpops(data_file, constants)

    # Data now holds data as [run order][day order][population][sub population]


    sum_pop = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS']))

    rate_adult = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS']))
    rate_young = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS']))
    rate_infant = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS']))

    for k in xrange(constants['NUM_RUNS']):
        for n in xrange(constants['NUM_DAYS']):
                sum_pop[k][n] += data[k][n][0][constants['ADULT_SUSC']] + data[k][n][0][constants['INFANTS_SUSC']] + data[k][n][0][constants['YOUNG_SUSC']]
                rate_adult[k][n] = data[k][n][0][constants['ADULT_SUSC']]/sum_pop[k][n]
                rate_young[k][n] = data[k][n][0][constants['YOUNG_SUSC']] / sum_pop[k][n]
                rate_infant[k][n] = data[k][n][0][constants['INFANTS_SUSC']] / sum_pop[k][n]

    time = range(0, constants['NUM_DAYS'])
    for n in xrange(constants['NUM_RUNS']):
        plt.figure('Total pop')
        plt.plot(time, sum_pop[n][:])
        plt.figure('Ratio adults')
        plt.plot(time, rate_adult[n][:])
        plt.figure('Ratio young')
        plt.plot(time, rate_young[n][:])
        plt.figure('Ratio infants')
        plt.plot(time, rate_infant[n][:])

    plt.figure('Total pop')
    plt.title('Total population, all age groups')
    plt.ylim([5000,15000])

    plt.figure('Ratio adults')
    plt.title('Ratio of adults in the population')
    plt.ylim([0,1])

    plt.figure('Ratio young')
    plt.title('Ratio of young in the population')
    plt.ylim([0,1])

    plt.figure('Ratio infants')
    plt.title('Ratio of infants in the population')
    plt.ylim([0,1])
    
    plt.show()

if __name__ == '__main__':
    main(sys.argv[1:])
