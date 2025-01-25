#include <stdio.h>

int main(void)
{
    typedef char *string;
    int n = 80;
    int *p = &n;
    printf("%i\n", *p);

    string s = "hi";
    printf("%c\n", *s);
}