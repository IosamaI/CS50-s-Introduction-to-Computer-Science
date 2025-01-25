#include <stdio.h>

int main(void)
{
    // Prompt the user for the pyramid's height
    int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
    } while (height < 1 || height > 8); // Limit height between 1 and 8

    // Print the double pyramid
    for (int i = 1; i <= height; i++)
    {
        // Print spaces for alignment on the left side
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        // Print hashes for the left pyramid
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Print the gap between the two pyramids
        printf("  ");

        // Print hashes for the right pyramid
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}
