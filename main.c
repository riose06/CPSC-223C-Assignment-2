/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: February 26 @ 11:59pm
 * CPSC 223C Assignment 2 - String Search
*/

// PURPOSE: 

// "a2.sh" in the terminal will run the bash program!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Removes the built-in next line (\n) when using the fgets() function
void trim(char *s) {
    s[strcspn(s, "\n")] = '\0';
}

int main () {
    printf("\nWelcome to String Search presented by Ethan Rios!\n\n");

    FILE* file_ptr;        // Internal name of the text file
    char file_name[50];    // External name of the text file
    char* file_data;       // Array of char from the text file

    // Gives user multiple chances to enter a text file in case of a typing mistake
    do 
    {
        printf("Please enter the name of a data file in the same directory where this program is running: ");
        fgets(file_name, 49, stdin);
        trim(file_name);

    }
    while ((file_ptr = fopen(file_name, "r")) == NULL);

    if ((file_ptr = fopen(file_name, "r")) != NULL) 
    {
        // Set file_ptr to the end of the text file
        // Use malloc to copy the size of the text file to file_data (create space)
        fseek(file_ptr, 0, SEEK_END);
        file_data = (char*) malloc ((ftell(file_ptr) + 1) * sizeof(char));

        // Set file_ptr to the start of the text file
        rewind(file_ptr);

        // Loop through the text file, copying each character
        // from file_ptr into the array file_data
        char c;
        int i;
        for (i = 0; (c = fgetc(file_ptr)) != EOF; i++) 
        {
            file_data[i] = c;
        }

        // Print the number of bytes and contents of the file to the user
        printf("Thank you! The size of the file you entered has %d bytes.", i);
        printf("\nThe data from the file was copied into a string array in the program.");
        printf("\nHere is the data that was stored in an array of chars:\n\n");
        printf("%s", file_data);
        
        // User enters a string to search for in the file
        char search[20];
        printf("\n\nPlease enter a search string: ");
        fgets(search, 19, stdin);
        trim(search);

        char* data_ptr = file_data;
        int found[50];
        int j = 0;
        while ((data_ptr = strstr(data_ptr, search)) != NULL) 
        {
            found[j] = data_ptr - file_data;
            data_ptr++;
            j++;
        }

        printf("\n\nThank you! \"%s\" was found at these positions counting from the start of the array:\n", search);
        for (int i = 0; i < j; i++)
        {
            printf("%d ", found[i]);
        }
        

        printf("\n\nI hope that you enjoyed using string search! Come back at any time.");
        printf("\nHave a great day!!\n\n");
        printf("==================================== End of execution ====================================\n\n");
    }
    return 0;
}


