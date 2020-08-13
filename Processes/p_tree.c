#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
    pid_t branch[2], c_branch[2];
    int ram = 2;

    for (int i = 0; i < 2; i ++)
    {
        if ((branch[i] = fork()) == 0)
        {
            for (int j = 0; j < ram; j ++)
            {
                if ((c_branch[j] = fork()) == 0)
                {
                    printf("Child branch #%d pid = %d, ppid = %d\n", j+1, getpid(), getppid());
                    return 0;
                }

                waitpid(c_branch[j], NULL, WUNTRACED);
            }
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
            printf("Branch #%d pid = %d, ppid = %d\n", i+1, getpid(), getppid());
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
            return 0;
        }
        waitpid(branch[i], NULL, WUNTRACED);
        ram--;
    }
    printf("Tree pid = %d\n", getpid());
    return 0;
}
