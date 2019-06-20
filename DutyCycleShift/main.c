#include <project.h>

int main(){
    CyGlobalIntEnable;
    int halfPeriod = 10;
    int i, r;
    int N = 10;
    while(1){
        for(i = 0; i<N; i++){
            r = N-i;
            pin1_Write(1);
            CyDelay(halfPeriod*r);
            pin1_Write(0);
            CyDelay(halfPeriod*i);
        }
        for(i = 0; i<N; i++){
            r = N-i;
            pin1_Write(1);
            CyDelay(halfPeriod*i);
            pin1_Write(0);
            CyDelay(halfPeriod*r);
        }
    }
}
