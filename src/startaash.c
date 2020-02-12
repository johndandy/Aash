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
   
    if (exec[0] == '/') {
        strcpy(bin, exec);
        strcat(bin, "bin/");
    }
    else {
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            strcpy(bin, cwd);
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

    char start_aash[PATH_MAX + 1];
    strcpy(start_aash, bin);
    strcat(start_aash, "aash");

    printf("%s", start_aash);

    execl(start_aash, start_aash, bin, cwd, (char*) NULL);

    return 0;
}
