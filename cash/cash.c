#include <stdio.h>

int main(void)
{
    int cents;

    // Prompt the user for the amount of change owed
    do
    {
        printf("Change owed: ");
        if (scanf("%d", &cents) != 1) // Validate input is an integer
        {
            // Clear invalid input from buffer if scanf fails
            while (getchar() != '\n')
                ;
            cents = -1; // Set cents to an invalid value to repeat the loop
        }
    } while (cents < 0); // Keep prompting until a valid input is received

    // Calculate minimum coins needed
    int coins = 0;

    // Use the largest coin denominations first
    coins += cents / 25; // Quarters
    cents %= 25;

    coins += cents / 10; // Dimes
    cents %= 10;

    coins += cents / 5; // Nickels
    cents %= 5;

    coins += cents; // Pennies (remaining cents)

    // Output the result
    printf("%d\n", coins);

    return 0;
}
