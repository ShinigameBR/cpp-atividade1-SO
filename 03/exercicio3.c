#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int valor = 100;
int* ptr = &valor;

int main(int argc, char **argv)
{
    pid_t pid1 = fork(); // Primeiro fork

    if (pid1 == 0)
    {
        *ptr += 100; // Incrementa o valor
        printf("Filho 1 - Valor da variável é %d\n", valor);

        pid_t pid2 = fork(); // Segundo fork
        if (pid2 == 0)
        {
            *ptr += 100; // Incrementa o valor novamente
            printf("Filho 2 - Valor da variável é %d\n", valor);
            exit(0);
        }
        else if (pid2 > 0)
        {
            wait(NULL); // Primeiro filho espera o segundo filho terminar
            printf("Filho 1 após Filho 2 - Valor da variável é %d\n", valor);
        }
        exit(0); // Encerra o primeiro filho
    }
    else if (pid1 > 0)
    {
        wait(NULL); // Pai espera o primeiro filho terminar
        printf("Pai - Valor da variável é %d\n", valor);
    }

    return 0;
}
