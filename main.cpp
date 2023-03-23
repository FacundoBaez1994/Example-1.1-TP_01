#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    bool ledStatus = OFF;

    alarmLed = OFF;

    printf ("holaaa!\n"); // @note usar baudrate 9600
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
  
        }

        printf ("%i\n", alarmLed.read()); // @note imprime el estado del led

        if ( gasDetector == OFF ) {
            alarmLed = OFF;
       
        }
    }
}