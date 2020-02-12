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

    char input[200], cmd_short[40], cmd[PATH_MAX + 1], args_string[160], *args[20];

    while (1) {
        memset(input, 0, sizeof(input));
        memset(cmd_short, 0, sizeof(cmd_short));
        memset(cmd, 0, sizeof(cmd));
        memset(args_string, 0, sizeof(args_string));
        memset(args, 0, sizeof(args));
        strcpy(cmd, bin);

        printf("%s > ", cwd);
        fflush(stdout);

        fgets(input, 200, stdin);
        sscanf(input, "%s %[^\n]", cmd_short, args_string);
        strcat(cmd, cmd_short);
        args[0] = cmd;
        args[1] = bin;
        args[2] = cwd;
        args[3] = strtok(args_string, " ");
        int i = 3;
        while (args[i] != NULL) {
            args[++i] = strtok(NULL, " ");
        }

        execv(cmd, args);

        printf("aash: command not found: %s\n", cmd_short);
        fflush(stdout);
    }

    return 0;
}
