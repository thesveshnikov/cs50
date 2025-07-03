import sys

if len(sys.argv) != 3:
    sys.exit("Usage: python copy.py infile outfile")

infile = open(sys.argv[1])
outfile = open(sys.argv[2], "w")

contents = infile.read()
outfile.write(contents)

infile.close()
outfile.close()
