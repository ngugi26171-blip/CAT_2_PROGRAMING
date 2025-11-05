//A a program requesting the users input and calculates the net pay 
/*
Name: George Maina Ngugi
RegNo; CT100/G/26171/25
Description; a program  calculating net pay after obtaining user's input
*/ 
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeInputFile();
void processNumbers();
void displayFiles();

int main() {
    writeInputFile();
    processNumbers();
    displayFiles();
    return 0;
}

//  Function to prompt user for 10 integers and store them in "input.txt"
void writeInputFile() {
    FILE *fptr;
    int num, i;

    fptr = fopen("input.txt", "w");
    if (fptr == NULL) {
        printf("Error opening input.txt for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fptr, "%d\n", num);
    }

    fclose(fptr);
    printf("✅ Numbers saved to input.txt successfully.\n\n");
}

// Function to read integers, compute sum & average, and save results to "output.txt"
void processNumbers() {
    FILE *fin, *fout;
    int num, sum = 0, count = 0;
    float avg;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for reading.\n");
        exit(1);
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(fin);
        exit(1);
    }

    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("No data found in input.txt!\n");
        fclose(fin);
        fclose(fout);
        exit(1);
    }

    avg = (float)sum / count;

    fprintf(fout, "Sum: %d\nAverage: %.2f\n", sum, avg);

    fclose(fin);
    fclose(fout);

    printf("✅ Results saved to output.txt (Sum and Average calculated).\n\n");
}

//  Function to display contents of both files in a formatted manner
void displayFiles() {
    FILE *fin, *fout;
    char ch;

    printf("----- Contents of input.txt -----\n");
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error opening input.txt for display.\n");
        exit(1);
    }

    while ((ch = fgetc(fin)) != EOF)
        putchar(ch);
    fclose(fin);

    printf("\n----- Contents of output.txt -----\n");
    fout = fopen("output.txt", "r");
    if (fout == NULL) {
        printf("Error opening output.txt for display.\n");
        exit(1);
    }

    while ((ch = fgetc(fout)) != EOF)
        putchar(ch);
    fclose(fout);

    printf("\n---------------------------------\n");
}
