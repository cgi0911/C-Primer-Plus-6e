#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char name[100];

    printf ("What is your name? ");
    gets (name);

    printf ("Your name is %s.\n", name);
    printf ("The length of your name is %lu.\n", strlen(name));
    return 0;
}
