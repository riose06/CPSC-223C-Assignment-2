/*
 * Author: Ethan Rios
 * CWID: 880071006
 * Email: eirios@csu.fullerton.edu
 * Due: February 26 @ 11:59pm
 * CPSC 223C Assignment 2 - String Search
 * Last updated: February 26 @ 4:53pm
 */

// PURPOSE: Program is intended to allow the user to choose an available text file. If they 
//          make a spelling error or the file is not found, the question will be repeated
//          and the user may try again. The user then enters one or more characters, which
//          the program takes and finds the number of times the string appears in the text
//          file, as well as the index / indices the start of the string is found at.

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
        printf("Please enter the name of a text file in the same directory where this program is running: ");
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
        printf("\nThank you! The size of the file you entered has %d bytes.", i);
        printf("\nThe data from the file was copied into a string array in the program.");
        printf("\nHere is the data that was stored in an array of chars:\n\n");
        printf("%s", file_data);
        
        // User enters a string to search for in the file
        char search[20];
        printf("\n\nPlease enter a search string: ");
        fgets(search, 19, stdin);
        trim(search);

        char* data_ptr = file_data;       // Instantiate a pointer to file data
        int found[50];                    // Create an array to hold indices where the string was found
        int j = 0;                        // Create int to hold the number of times the string was found

        // If search string is not found, else continue
        if (strstr(file_data, search) == NULL) 
        {
            printf("\n\nSorry, the search string you entered was not found.");
        }
        else 
        {
            while ((data_ptr = strstr(data_ptr, search)) != NULL)    // Places indices where search is found into array
            {
                found[j] = data_ptr - file_data;
                data_ptr++;
                j++;
            }

            // Prints how many times search was found and at which indices it was found
            printf("\n\nThank you! \"%s\" was found %d times, located at these positions counting from the start of the array:\n", search, j);
            for (int i = 0; i < j; i++)
            {
                printf("%d ", found[i]);
            }
        }

        
        // Conclusion
        printf("\n\nI hope that you enjoyed using string search! Come back at any time.");
        printf("\nHave a great day!!\n\n");
        printf("==================================== End of execution ====================================\n\n");
    }
    return 0;
}