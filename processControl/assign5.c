#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int Procreate(int a, pid_t *childrenPIDs){
    long forkPid;
    for(int i = 0; i < a; i++){
        forkPid = fork();
        switch(forkPid){
            case -1: 
                printf("Error -1");
                return -1;
            case 0:
                return i + 1;
            default:
                childrenPIDs[i] = forkPid;
        }
    }
    return 0;
}
int ZombieReaper(int zombieCount){
    int killCount = 0;
    int check;
    for(int i = 0; i < zombieCount; i++){
        if(wait(&check) > 0){
           killCount++;
            if(WIFSIGNALED(check))
                psignal(WTERMSIG(check), "Exit Signal");
        }
    }
    
    if(killCount == zombieCount){
        return 0;
    }else{
        return 1;
    }
}
void Purpose(int i){
    printf("Child Process %d, PID: %ld, PPID: %ld\n", i, (long)getpid(), (long)getppid());
}
