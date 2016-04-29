import os, sys
from time import sleep
from subprocess import call
import re

# File for the output
thread_metrics = open('thread_metrics.csv', 'w+')
maxsat_metrics = open('maxsat_metrics.csv', 'w+')


def run_and_store_results(ex_name, filepath, num_slaves, num_threads_per_slave):
  # print filepath + str(num_slaves)
  error_file = ex_name + "_" + str(num_slaves) + ".err"
  out_file   = ex_name + "_" + str(num_slaves) + ".out"
  log_file   = ex_name + "_" + str(num_slaves) + ".log"

  # Set the amount of threads
  os.environ['OMP_NUM_THREADS'] = num_threads_per_slave

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
    sleep(1)

  # Get the result from the .err file
  for line in open(error_file).readlines():

    # Get the metrics for the threads
    if "total_computation_time" in line:
      metrics = re.findall("\d+.\d+", line)

      # Append to the begin the amount of slaves and the filepath
      metrics = [filepath, str(num_slaves)] + metrics

      # Write the metrics to the output file
      thread_metrics.write(",".join(metrics) + "\n")
      thread_metrics.flush()

    # Maxsata total time from master
    elif "maxsat time" in line:
      metrics = re.findall("\d+.\d+", line)
      # Append to the begin the amount of slaves and the filepath
      metrics = [filepath, str(num_slaves)] + metrics

      # Write the metrics to the output file
      maxsat_metrics.write(",".join(metrics) + "\n")
      maxsat_metrics.flush()


def main():
  folder = os.path.dirname(os.path.abspath(__file__))
  for filename in os.listdir("."):
    if filename.endswith(".in"):
      filepath = folder + "/" + filename

      for num_cores in [2, 4, 8, 16, 32, 64, 128, 256]:
        if num_cores <= 4:
          run_and_store_results(filename, filepath, 1, num_cores)
        else:
          # Simplification, all the others are multiples of 4
          run_and_store_results(filename, filepath, num_cores/4, 4)


if __name__ == "__main__":
  main()
  thread_metrics.close()
  maxsat_metrics.close()
