#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
    char *args[MAX_LINE/2 + 1]; /* command line arguments */
    int should_run = 1; /* flag to determine when to exit program */
    char command[MAX_LINE];

    while (should_run) {
        int i = 0;
        char *token;
        pid_t pid;
        
        printf("asim-shell> ");
        fflush(stdout);

        fgets(command, MAX_LINE, stdin);
        command[strcspn(command, "\n")] = '\0'; /* remove newline character from input */


        token = strtok(command, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

         pid = fork();
        if (pid == 0) {
            /* Child process */
            execvp(args[0], args);
            printf("Invalid command\n");
            exit(0);
        } else {
            /* Parent process */
            wait(NULL);
        }
    }

    return 0;
}
