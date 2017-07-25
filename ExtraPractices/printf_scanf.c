#include <stdio.h>

int main (int argc, char *argv[]) {
    int a, b;
    printf ("Input two integers: ");
    scanf ("%d %d", &a, &b);

    printf ("Your inputs: %d, %d\n", a, b);

    char c[100] = "Hello world!";

    printf ("%s\n", c);

    return 0;
}
