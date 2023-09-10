#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[] = "input.txt";   
    char outputFileName[] = "output.txt"; 

    // Open the input file
    inputFile = fopen("ab.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file
    outputFile = fopen("abc.text", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    int searchValue;
    printf("Enter the value to search for: ");
    scanf("%d", &searchValue);

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Read lines from input file and search for the value
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        int value;
        if (sscanf(line, "%d", &value) == 1) {
            if (value == searchValue) {
                found = 1;
                fprintf(outputFile, "Value %d found in the input file.\n", searchValue);
                break;
            }
        }
    }

    if (!found) {
        fprintf(outputFile, "Value %d not found in the input file.\n", searchValue);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Search result has been written to %s\n", outputFileName);

    return 0;
}
