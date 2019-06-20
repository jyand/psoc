#include <project.h>

int octaveAscent(int delay){
    if(delay>0 && delay%2==0){
        pin1_Write(1);
        CyDelay(delay);
        pin1_Write(0);
        CyDelay(delay);
        return octaveAscent(delay/2);
    }
    else{
        pin1_Write(0);
        return 0;
    }
}

int main(){
    CyGlobalIntEnable;
    int initialDelay = 1024;
    while(1){
        octaveAscent(initialDelay);
    }
}