#!/bin/python

import sys, argparse

parser = argparse.ArgumentParser(description='1 var problem gen')
parser.add_argument('num_vars', type=int)

args = parser.parse_args()

num_vars = args.num_vars

print("{0} {1}".format(num_vars, 4 * (num_vars - 1)))
for i in range(1, num_vars):
    print("{0} {1} 0".format(i, i+1))
    print("-{0} {1} 0".format(i, i+1))
    print("{0} -{1} 0".format(i, i+1))
    print("-{0} -{1} 0".format(i, i+1))
