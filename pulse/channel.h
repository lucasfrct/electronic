 /*
 * pulse_new Example
 * Autor Lucas Costa
 * Agosto de 2018
 */

#ifndef channel_controller
#define channel_controller

#include "Arduino.h"
#include "math.h"
#include "pwm.h"

class Channel
{
    private:
        Pwm *_Red;
        Pwm *_Green;
        Pwm *_Blue;

        float _frequency = 1.0;  // 1 - 30 fps 
        float _duty = 50; // 0% - 100%

        float _dimmer = 255; // 0 - 255 | DMX 2^8 = 8bits
        float _redDimmer = 255; // 0 - 255 | DMX 2^8 = 8bits
        float _greenDimmer = 255; // 0 - 255 | DMX 2^8 = 8bits
        float _blueDimmer = 255; // 0 - 255 | DMX 2^8 = 8bits
        float _strobo = 0; // 0 - 255 | DMX 2^8 = 8bits
        String _mode = "analogic";

    public:
        Channel ( );
        void setup ( int pinRed, int pinGreen, int pinBlue );
        void duty ( float duty );
        void dimmer ( float dimmer );
        void red ( float dimmer );
        void green ( float dimmer );
        void blue ( float dimmer );
        void strobo ( float fader );
        void update ( );
        void out ( );
        bool hasSerial ( );
        String serial ( );
};

#endif
