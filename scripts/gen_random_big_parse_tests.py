#!/bin/python

import sys, argparse, random


def test_rand(t):
    if t == "both":
        return random.randint(0,1)
    elif t == "positive":
        return 0
    else:
        return 1

parser = argparse.ArgumentParser(description="problem gen. clauses might be duplicate and have repeated variables")
parser.add_argument('min_num_vars', type=int)
parser.add_argument('max_num_vars', type=int)
parser.add_argument('min_clauses', type=int)
parser.add_argument('max_clauses', type=int)
parser.add_argument('min_vars_per_clause', type=int)
parser.add_argument('max_vars_per_clause', type=int)
parser.add_argument('--type', default="both", choices=["positive", "negative"])

args = parser.parse_args()

num_vars = random.randint(args.min_num_vars, args.max_num_vars)
num_clauses = random.randint(args.min_clauses, args.max_clauses)

print("{0} {1}".format(num_vars, num_clauses))
for i in range(1, num_clauses + 1):
    num_clause_vars = random.randint(args.min_vars_per_clause, args.max_vars_per_clause)
    
    print(" ".join([str(v) if test_rand(args.type) == 0 else str(-v) for v in [ random.randint(1, num_vars) for _ in range(num_clause_vars)]])+ " 0")
