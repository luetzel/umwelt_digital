#define _GNU_SOURCE

#include "MicroBit.h" 
#include <array>
#include <stdlib.h>
#define _SET_BRIGHTNESS_MULTIPLIER 28.34
#define _GET_BRIGHTNESS_MULTIPLIER 0.0353
#define _GET_LIGHTLEVEL_MULTIPLIER 0.3922
#define _ITERATION_SLEEP_TIMEOUT 1

MicroBit uBit;


int initTime = uBit.systemTime();
double Messwert1;
double Messwert2;
double Messwert3;
double Mittelwert;
double Summe;

int main()
{
    uBit.init();
    Messwert1 = 0;
    Messwert2 = 0;
    Messwert3 = 0;
    Mittelwert = 0;
    Summe = 0;
    
    while ( true ) {
        while (true) {
            if ( uBit.buttonA.isPressed() == true ) {
                break;
            }
            uBit.sleep(_ITERATION_SLEEP_TIMEOUT);
        }
        uBit.io.P0.setAnalogValue(1023);
        uBit.sleep(500);
        uBit.io.P0.setAnalogValue(0);
        uBit.sleep(500);
        uBit.io.P0.setAnalogValue(1023);
        Messwert1 = uBit.io.P1.getAnalogValue();
        uBit.sleep(100);
        Messwert2 = uBit.io.P1.getAnalogValue();
        uBit.sleep(100);
        Messwert3 = uBit.io.P1.getAnalogValue();
        uBit.io.P0.setAnalogValue(0);
        Summe = Messwert1 + ( Messwert2 + Messwert3 );
        Mittelwert = Summe / ((float) 3);
        uBit.display.print(ManagedString(Mittelwert));
        uBit.sleep(1000);
        uBit.sleep(_ITERATION_SLEEP_TIMEOUT);
    }
    release_fiber();
}
