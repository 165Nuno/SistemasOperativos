#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    pid_t pid;
    pid_t pid_atual = getpid();
    int status;


    for(int i = 0; i < 10; i++){
        if((pid = fork()) == 0){
            // Estamos no processo filho
            pid_t filho = getpid(); // pid atual do filho
            printf("[FILHO %d] pid atual %d\n",i+1,filho);
            printf("[FILHO %d] pid do seu pai %d\n", i+1, pid_atual);
            _exit(i+1);
        }else{
            // Estamos no processo pai
            pid_t pid_filho = wait(&status);
            printf("[PAI %d] pid do seu filho %d e o código %d\n",i+1,pid_filho,WEXITSTATUS(status));
            printf("------------------X------------------\n");
        }

    }
}