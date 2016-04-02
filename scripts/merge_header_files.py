#!/usr/bin/python
import sys, argparse, re, StringIO, logging


included_files={}
merged_file = StringIO.StringIO()
regex = re.compile('^\s*#include\s+"([^"]*)"')

def include_file(inc_file, include_c=False):
    logging.debug("Including file {}".format(inc_file))
    if inc_file in included_files:
        logging.debug("ERROR! Including '{}' more than once.".format(inc_file))

    included_files[inc_file] = True
    merged_file.write("\n/*{:*^80s}*/\n".format("Start of " + inc_file))
    with open(inc_file, "r") as f:
        for line in f:
            match = regex.match(line)
            if match is None:
                merged_file.write(line)
                continue

            new_inc_file = match.group(1)
            if new_inc_file in included_files:
                continue

            include_file(new_inc_file, include_c=include_c)
            if include_c:
                c_file = new_inc_file[:-1] + "c"
                try:
                    with open(c_file, "r") as f:
                        include_file(c_file, include_c=include_c)
                except:
                    logging.debug("Failed to find '{}'. Continuing".format(c_file))

    merged_file.write("\n/*{:*^80s}*/\n".format("End of " + inc_file))
    logging.debug("Finished file {}".format(inc_file))
            
        


def main():

    parser = argparse.ArgumentParser(description="Merges user includes like '#include \"test.h\"' starting from a file.")
    parser.add_argument("file", help="File to start in")
    parser.add_argument("--debug", default=False, action='store_true', help="verbose output of what the script is doing")
    parser.add_argument("--include-c", default=False, action='store_true', help="verbose output of what the script is doing")

    args = parser.parse_args()

    if args.debug:
        logging.basicConfig(format="%(levelname) -10s %(asctime)s %(module)s:%(lineno)s %(funcName)s %(message)s", level=logging.DEBUG)
    else:
        logging.basicConfig(level=logging.CRITICAL)  # no debug

    merged_file.write("/*This file was automatically merged that's why it might look weird.*/")
    include_file(args.file, include_c=args.include_c)

    print(merged_file.getvalue())

if __name__ == '__main__':
    main()

    
