#include "mbed.h"

#include "VL53L0X.h"
#include "SRF05.h"

SRF05 srf_Left(PA_10,PB_3); // Output from PA_10 (D2) is connected to the Trigger pin of the SRF05, Input to PB_3 (D3) is connected to the SRF05 Echo_Pin. 
SRF05 srf_Right(PA_8,PA_9); // Output from PA_8 (D7) is connected to the Trigger pin of the SRF05, Input to PA_9 (D8) is connected to the SRF05 Echo_Pin.   

I2C i2c(PB_9,PB_8);
VL53L0X sensor(&i2c);
Serial      usb(USBTX, USBRX, 9600);

float Left_Ultrasonic;
float Right_Ultrasonic;
float Time_of_flight;

DigitalIn Blue_button(PC_13);

int main(void) {

                sensor.init();
                sensor.setModeContinuous();
                sensor.startContinuous();

    while (1){

                Time_of_flight = sensor.getRangeMillimeters();
                Left_Ultrasonic = 10*srf_Left.read() ;
                Right_Ultrasonic = 10*srf_Right.read();                 
                           
                printf("Time of flight: %.0f \t", Time_of_flight);                                          
                printf("Left Ultrasonic: %.0f  \t"  , Left_Ultrasonic) ;
                printf("Right Ultrasonic: %.0f \t", Right_Ultrasonic);
                printf("\n");
                wait(0.05);   
              }
    }