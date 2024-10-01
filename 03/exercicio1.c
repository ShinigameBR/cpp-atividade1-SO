#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int num_filhos = 4;
    int i;

    for (i = 0; i < num_filhos; i++) {
        pid = fork();

        if (pid < 0) {
            // Erro ao criar o processo filho
            printf("Sou o processo %d e não consegui criar um novo processo.\n", getpid());
            return 1;
        }

        if (pid == 0) {
            printf("Sou o processo filho %d, meu PID é %d.\n", i + 1, getpid());
            _exit(0); // Termina o processo filho
        }
    }

    // Processo pai espera por todos os filhos
    for (i = 0; i < num_filhos; i++) {
        pid_t pid_filho_terminado = wait(NULL);
        printf("Filho com PID %d terminou.\n", pid_filho_terminado);
    }

    printf("Todos os filhos terminaram.\n");

    return 0;
}
