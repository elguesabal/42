#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void    func()
{
    printf("TESTE\n");
}

int main(void)
{
    signal(SIGUSR1, func);

    printf("PID: %d\n", getpid());

    while(1)
    {
        sleep(1);
    }
}

