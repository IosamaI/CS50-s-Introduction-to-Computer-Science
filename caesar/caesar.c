#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a string is numeric
bool is_numeric(string str);

int main(int argc, string argv[])
{
    // Check if exactly one command-line argument is provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key is numeric
    if (!is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the argument to an integer
    int key = atoi(argv[1]);

    // Ensure that the key is a non-negative integer
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Prompt the user for the plaintext
    string plaintext = get_string("plaintext: ");

    // Loop through each character of the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Encrypt uppercase letters
        if (isupper(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
    }

    // Output the ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

// Function to check if a string contains only digits
bool is_numeric(string str)
{
    for (int i = 0, len = strlen(str); i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return false; // If any character is not a digit, return false
        }
    }
    return true; // All characters are digits, so return true
}
