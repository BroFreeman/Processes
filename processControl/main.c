#include <stdio.h>
#include <stdlib.h>
#include "assign5.h"

int main(int argc, char* argv[]){
    if(argc != 1){
        printf("ERROR ARGS\n");
        return 1;
    }
    
    int numChildren = 5;
    pid_t childrenPIDs[numChildren];

    int childNum = Procreate(numChildren, childrenPIDs);
    if(childNum == -1){
        printf("ERROR Procreation\n");
        return 1;
    }
    if(childNum > 0){
        switch(childNum){
            case 1:
                Purpose(childNum);
                break;
            case 2:
                Purpose(childNum);
                break;
            case 3:
                Purpose(childNum);
                break;
            case 4:
                Purpose(childNum);
                break;
            case 5:
                Purpose(childNum);
                break;
            default:
                printf("ERROR! multitasking stage!\n");
        }
        exit(0);
    }

    int killSuccess = ZombieReaper(numChildren);
    if(killSuccess != 0)
        printf("ERROR kills unsuccessful\n");
    
    return 0;
}
