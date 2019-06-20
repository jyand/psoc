
#include <project.h>
#include <stdint.h>
#include <stdio.h>

int main(){
    
    CyGlobalIntEnable;
    
    uint8 volatile led3 = 0;
    uint8 volatile led4 = 0;
    
    Pin_3_Write(1);
    Pin_4_Write(1);
    
    CharLCD_Start();
    CharLCD_ClearDisplay();
    CharLCD_Position(0, 0);
    CharLCD_PrintString("     Hello!");
    CyDelay(2500);
    CharLCD_Position(0, 0);
    CharLCD_PrintString(" please press");
    CharLCD_Position(1, 0);
    CharLCD_PrintString("      SW3");
    
    while(Pin_1_Read()){}
    CyDelay(300);
    
    Pin_3_Write(0);
    Pin_4_Write(0);
    
    CharLCD_ClearDisplay();
    CharLCD_Position(0, 0);
    CharLCD_PrintString(" press a button");
    CharLCD_Position(1, 0);
    CharLCD_PrintString("to toggle an LED");
    CyDelay(300);
    
    while(1){
       while(Pin_1_Read() && Pin_2_Read()){}
       CyDelay(100);
       
       if(!Pin_1_Read()){
           while(!Pin_1_Read()){}
           CyDelay(100);

           CharLCD_ClearDisplay();
           CharLCD_Position(0, 0);
           CharLCD_PrintString("You have pressed");
           CharLCD_Position(1, 0);
           CharLCD_PrintString("SW3 to set LED1");
           led3 = ~led3;
           Pin_3_Write(led3);
       }
        
      if(!Pin_2_Read()){
           while(!Pin_2_Read()){}
           CyDelay(100);
           CharLCD_ClearDisplay();
           CharLCD_Position(0, 0);
           CharLCD_PrintString("You have pressed");
           CharLCD_Position(1, 0);
           CharLCD_PrintString("SW2 to set LED4");
           led4 = ~led4;
           Pin_4_Write(led4);
        }
    }
}