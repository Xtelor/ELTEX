#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    pid_t pid;
    int status;

    if((pid = fork()) == 0)
    {
        printf("Child process pid = %d, ppid = %d\n", getpid(), getppid());
    }
    else
    {
        waitpid(pid, NULL, WUNTRACED);
        printf("Parent process: pid = %d, ppid = %d\n", getpid(), getppid());
    }
    return 0;
}
