#!/bin/python

import sys, argparse

parser = argparse.ArgumentParser(description='1 var problem gen')
parser.add_argument('num_vars', type=int)
parser.add_argument('--negate', action='store_true', default=False)

args = parser.parse_args()

num_vars = args.num_vars
negate = args.negate

print("{0} {0}".format(num_vars))
for i in range(1, num_vars+ 1):
    if negate:
        print("-{0} 0".format(i))
    else:
        print("{0} 0".format(i))
