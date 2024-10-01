#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    fork(); // Funcao usada para criar um novo processo
    fork(); // E mais um
    fork(); // E mais um
    printf("Sou o processo %d.\n", getpid());
    return 0;
}