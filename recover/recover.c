#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Step 1: Check for correct command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Step 2: Open the memory card file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Step 3: Initialize buffer and necessary variables
    uint8_t buffer[512];
    int jpeg_count = 0;
    FILE *img = NULL;
    char filename[8]; // enough for "###.jpg\0"

    // Step 4: Read through the memory card file
    while (fread(buffer, sizeof(uint8_t), 512, card) == 512)
    {
        // Step 5: Check if the block is the beginning of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Step 6: If a JPEG file is already open, close it
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new JPEG filename and open a new file to write to
            sprintf(filename, "%03i.jpg", jpeg_count);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create JPEG file.\n");
                return 1;
            }
            jpeg_count++;
        }

        // Step 7: Write to the open JPEG file, if one is open
        if (img != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, img);
        }
    }

    // Step 8: Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
