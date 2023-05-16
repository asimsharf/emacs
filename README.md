```c
printf("$");
getline(&b, &bS, stdin)
char *c = strdup(b);
char *token = strtok(b, " ");
char **list_of_tokens = malloca();
int i = 0;
while(token){
    list_of_tokens[i] = token;
    token = strtok(NULL, " ");
    i++;
}

pid_t pid;

pid = fork();

if (pid == 0){
    if(execve(list_of_tokens[0], list_of_tokens) == 0){

    }else{
        printf("Error");
    }
}