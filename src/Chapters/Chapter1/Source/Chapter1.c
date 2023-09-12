#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "../../../utils/Escape.h"
#include "../Prototypes/Chapter1.h"

bool escaped;

int startChapterOne()
{
    // Open the file for reading
    FILE *file = fopen("Chapter1.txt", "r");

    // Check if the file was successfully opened
    if (file == NULL)
    {
        perror("Error opening the file");
        return 1; // Return an error code
    }

    // Read and print the content of Chapter1 from the file
    char buffer[100]; // Assuming lines in the file are no longer than 100 characters

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // Print each line from the file character by character with a delay
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            putchar(buffer[i]);
            fflush(stdout);
            usleep(50000); // Adjust the delay as needed (in microseconds)
        }
    }

    printf("\n");

    // Close the file
    fclose(file);

    escape();
    return 0;
}
