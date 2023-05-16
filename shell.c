#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

void drow_prompt()
{
    char *user = getenv("USER");

    char *home = getenv("HOME");

    char *pwd = getenv("PWD");

    char *hostname = getenv("HOSTNAME");

    if (hostname == NULL)
    {
        hostname = "guest";
    }

    char *path = malloc(strlen(pwd) - strlen(home) + 1);
    strcpy(path, pwd + strlen(home));
    printf("\033[1;32m%s@%s\033[0m:\033[1;34m%s\033[0m$ ", user, hostname, path);
    free(path);
}
void handle_user_input(char **argv, char **envp);

int main(int argc, char **argv, char **envp)
{

    if (argc < 2)
    {
        /* handle interactive mode */
        handle_user_input(argv, envp);
    }

    else
    {
        /* handle non-interactive mode */
        int j = 0;
        while (envp[j] != NULL)
        {
            printf("%s\n", envp[j]);
            j++;
        }

        char **tokens = malloc(sizeof(char *) * argc);
        int i = 0;
        while (argv[i])
        {
            tokens[i] = argv[i + 1];
            i++;
        }

        if (execve(tokens[0], tokens, envp) == -1)
        {
        }
    }

    return 0;
}

void handle_user_input(char **argv, char **envp)
{

    char *line, *line_copy;
    size_t line_size = 1024;
    char *token, *path_token;
    char **tokens;
    char *env, *en;
    int i = 0;
    struct stat st;
    pid_t child_pid;
    int status;
    en = getenv("PATH");

    while (1)
    {

        /* start print [prompt] */
        drow_prompt();

        line = malloc(sizeof(char) * line_size);
        getline(&line, &line_size, stdin);

        line_copy = strdup(line);

        token = strtok(line, " \n");
        if (strcmp(token, "exit") == 0)
        {
            exit(0);
        }
        while (token)
        {
            token = strtok(NULL, " \n");
            i++;
        }
        /* end print [prompt] */

        /* start tokenization [tokens] */
        tokens = malloc(sizeof(char *) * i);
        token = strtok(line_copy, " \n");
        i = 0;
        while (token)
        {
            tokens[i] = malloc(strlen(token) * sizeof(char));
            tokens[i] = token;
            token = strtok(NULL, " \n");
            i++;
        }
        i = 0;

        en = getenv("PATH");
        env = strdup(en);
        path_token = strtok(env, ":");
        /* end tokenizatin [toknes] and return [path_token] */

        /* start full command and execute command if exits */
        while (path_token)
        {
            char *full_command = malloc(strlen(tokens[0]) + strlen(path_token) + 2);
            strcpy(full_command, path_token);
            strcat(full_command, "/");
            strcat(full_command, tokens[0]);
            strcat(full_command, "\0");
            if (stat(full_command, &st) == 0)
            {
                tokens[0] = full_command;
                child_pid = fork();
                if (child_pid == -1)
                {
                    perror("forkError:");
                    // return (1);
                    exit(1);
                }
                if (child_pid == 0)
                {
                    int exeve_return = execve(tokens[0], tokens, envp);

                    if (exeve_return == -1)
                    {
                        printf("%s: %d: %s: not found\n", argv[0], i, tokens[0]);
                    }
                    exit(0);
                }
                else
                {
                    wait(&status);
                }
            }
            else
            {
                path_token = strtok(NULL, ":");
            }
        }
        /* end full command and execute command if exits */
    }
}