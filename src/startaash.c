#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char exec[PATH_MAX + 1]; 
    strcpy(exec, argv[0]);
    exec[strlen(argv[0]) - 9] = '\0';
    
    char cwd[PATH_MAX + 1];
    char bin[PATH_MAX + 1];
    char home[PATH_MAX + 1];
    strcpy(bin, "PATH=");
    strcpy(home, "HOME=");
    strcat(home, getenv("HOME"));
   
    if (exec[0] == '/') {
        strcat(bin, exec);
        strcat(bin, "bin/");
    }
    else {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            strcat(bin, cwd);
            strcat(bin, "/");
            strcat(bin, exec);
            strcat(bin, "bin/");
        }
    }

    chdir(getenv("HOME"));

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("\033[H\033[2JWelcome to Aash!\n");
    }
    else {
        printf("Something went wrong, sorry!\n");
        return 0;
    }

    char aash[PATH_MAX + 1];
    strcpy(aash, bin + 5);
    strcat(aash, "aash");

    char *args[] = {aash, cwd, NULL};
    char *env[] = {bin, home, NULL};

    execve(aash, args, env);

    return 0;
}
