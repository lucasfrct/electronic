 /*
 * pulse_new Example
 * Autor Lucas Costa
 * Agosto de 2018
 */

#include "Arduino.h"
#include "channel.h"
#include "pwm.h"

Channel::Channel ( ) { };

void Channel::setup ( int pinRed, int pinGreen, int pinBlue )
{   
    _Blue = new Pwm ( pinBlue );
    delayMicroseconds ( 1 );
    _Green = new Pwm ( pinGreen );
    delayMicroseconds ( 1 );
    _Red = new Pwm ( pinRed );
    delayMicroseconds ( 1 );
};

void Channel::duty ( float duty ) 
{
    _duty = duty;
};

void Channel::dimmer ( float dimmer )
{
    _dimmer = dimmer;
};

void Channel::red ( float dimmer )
{   
    _redDimmer = dimmer;
};

void Channel::green ( float dimmer )
{   
    _greenDimmer = dimmer;
};

void Channel::blue ( float dimmer )
{   
    _blueDimmer = dimmer;
};

void Channel::strobo ( float dimmer )
{
    _strobo = dimmer;
}

void Channel::update ( ) 
{
    register float percentDimmer = ( ( 100 * _dimmer ) / 255 );
    register float percentRed = ( ( 100 * _redDimmer ) / 255 );
    register float percentGreen = ( ( 100 * _greenDimmer ) / 255 );
    register float percentBlue = ( ( 100 * _blueDimmer ) / 255 );

    float strobo = ( ( 30 * _strobo ) / 255 );
    _frequency = ( strobo > 0 ) ? strobo : 0;

    _Blue->frequency ( _frequency );
    _Blue->duty ( _duty );
    _Blue->update ( );
    delayMicroseconds ( 1 );

    _Green->frequency ( _frequency );
    _Green->duty ( _duty );
    _Green->update ( ); 
    delayMicroseconds ( 1 );

    _Red->frequency ( _frequency );
    _Red->duty ( _duty );
    _Red->update ( ); 
    delayMicroseconds ( 1 );
};

void Channel::out ( ) 
{  
    _Blue->out ( );
    _Green->out ( );
    _Red->out ( );
    delayMicroseconds ( 1 );
};

bool Channel::hasSerial ( )
{
    return ( Serial.available ( ) > 0 ) ? true : false;
};

String Channel::serial ( )
{
    String content = "";
    char character;

    while ( true ) {
        character = Serial.read ( );
        if ( character != '\n' ) {
            content.concat ( character );
        };
        delay ( 10 );
    };

    return content;
};