#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void fibonacci(int n) {
    int t1 = 0, t2 = 1, proximoTermo;

    printf("Sequência de Fibonacci até %d termos:\n", n);

    for (int i = 1; i <= n; ++i) {
        printf("%d ", t1);
        proximoTermo = t1 + t2;
        t1 = t2;
        t2 = proximoTermo;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        fprintf(stderr, "Por favor, insira um valor positivo para n.\n");
        return 1;
    }

    pid_t pid = fork(); // Cria um novo processo

    if (pid < 0) {
        // Erro ao criar o processo filho
        perror("Erro no fork");
        return 1;
    }

    if (pid == 0) {
        // Processo filho
        printf("Processo filho calculando Fibonacci...\n");
        fibonacci(n);
        exit(0); // Termina o processo filho
    } else {
        // Processo pai
        wait(NULL); // O pai espera o filho terminar
        printf("Processo pai: Filho terminou.\n");
    }

    return 0;
}
