#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    printf("\e[H\e[2J");
    fflush(stdout);

    char aash[PATH_MAX + 1];
    strcpy(aash, argv[1]);
    strcat(aash, "aash");
    execl(aash, aash, argv[1], argv[2], (char*) NULL);

    return 0;
}
