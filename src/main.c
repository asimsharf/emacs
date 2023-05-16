// #include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{

    // Check if run program interactive on not
    if (argc < 2)
    {

        size_t bufferSize = 1024;
        char *buffer = malloc(sizeof(buffer) * bufferSize);
        char **tokens = malloc(sizeof(char *) * bufferSize);
        char *token;
        int position = 0;

        struct stat file_stat;

        (void)argc;

        // for showing the promts and loop
        while (1)
        {
            // print prompts
            printf("~$ ");
            // read user inputs
            getline(&buffer, &bufferSize, stdin);
            // split user inputs by delm
            token = strtok(buffer, " \n");
            while (token)
            {
                tokens[position] = token;
                position++;
                token = strtok(NULL, " \n");
            }

            // check if tokens array is not empty
            if (tokens)
            {
                // grap the command ex: ( ls, pwd, ...)
                char *cmd = malloc(strlen(tokens[0]));
                strcpy(cmd, tokens[0]);
                int cmd_len = strlen(tokens[0]);

                // get a list of paths
                char *path = getenv("PATH");
                if (path)
                {
                    char *copy_path = strdup(path);
                    char *token_path = strtok(copy_path, ":");
                    int token_path_len = strlen(token_path);

                    while (token_path)
                    {

                        char *file_path = malloc(cmd_len + token_path_len + 2);
                        strcpy(file_path, token_path);
                        strcat(file_path, "/");
                        strcat(file_path, cmd);
                        strcat(file_path, "\0");

                        if (stat(file_path, &file_stat) == 0)
                        {

                            // Create the Process
                            pid_t pid;
                            pid = fork();
                            if (pid == -1)
                            {
                                return -1;
                            }
                            if (pid == 0)
                            {
                                // Execute the command

                                if (execve(file_path, tokens, envp) == 0)
                                {
                                    free(copy_path);
                                    free(file_path);
                                    free(cmd);
                                    exit(0);
                                }
                                else
                                {
                                    printf("##################");
                                    exit(0);
                                }
                                exit(0);
                            }
                            else
                            {
                                wait(NULL);
                                // exit(0);
                            }
                        }
                        else
                        {
                            free(file_path);
                            token_path = strtok(NULL, ":");
                        }
                    }
                    free(token_path);
                }
                else
                {
                    printf("No path\n");
                }
            }
            else
            {
                printf("No token\n");
            }
            free(token);
        }

        free(buffer);
        free(tokens);
    }
    else
    {
        // non interactive mode
        char **tokens = malloc(sizeof(char *) * argc);
        int i = 0;
        while (argv[i])
        {
            tokens[i] = argv[i + 1];
            i++;
        }

        if (execve(tokens[0], tokens, envp) == 0)
        {
            free(tokens);
        }
    }

    return 0;
}