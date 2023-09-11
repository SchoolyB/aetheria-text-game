#include <stdio.h>
#include <unistd.h> // for usleep



int startChapter() {
    // Open the file for reading
    FILE *file = fopen("Chapter1.txt", "r");
    // Check if the file was successfully opened
    if (file == NULL) {
        perror("Error opening the file");
        return 1; // Exit the function with an error code
    }
    // Read and print the content of chapter1 from the file
    char buffer[200]; // Assuming lines in the file are no longer than 100 characters

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Print each line from the file character by character with a delay
        for (int i = 0; buffer[i] != '\0'; i++) {
            putchar(buffer[i]);
            fflush(stdout);
            usleep(45000);
        }
    }
    printf("\n");
    // Close the file
    fclose(file);
    return 0;
}

int getEscapeDecision(){
// make a function that takes offers the player 2 options run or fight
// if they choose run they get a random number between 1 and 10
// if the number is greater than 5 they escape
// if the number is less than 5 they get caught and have to fight
// if they choose fight they have to fight
// if they win they escape
// if the lose they still escape but they are injured
}