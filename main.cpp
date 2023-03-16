#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);

    bool ledStatus = OFF;

    alarmLed = OFF;

    printf ("hola!\n"); // baudrate 9600
    while (true) {
        if ( gasDetector == ON ) {
            alarmLed = ON;
            ledStatus = ON;
        }

        printf ("%d\n", ledStatus); // baudrate 9600

        if ( gasDetector == OFF ) {
            alarmLed = OFF;
            ledStatus = OFF;
        }
    }
}