#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int main(int argc, char *argv[]) {
    char cwd[PATH_MAX + 1];
    strcpy(cwd, argv[1]);

    char input[200], cmd[40], args_string[160], *args[20];

    while (1) {
        memset(input, 0, sizeof(input));
        memset(cmd, 0, sizeof(cmd));
        memset(args_string, 0, sizeof(args_string));
        memset(args, 0, sizeof(args));

        printf("%s > ", cwd);
        fflush(stdout);

        fgets(input, 200, stdin);
        sscanf(input, "%s %[^\n]", cmd, args_string);
        args[0] = cmd;
        args[1] = cwd;
        args[2] = strtok(args_string, " ");
        int i = 2;
        while (args[i] != NULL) {
            args[++i] = strtok(NULL, " ");
        }

        execvp(cmd, args);

        if (cmd[0] != '\0') {
            printf("aash: command not found: %s\n", cmd);
            fflush(stdout);
        }
    }

    return 0;
}
