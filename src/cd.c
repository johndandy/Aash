#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char cwd[PATH_MAX + 1];
    strcpy(cwd, argv[1]);
    
    if (argc > 3) {
        printf("cd: too many arguments\n");
        fflush(stdout);
        execlp("aash", "aash", argv[1], NULL);
    }

    if (argv[2] == NULL) {
        chdir(getenv("HOME"));
        getcwd(cwd, sizeof(cwd)); 
    }
    else if (argv[2][0] == '/') {
        strcpy(cwd, argv[2]);
    }
    else {
        strcat(cwd, "/");
        strcat(cwd, argv[2]);
    }

    if (chdir(cwd) == -1) {
        printf("cd: not a directory: %s\n", argv[2]);
        fflush(stdout);
        execlp("aash", "aash", argv[1], NULL);
    }
    else {
        execlp("aash", "aash", cwd, NULL);
    }

    return 0;
}
