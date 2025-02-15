#!/bin/bash

# Author: Ethan Rios
# CWID: 880071006
# Email: eirios@csu.fullerton.edu
# Due date: February 12, 2025 before 2:00am
# CPSC 223C Assingment 1

# PURPOSE: 

echo "Remove unnecessary files"
rm -f main.o main.out

echo "Compile main.c"
gcc -Wall -m64 -no-pie -o main.out main.c -std=c17 -fno-use-linker-plugin

# Make sure the executable has permission to execute
chmod u+x a2.sh
chmod u+x main.out

echo "Run the program Chemistry:"
./main.out

echo "The script file will terminate"