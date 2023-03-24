#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
    DigitalIn gasDetector(D2);

    gpio_t alarmLedC; // En C variable tipo gpio_t general port input output
    gpio_init_out (&alarmLedC, LED1); // En C defino como salida al pin LED1

     gpio_t gasDetectorC; // En C variable tipo gpio_t general port input output
    gpio_init_in (&gasDetectorC , D2); // En C defino como entrada al pin D2
    // DigitalOut alarmLed(LED1); C++

    core_util_critical_section_enter(); // En C
    gpio_mode(&gasDetectorC, PullDown);
    core_util_critical_section_exit();

   //  gasDetector.mode(PullDown); En C++

    bool ledStatus = OFF;

   // alarmLed = OFF;  En C++
    gpio_write(&alarmLedC, OFF);

    printf ("hola!\n"); // @note usar baudrate 9600
    while (true) {
        if ( gpio_read (&gasDetectorC) == ON ) {
               gpio_write(&alarmLedC, ON);
  
        }

        // printf ("%i\n", alarmLed.read()); // @note imprime el estado del led
        
        printf ("LED %i\n", gpio_read(&alarmLedC));  //C

        if ( gpio_read (&gasDetectorC) == OFF ) {
            gpio_write(&alarmLedC, OFF);
       
        }
    }
}