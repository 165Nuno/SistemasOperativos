#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    pid_t pid; // para o fork
    pid_t pid_atual = getpid(); // pid do processo atual
    int status; // status

    if ((pid = fork())== 0){
        // Estamos no processo filho
        pid_t filho = getpid(); // pid do processo atual, que é o processo do filho
        printf("[PROCESSO FILHO] seu própio identificador %d\n",filho);
        printf("[PROCESSO FILHO] pid do seu pai %d\n",pid_atual);
        _exit(0);
    }else{
        // Estamos no processo pai
        pid_t pid_filho = wait(&status);
        pid_t pai = getppid();
        printf("[PROCESSO PAI] pid do seu processo pai %d\n",pai);
        printf("[PROCESSO PAI] o pid do seu próprio processo %d\n",pid_atual);
        printf("[PROCESSO PAI] pid do seu filho %d\n",pid_filho);
    }
}
