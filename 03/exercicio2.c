#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int valor = 100;
int* ptr = &valor;
int main(int argc, char **argv)
{
    pid_t pid = fork(); // Função usada para criar um novo processo
    if (pid == 0)
    { // Processo filho
        *ptr += 100;
        exit(0); // Função que encerra o processo
    }
    else if (pid > 0)
    {               // Processo pai
        wait(NULL); // O pai vai esperar a conclusão do filho
    }
    printf("Valor da variável é %d\n", valor);
    return 0;
}

/* Nada mudou pois, quando o fork() é chamado, ele cria uma cópia exata do processo original (o pai) e
   todo o seu estado, incluindo variáveis e ponteiros.
*/