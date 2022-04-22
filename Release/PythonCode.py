import re
import string

def frequency_of_each_item(read_file):
    dictionary = create_produce_dict(read_file) # create data dictionary from file
    print_buffer = ""
    for k, v in dictionary.items():
        print_buffer += k + " " + str(v) + "\n"
    print(print_buffer) # print the data dictionary in full
    return 1

def frequency_of_specific_item(parameters):
    tokens = parameters.split()
    read_file = tokens[0]
    produce_item = tokens[1]
    dictionary = create_produce_dict(read_file) # create data dictionary from file
    for k, v in dictionary.items():
        if (k == produce_item):
            return v # if found return the items purchase frequency
    return 0 # if not found return 0

def histogram_preperation(read_file):
    produce_dict = create_produce_dict(read_file) # create data dictionary from file
    write_dict_to_file(produce_dict, "frequency.dat") # output data dictionary to a file
    return 1

def create_produce_dict(read_file):
    produce_dict = {}
    with open(read_file, "r") as in_file:
        lines = in_file.readlines()
    for index, value in enumerate(lines):
        stripped = value[:-1] # strip off the newline character
        if stripped in produce_dict:
            produce_dict[stripped] += 1 # increment count if already in the data dictionary
        else:
            produce_dict[stripped] = 1 # if not found in the data dictionary, add it and set count to 1
    return produce_dict

def write_dict_to_file(dictionary, write_file):
     with open(write_file, "w") as output_file:
        for k, v in dictionary.items():
            output_file.write(k + " " + str(v) + "\n") # output each line of the data dictionary to the file