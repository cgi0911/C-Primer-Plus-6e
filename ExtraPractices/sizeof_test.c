#include <stdio.h>
#include <limits.h>

int main () {
    int a;
    unsigned int b;
    short int c;
    unsigned short int d;
    char e;

    printf ("%lu %lu %lu %lu %lu\n",
            sizeof (a), sizeof (b), sizeof (c), sizeof (d), sizeof (e));

    printf ("INT_MAX = %d\n", INT_MAX);
    printf ("INT_MIN = %d\n", INT_MIN);
    printf ("UINT_MAX = %d\n", UINT_MAX);
    printf ("LONG_MAX = %ld\n", LONG_MAX);
    printf ("LONG_MIN = %ld\n", LONG_MIN);

    return 0;
}
