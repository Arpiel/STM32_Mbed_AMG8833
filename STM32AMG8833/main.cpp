#include "mbed.h"
#include <algorithm>
#include <cstdio>
#include <AMG8833.h>
AMG8833 AMGT(PB_9,PB_8,AMG8833::AMG8833_ADDRESS_AD_SELECT_VDD, 400000);
DigitalOut led1(LED1);
int main()
{
    AMG8833::AMG8833_data_t AMGdata;
    AMG8833::AMG8833_status_t AMGSTAT;
    AMGdata.operationMode=AMG8833::PCTL_NORMAL_MODE;
    AMGSTAT=AMGT.AMG8833_SetOperationMode(AMGdata);
    AMGSTAT=AMGT.AMG8833_SoftwareReset(AMG8833::RST_INITIAL_RESET);
    HAL_Delay(500);
    AMGSTAT=AMGT.AMG8833_SetFrameMode(AMG8833::FPSC_10FPS);
    AMGSTAT=AMGT.AMG8833_SetAverageOutputMode(AMG8833::MAMOD_WICE_MOVING_AVERAGE_OUTPUT_MODE_OFF);
    AMGSTAT=AMGT.AMG8833_ClearFlags(( AMG8833::OVT_CLR_THERMISTOR_TEMPERATURE_OVERFLOW_CLEAR_FLAG | AMG8833::OVS_CLR_TEMPERATURE_OVERFLOW_CLEAR_FLAG | AMG8833::INTCLR_INTERRUPT_OUTBREAK_CLEAR_FLAG ) );
    AMGSTAT=AMGT.AMG8833_SoftwareReset(AMG8833::RST_INITIAL_RESET);
    HAL_Delay(500);
    AMGdata.operationMode=AMG8833::PCTL_NORMAL_MODE;
    AMGSTAT=AMGT.AMG8833_SetOperationMode(AMGdata);

    float temp=0;
    while (true)
    {
        AMGSTAT=AMGT.AMG8833_GetThermistorValue(&AMGdata);
        AMGSTAT=AMGT.AMG8833_GetPixelTemperatures(&AMGdata);
        printf(" %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n %0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|%0.2f| \n "
                 ,AMGdata.pixelOutputValues[0],AMGdata.pixelOutputValues[1],AMGdata.pixelOutputValues[2],AMGdata.pixelOutputValues[3],AMGdata.pixelOutputValues[4],AMGdata.pixelOutputValues[5],AMGdata.pixelOutputValues[6],AMGdata.pixelOutputValues[7]
                 ,AMGdata.pixelOutputValues[8],AMGdata.pixelOutputValues[9],AMGdata.pixelOutputValues[10],AMGdata.pixelOutputValues[11],AMGdata.pixelOutputValues[12],AMGdata.pixelOutputValues[13],AMGdata.pixelOutputValues[14],AMGdata.pixelOutputValues[15]
                 ,AMGdata.pixelOutputValues[16],AMGdata.pixelOutputValues[17],AMGdata.pixelOutputValues[18],AMGdata.pixelOutputValues[19],AMGdata.pixelOutputValues[20],AMGdata.pixelOutputValues[21],AMGdata.pixelOutputValues[22],AMGdata.pixelOutputValues[23]
                 ,AMGdata.pixelOutputValues[24],AMGdata.pixelOutputValues[25],AMGdata.pixelOutputValues[26],AMGdata.pixelOutputValues[27],AMGdata.pixelOutputValues[28],AMGdata.pixelOutputValues[29],AMGdata.pixelOutputValues[30],AMGdata.pixelOutputValues[31]
                 ,AMGdata.pixelOutputValues[32],AMGdata.pixelOutputValues[33],AMGdata.pixelOutputValues[34],AMGdata.pixelOutputValues[35],AMGdata.pixelOutputValues[36],AMGdata.pixelOutputValues[37],AMGdata.pixelOutputValues[38],AMGdata.pixelOutputValues[39]
                 ,AMGdata.pixelOutputValues[40],AMGdata.pixelOutputValues[41],AMGdata.pixelOutputValues[42],AMGdata.pixelOutputValues[43],AMGdata.pixelOutputValues[44],AMGdata.pixelOutputValues[45],AMGdata.pixelOutputValues[46],AMGdata.pixelOutputValues[47]
                 ,AMGdata.pixelOutputValues[48],AMGdata.pixelOutputValues[49],AMGdata.pixelOutputValues[50],AMGdata.pixelOutputValues[51],AMGdata.pixelOutputValues[52],AMGdata.pixelOutputValues[53],AMGdata.pixelOutputValues[54],AMGdata.pixelOutputValues[55]
                 ,AMGdata.pixelOutputValues[56],AMGdata.pixelOutputValues[57],AMGdata.pixelOutputValues[58],AMGdata.pixelOutputValues[59],AMGdata.pixelOutputValues[60],AMGdata.pixelOutputValues[61],AMGdata.pixelOutputValues[62],AMGdata.pixelOutputValues[63]
                 );
        for(int i=0;i<64;i++)
        {
            if(temp<AMGdata.pixelOutputValues[i])
            temp=AMGdata.pixelOutputValues[i];
        }
        printf("\n");
        printf("%f \n",temp);
        if(temp>38)
        {
            led1.write(1);
        }
        else
        {
            led1.write(0);
        }
        temp=0;
        HAL_Delay(200);
    }
}