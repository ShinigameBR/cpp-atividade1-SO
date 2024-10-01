#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid = fork(); // Funcao usada para criar um novo processo

    if (pid < 0)
    { // Erro na criacao do processo
        printf("Sou o processo %d e nao consegui criar um novo processo.\n", getpid());
        return 1;
    }
    else if (pid == 0)
    {                                       // Processo filho
        execlp("./newProgram", "np", NULL); // Funcao derivada da exec()
        printf("Sou o processo filho, meu PID e %d.\n", getpid());
    }
    else
    {               // Processo pai
        wait(NULL); // Funcao que faz o processo pai esperar pelo final da execucao de um de seus filhos
        printf("Sou o processo pai do %d, meu PID e %d.\n", pid, getpid());
    }

    return 0;
}