#!/bin/bash

# Author: Ethan Rios
# CWID: 880071006
# Email: eirios@csu.fullerton.edu
# Due: February 26 @ 11:59pm
# CPSC 223C Assignment 2 - String Search

# PURPOSE: Program is intended to allow the user to choose an available text file. If they 
#          make a spelling error or the file is not found, the question will be repeated
#          and the user may try again. The user then enters one or more characters, which
#          the program takes and finds the number of times the string appears in the text
#          file, as well as the index / indices the start of the string is found at. 

echo "Remove unnecessary files"
rm -f main.o main.out

echo "Compile main.c"
gcc -Wall -m64 -no-pie -o main.out main.c -std=c17 -fno-use-linker-plugin

# Make sure the executable has permission to execute
chmod u+x a2.sh
chmod u+x main.out

echo "Run the program String Search:"
./main.out

echo "The script file will terminate"
