#!/usr/bin/python
import sys

def print_usage():
  print("Usage: " + sys.argv[0] + "  --enable | --disable")
  sys.exit(0);

def replace_active(new_state):
  file_name = "/etc/audisp/plugins.d/sedispatch.conf"
  input = open(file_name, "r")
  lines = input.readlines()
  input.close()
  output = open(file_name, "w")
  for line in lines:
    splitted = line.split()
    if len(splitted):
      if splitted[0] == "active":
        line = "active = " + new_state + "\n"
    output.write(line)
  output.close()
    


argc = len(sys.argv)

if argc != 2:
  print_usage()
  
prog_arg = sys.argv[1]

if prog_arg == "--enable":
  replace_active("yes")
elif prog_arg == "--disable":
  replace_active("no")
else:
  print_usage()  