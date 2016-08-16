import numpy as np
import sys
import os.path
import matplotlib.pyplot as plt
import json

def main(argv):
    file_loc = os.path.dirname(os.path.relpath(__file__))
    with open(file_loc + '../constants_runspec.json') as constants_file:
        constants = json.load(constants_file)
    data_file = open(file_loc + '../data/' + argv[0])
    data = read_file(data_file, constants)
    print data


def read_file(data_file, constants):
    # Numpy multidimensional arrays are indexed as array[depth, rows, cols]
    sim_data = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUM_POPS']), dtype = np.int)
    for k in xrange(constants['NUM_RUNS']):
        for n in xrange(constants['NUM_DAYS']):
            data_string = data_file.readline()
            sim_data[k,n,:] = (data_string.split())[1:]
    return sim_data



if __name__ == '__main__':
    main(sys.argv[1:])
