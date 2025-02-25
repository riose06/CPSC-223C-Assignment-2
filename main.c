/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: February 26 @ 11:59pm
 * CPSC Assignment 2 - String Search
*/

// Purpose:

#include <stdio.h>
#include <stdlib.h>

// Removes the built-in next line (\n) when using the fgets() function
void trim(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

int main () {
    printf("Welcome to String Search presented by Ethan Rios\n\n");

    FILE *file_ptr;
    char file_name[50];
    char file_data;
    printf("Please enter the name of a data file in the same directory where this program is running: ");












    return 0;
}


