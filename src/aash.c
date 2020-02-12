#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    char bin[PATH_MAX + 1];
    strcpy(bin, argv[1]);
    char cwd[PATH_MAX + 1];
    strcpy(cwd, argv[2]);
    chdir(cwd);

    char input[50], cmd[PATH_MAX + 1];

    while (1) {
        strcpy(cmd, bin);

        printf("%s > ", cwd);
        fflush(stdout);

        fgets(input, 50, stdin);
        sscanf(input, "%s", input);

        strcat(cmd, input);
        execl(cmd, cmd, bin, cwd, (char*) NULL);

        printf("aash: command not found: %s\n", input);
        fflush(stdout);
    }

    return 0;
}
