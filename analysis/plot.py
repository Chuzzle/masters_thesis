import numpy as np
import sys
import os.path
import matplotlib.pyplot as plt
import json

def main(argv):
    file_loc = os.path.dirname(os.path.relpath(__file__))
    with open(file_loc + '/../constants_runspec.json') as constants_file:
        constants = json.load(constants_file)
    data_file = open(file_loc + '/../data/' + argv[0])
    data = read_file(data_file, constants)

    time = range(0, constants['NUM_DAYS'])
    fig = plt.figure(1)
    for n in xrange(constants['NUM_RUNS']):
        plt.plot(time, data[n, :, constants['ADULT_SUSC']], 'r', time, data[n, :, constants['ADULT_SICK']], 'g', time, data[n, :, constants['ADULT_IMMUNE']], 'b', time, data[n, :, constants['ADULT_CARRIERS']], 'k')
    plt.legend(['Susceptible adults', 'Sick adults', 'Immune adults', 'Adult carriers'])

    stats_array = np.zeros((constants['NUM_RUNS'], 3), dtype=np.float_)
    np.seterr(divide = 'ignore')
    for n in xrange(constants['NUM_RUNS']):
        pop_sum = np.sum(data[n, :, :],1)
        rate_carriers = np.nanmean(np.divide(data[n, :, constants['ADULT_CARRIERS']], pop_sum))
        ccr = np.nanmean(np.divide(data[n, :, constants['ADULT_SICK']], data[n, :, constants['ADULT_CARRIERS']]))
        max_sick = np.max(data[n,:,constants['ADULT_SICK']])
        stats_array[n,:] = [rate_carriers, ccr, max_sick]
    print '{0:22}|| {1:18} || {2:18} ||'.format('   Rate of carriers', 'Case-Carrier ratio', 'Top notation of sick')
    print np.array2string(stats_array, separator= '||', formatter={'float_kind':lambda x: "%20f" % x})
    plt.show()


def read_file(data_file, constants):
    # Numpy multidimensional arrays are indexed as array[depth, rows, cols]
    sim_data = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUM_POPS']), dtype = np.float_)
    for k in xrange(constants['NUM_RUNS']):
        for n in xrange(constants['NUM_DAYS']):
            data_string = data_file.readline()
            sim_data[k,n,:] = (data_string.split())[1:]
    return sim_data


if __name__ == '__main__':
    main(sys.argv[1:])
