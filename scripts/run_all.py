import os, sys
from time import sleep
from subprocess import call,Popen
import re

# File for the output
thread_metrics = open('thread_metrics.csv', 'a')
maxsat_metrics = open('maxsat_metrics.csv', 'a')

# Configurations
num_threads=4
slaves=[1,2,4,8,16,32,64]
tests=[1,2,3]
# 1 if mpi or mpi and omp, 0 if serial (just to add a master or not)
parallel=1



def run_and_store_results(ex_name, filepath, num_slaves, num_threads_per_slave, num_iteration):
  # print filepath + str(num_slaves)
  error_file = ex_name + "_" + str(num_slaves) + "_" + str(num_iteration) + ".err"
  out_file   = ex_name + "_" + str(num_slaves) + "_" + str(num_iteration) + ".out"
  log_file   = ex_name + "_" + str(num_slaves) + "_" + str(num_iteration) + ".log"
  

  if (not os.path.isfile(error_file) or os.stat(out_file).st_size == 0):
    result = Popen([
        "/mnt/cirrus/users/2/6/ist175926/condor_mpi",
        "-n " + str(num_slaves + parallel),
        "-o " + out_file,
        "-l " + log_file,
        "-e " + error_file,
        "/mnt/cirrus/users/2/6/ist175926/main",
        "--debug",
        filepath]).wait()

    # While the file is empty
    while os.stat(out_file).st_size == 0:
        sleep(1)

    # Get the result from the .err file
    for line in open(error_file).readlines():

        # Get the metrics for the threads
        if "total_computation_time" in line:
            metrics = re.findall("\d+.\d+", line)

            # Append to the begin the amount of slaves and the filepath
            metrics = [filepath, str(num_iteration), str(num_slaves), str(num_threads_per_slave)] + metrics

            # Write the metrics to the output file
            thread_metrics.write(",".join(metrics) + "\n")
            thread_metrics.flush()

        # Maxsata total time from master
        elif "maxsat time" in line:
            metrics = re.findall("\d+.\d+", line)
            # Append to the begin the amount of slaves and the filepath
            metrics = [filepath, str(num_iteration), str(num_slaves), str(num_threads_per_slave)] + metrics

            # Write the metrics to the output file
            maxsat_metrics.write(",".join(metrics) + "\n")
            maxsat_metrics.flush()


def main():
  folder = os.path.dirname(os.path.abspath(__file__))
  for filename in os.listdir("."):
    if filename.endswith(".in"):
      filepath = folder + "/" + filename

      for num_cores in slaves:
        for it in tests:
            run_and_store_results(filename, filepath, num_cores, num_threads, it)


if __name__ == "__main__":
  main()
  thread_metrics.close()
  maxsat_metrics.close()
