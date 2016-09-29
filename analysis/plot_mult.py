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
    # Population-wise statistics over the age distribution (later)

    sum_sick = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUMBER_OF_POPS']))
    sum_carriers = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUMBER_OF_POPS']))
    sum_immune = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUMBER_OF_POPS']))
    sum_susc = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUMBER_OF_POPS']))

    for k in xrange(constants['NUM_RUNS']):
        for n in xrange(constants['NUM_DAYS']):
            for j in xrange(constants['NUMBER_OF_POPS']):
                sum_sick[k][n][j] += data[k][n][j][constants['ADULT_SICK']] + data[k][n][j][constants['INFANTS_SICK']] + data[k][n][j][constants['YOUNG_SICK']]

                sum_carriers[k][n][j] += data[k][n][j][constants['ADULT_CARRIERS']] + data[k][n][j][constants['INFANTS_CARRIERS']] + data[k][n][j][constants['YOUNG_CARRIERS']]

                sum_immune[k][n][j] += data[k][n][j][constants['ADULT_IMMUNE']] + data[k][n][j][constants['INFANTS_IMMUNE']] + data[k][n][j][constants['YOUNG_IMMUNE']]

                sum_susc[k][n][j] += data[k][n][j][constants['ADULT_SUSC']] + data[k][n][j][constants['INFANTS_SUSC']] + data[k][n][j][constants['YOUNG_SUSC']]

    #Plot the sick from all runs in one fig and so on
    time = range(0, constants['NUM_DAYS'])
    for n in xrange(constants['NUM_RUNS']):
        plt.figure('Sick')
        plt.plot(time, sum_sick[n,:,0], time, sum_sick[n,:,1])
        plt.figure('Carriers')
        plt.plot(time, sum_carriers[n,:,0], time, sum_carriers[n,:,1])
        plt.figure('Immune')
        plt.plot(time, sum_immune[n,:,0], time, sum_immune[n,:,1])
        plt.figure('Susceptibles')
        plt.plot(time, sum_susc[n,:,0], time, sum_susc[n,:,1])

    # plot the average from all runs.
    avg_sick = np.mean(sum_sick, (0,2))
    avg_carriers = np.mean(sum_carriers, (0,2))
    avg_immune = np.mean(sum_immune, (0,2))
    avg_susc = np.mean(sum_susc, (0, 2))

    fig = plt.figure('Averages')
    plt.subplot(2,2,1)
    plt.plot(time, avg_sick)
    plt.subplot(2, 2, 2)
    plt.plot(time, avg_carriers)
    plt.subplot(2, 2, 3)
    plt.plot(time, avg_immune)
    plt.subplot(2, 2, 4)
    plt.plot(time, avg_susc)

    plt.show()

if __name__ == '__main__':
    main(sys.argv[1:])
