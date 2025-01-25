#include <stdio.h>

int main(void)
{

    // Prompt the user for the pyramid's height
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    } while (height < 1 || height > 8); // Limit height between 1 and 8 for a standard CS50 requirement

    // Print the pyramid
    for (int i = 1; i <= height; i++)
    {
        // Print spaces for alignment
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Print hashes for the pyramid
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Move to the next line after each row
        printf("\n");
    }
    // next

    return 0;
}
