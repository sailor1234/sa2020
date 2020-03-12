#include <unistd.h>
#include <stdio.h>
int main() {
        printf("Main before fork()\n");
        int pid = fork();
        if (pid == 0) {
                printf("I am child after fork()\n");
                char *args[]= { "/usr/bin/whoami", NULL};
                execvp("/usr/bin/whoami", args);
        }
        else {
                printf("I am parent after fork(), child is %d\n", pid);
                wait(NULL);
                printf("Finished launching ps -ef\n");
        }
        return 0;
}

