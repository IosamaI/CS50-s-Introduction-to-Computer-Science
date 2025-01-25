#include <stdio.h>

int main(void)
{
    char name[50]; // Array to store the user's name

    // Prompt the user for their name
    printf("What's your name? ");
    scanf("%49s", name); // Use %49s to avoid overflow (49 characters + null terminator)

    // Greet the user
    printf("hello, %s\n", name);

    return 0;
}
