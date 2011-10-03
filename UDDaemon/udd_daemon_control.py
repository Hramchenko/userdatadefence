#!/usr/bin/python
import sys

def print_usage():
  print("Usage: " + sys.argv[0] + "  --enable | --disable")
  sys.exit(0);

file_name = "/etc/rc.local"


def read_config():
  input = open(file_name, "r")
  lines = input.readlines()
  input.close()
  return lines
  
def write_config(lines):  
  output = open(file_name, "w")
  for line in lines:
    output.write(line)
  output.close()

def process_lines(lines, pattern, new_str, append_str):
  for index in range(0, len(lines)):
    line = lines[index]
    if line.startswith(pattern):
      lines[index] = new_str + "\n"
      return lines
    elif  len(append_str): 
      if line.startswith(append_str):
        return lines
  if len(append_str):
    lines.append(append_str + "\n")
  return lines
   
argc = len(sys.argv)

if argc != 2:
  print_usage()
  
prog_arg = sys.argv[1]

lines = read_config()

comm = "/usr/sbin/UDDaemon &"

if prog_arg == "--enable":
  lines = process_lines(lines, "#" + comm, comm, comm) 
elif prog_arg == "--disable":
  lines = process_lines(lines, comm, "#" + comm, "") 
else:
  print_usage() 
  sys.exit(0)
  
write_config(lines)