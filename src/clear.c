#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("\e[H\e[2J");
    fflush(stdout);

    execlp("aash", "aash", argv[1], NULL);

    return 0;
}
