#include <stdio.h>
#include <string.h>

int main(void) {
    char s[] = "This is the way";
    char d[] = " ";

    char *portion1 = strtok(s, d);
    printf("%s\n", portion1);
}