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

    # Population-wise statistics over the age distribution (later)
