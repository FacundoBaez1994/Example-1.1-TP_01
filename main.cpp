#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);  // @note Constructor DigitalIn

    DigitalOut alarmLed(LED1);  // @note Constructor DigitalOUT

    gasDetector.mode(PullDown);  // @note metodo de la clase DigitalIn

    bool ledStatus = OFF;

    alarmLed = OFF; // @note operador "=" sobrecargado de la clase DigitalOUT

    printf ("holaaa!\n"); // @note usar baudrate 9600
    while (true) {
        if ( gasDetector == ON ) {

            alarmLed = ON; // @note operador "=" sobrecargado de la clase DigitalOUT
            printf ("led encendido %i\n", alarmLed.read()); // @note imprime el estado del led
            printf ("gas detectado:  %i\n", gasDetector.read()); // @note imprime el estado del led

        } else {    
        /*
        @note usa operator int() definido en DigitalIn y llama al metodo read
        */
            alarmLed = OFF;
            printf ("led apagado %i\n", alarmLed.read()); // @note imprime el estado del led
            printf ("gas no detectado:  %i\n", gasDetector.read()); // @note imprime el estado del led
        }
    }
}