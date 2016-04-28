import os, sys
from time import sleep
from subprocess import call
import re

# File for the output
output_file = open('all_metrics.csv', 'w+')

def run_and_store_results(filepath, num_slaves):
  # print filepath + str(num_slaves)
  error_file = str(num_slaves) + ".err"
  out_file   = str(num_slaves) + ".out"
  log_file   = str(num_slaves) + ".log"

  print " ".join([
    "condor_mpi",
    "-n " + str(num_slaves),
    "-o " + out_file,
    "-l " + log_file ,
    "-e " + error_file,
    "/mnt/cirrus/users/2/6/ist175926/main",
    "--debug",
    filepath])

  result = call([
    "condor_mpi",
    "-n " + str(num_slaves),
    "-o " + out_file,
    "-l " + log_file ,
    "-e " + error_file,
    "/mnt/cirrus/users/2/6/ist175926/main",
    "--debug",
    filepath])

  # While the file is empty
  while os.stat(out_file).st_size == 0:
    sleep(5)

  # Get the result from the .err file
  for line in reversed(open(error_file).readlines()):
    # Get the line with the metrics
    if "total_computation_time" in line:
      metrics = re.findall("\d+.\d+", line)
      break

  # Append to the begin the amount of slaves and the filepath
  metrics = [filepath, num_slaves] + metrics

  # Write the metrics to the output file
  output_file.write(",".join(metrics))
  output_file.flush()



def main():
  folder = os.path.dirname(os.path.abspath(__file__))
  for filename in os.listdir("."):
    if filename.endswith(".in"):
      filepath = folder + "/" + filename
      for num_slaves in range(10, 70, 10):
        run_and_store_results(filepath, num_slaves)


if __name__ == "__main__":
  main()
  output_file.close()