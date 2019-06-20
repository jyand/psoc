#include "project.h"
#include<stdint.h>

int main(){
    /*Part of Cypress library to enable global interrupts.*/
    CyGlobalIntEnable;
    /*Delay in milliseconds, declared as an int so 
    only one value is changed as period is varied*/
    int halfPeriod = 500;
    /*The value of LED controlled by the button*/
    int led;
    /*Loop ad infinitum*/
    while(1){
        /*Produces a square wave*/
        Pin_1_Write(1);
        CyDelay(halfPeriod);
        Pin_1_Write(0);
        CyDelay(halfPeriod);  
        /*Sets the variable to the inverse of the button value*/      
        led = ~Pin_3_Read();
        /*Set the value of the variable to the led*/
        Pin_2_Write(led);
    }
}