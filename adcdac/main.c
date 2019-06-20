#include <project.h>
#include <math.h>

#define SAMPLES 256

void tableGen(uint8_t *table){
    
    uint16_t i;
    double amplitude = (SAMPLES-1)/4;
    double radPerSample = (M_PI)/SAMPLES;
    
    for(i = 0; i<SAMPLES; ++i){
        table[i] = amplitude*(1-cos(i*radPerSample));
    }
}

int main(){
    
    CyGlobalIntEnable;
    
    ADC_SAR_Start();
    VDAC8_Start();
    
    uint8_t lookUpTable[SAMPLES];
    tableGen(lookUpTable);
        
    while(1){
        ADC_SAR_IsEndConversion(ADC_SAR_WAIT_FOR_RESULT);
        VDAC8_SetValue(lookUpTable[ADC_SAR_GetResult16() >> 4]);
    }
}