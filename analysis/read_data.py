import numpy as np
import sys
import os.path
import matplotlib.pyplot as plt
import json

def read_data_multpops(data_file, constants):
    sim_data = np.zeros((constants['NUM_RUNS'], constants['NUM_DAYS'], constants['NUMBER_OF_POPS'], constants['NUM_POPS']), dtype = np.float)
    data_file.readline()
    for n in xrange(constants['NUM_RUNS']):
        for k in xrange(constants['NUM_DAYS']):
            data_string = data_file.readline()
            data = (data_string.split())[1:]
            sim_data[n,k,:,:] = np.reshape(data, (constants['NUMBER_OF_POPS'], constants['NUM_POPS']))
    return sim_data
