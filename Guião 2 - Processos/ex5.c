#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main(){
    int linhas = 7; // número de linhas
    int colunas = 10; // número de colunas
    int matrix[linhas][colunas]; // matrix
    srand(time(NULL));
    int num = rand() % 100;
    int status;

    srand(time(NULL));
    // Geração da matriz de forma aleatória
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // Debug apenas para visualizar 
    for (int i = 0; i < linhas; i++) {
        printf("| ");
        for (int j = 0; j < colunas; j++) {
            printf("%d ",matrix[i][j]);
            printf("|");
        }
        printf("\n");
    }

    printf("%d\n",num);
    pid_t pid;
    for (int var = 0; var < linhas; var++) {

        if ((pid = fork()) == 0){
            // Estamos num filho
            for (int j = 0; j < colunas; j++){
                if(matrix[var][j] == num){
                    _exit(1);
                }
            }
            _exit(0);
        }else{
            // Estamos no pai
            pid_t pid_filho = wait(&status);
            if (WEXITSTATUS(status) == 1){
                printf("O PROCESSO %d encontrou o num que corresponde a %d, **debug** %d\n",pid_filho,num,var);
            }else{
                printf("O PROCESSO %d não encontrou o num, **debug** %d\n",pid_filho,var);
            }
        }


    }
}