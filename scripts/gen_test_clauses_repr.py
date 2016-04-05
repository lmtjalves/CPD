
import sys

lines = sys.stdin.readlines()

num_vars, num_clauses = lines[0].split()
num_vars = int(num_vars)

lines = lines[1:] # skip first line

var_clauses = { i: [] for i in range(num_vars + 1) }


print(" " * 4 + "{")
print(" " * 8 + "struct clauses_repr_clause crc;")
clause_num = 0
for line in lines:
    print(" " * 8 + "crc = clauses_repr_clause(cr, {});".format(clause_num))
    spl = line.split()
    print(" " * 8 + "UT_ASSERT_TRUE(crc.len == {});".format(len(spl) - 1))
    num_var = 0
    for var in spl[:-1]: # skip 0
        print(" " * 8 + "UT_ASSERT_TRUE(crc.first[{}] == {});".format(num_var, var))
        num_var += 1
        var = abs(int(var))
        var_clauses[var] += [clause_num]

    print("")
    clause_num += 1

print(" " * 4 + " }")

print(" " * 4 + "{")
print(" " * 8 + "struct  clauses_repr_clauses_of crco;")
for var in range(num_vars +1):
    print(" " * 8 + "crco = clauses_repr_clauses_of(cr, {});".format(var))
    print(" " * 8 + "UT_ASSERT_TRUE(crco.len == {});".format(len(var_clauses[var])))
    clause_count = 0
    for el in var_clauses[var]:
        print(" " * 8 + "UT_ASSERT_TRUE(crco.first[{}] == {});".format(clause_count, el))
        clause_count += 1
            
    print("")

print(" " * 4 + " }")
