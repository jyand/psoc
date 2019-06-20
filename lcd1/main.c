#include <project.h>

int main(){
    
    CyGlobalIntEnable;
    
    char finalString[] = "Progam Completion Succeeded ";
    uint8 strlength = 0;
    uint8 complete;
    while (finalString[strlength] != '\0'){
        strlength++;
    }
    
    CharLCD_Start();
    CharLCD_Position(0, 0);
    CharLCD_PrintString("    My First");
    CharLCD_Position(1, 0);
    CharLCD_PrintString("Microcontroller");
    CyDelay(2000);
    CharLCD_ClearDisplay();
    
    CharLCD_Position(0, 0);
    CharLCD_PrintString("  I/O Console");
    CharLCD_Position(1, 0);
    CharLCD_PrintString("    Program");
    CyDelay(2000);
    CharLCD_ClearDisplay();
    
    CharLCD_Position(0, 0);
    CharLCD_PrintString("MicroController");
    CharLCD_Position(1, 0);
    CharLCD_PrintString("  Programmer");
    CyDelay(2000);
    CharLCD_ClearDisplay();
    
    CharLCD_Position(0, 0);
    CharLCD_PrintString(" Press a Switch");
    CharLCD_Position(1, 0);
    CharLCD_PrintString(" to continue...");
    CyDelay(2000);

    while(1){
        while(Pin_1_Read() && Pin_2_Read()){}
        CyDelay(100);
        if(!Pin_1_Read() || !Pin_2_Read()){
            complete = 1;
            while(!Pin_1_Read() || !Pin_2_Read()){}
            CyDelay(100);
        }
        while(complete){
            CharLCD_ClearDisplay();
            CharLCD_Position(0, 0);
            CharLCD_PrintString("    Program");
            CharLCD_Position(1, 0);
            CharLCD_PrintString("   completion");
            CyDelay(1000);
            CharLCD_ClearDisplay();
            CharLCD_Position(0, 0);
            CharLCD_PrintString("   completion");
            CharLCD_Position(1, 0);
            CharLCD_PrintString("   succeeded");
            CyDelay(1000);
            CharLCD_ClearDisplay();
            CharLCD_Position(0, 0);
            CharLCD_PrintString("   succeeded");
            CharLCD_Position(1, 0);
            CharLCD_PrintString("    Program");
            CyDelay(1000);
        }
    }
}