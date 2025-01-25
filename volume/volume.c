#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// Define types for readability
typedef uint8_t BYTE;

// Create a buffer for a single sample
int16_t buffer;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input); // Close input file before returning
        return 1;
    }

    // Convert the factor argument to a float
    float factor = atof(argv[3]);

    // Copy header from input file to output file
    BYTE header[HEADER_SIZE];
    if (fread(header, sizeof(BYTE), HEADER_SIZE, input) != HEADER_SIZE)
    {
        printf("Could not read the header.\n");
        fclose(input);
        fclose(output);
        return 1;
    }
    fwrite(header, sizeof(BYTE), HEADER_SIZE, output);

    // Read samples from input file, adjust volume, and write updated samples to output file
    while (fread(&buffer, sizeof(int16_t), 1, input) == 1)
    {
        // Update volume of sample by multiplying with factor
        buffer = (int16_t)(buffer * factor);

        // Write updated sample to output file
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}
