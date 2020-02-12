#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char aash[PATH_MAX + 1];
    strcpy(aash, argv[1]);
    strcat(aash, "aash");
    char cwd[PATH_MAX + 1];
    strcpy(cwd, argv[2]);
    
    if (argc > 4) {
        printf("cd: too many arguments\n");
        fflush(stdout);
        execl(aash, aash, argv[1], cwd, (char *) NULL);
    }

    if (argv[3] == NULL) {
        chdir(getenv("HOME"));
        getcwd(cwd, sizeof(cwd)); 
    }
    else if (argv[3][0] == '/') {
        strcpy(cwd, argv[3]);
    }
    else {
        strcat(cwd, "/");
        strcat(cwd, argv[3]);
    }

    if (chdir(cwd) == -1) {
        printf("cd: not a directory: %s\n", argv[3]);
        fflush(stdout);
        execl(aash, aash, argv[1], argv[2], (char *) NULL);
    }
    else {
        execl(aash, aash, argv[1], cwd, (char *) NULL);
    }

    return 0;
}
