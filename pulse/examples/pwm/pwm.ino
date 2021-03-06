#include <pulse.h>

Pwm ledOn ( D0 );
//Channel ch;
//Host host ( "TecLan", "teclan2018" );

String request;

void setup ( ) {
    Serial.begin ( 115200 );

    ledOn.frequency ( 1 );
    ledOn.duty ( 90 );
    ledOn.update ( );

    //ch.setup ( D8, D6, D5 );
    //ch.duty ( 50 );
    //ch.dimmer ( 255 );
    //ch.red ( 128 );
    //ch.green ( 128 );
    //ch.blue ( 255 );
    //ch.strobo ( 8 );
    //ch.update ( );

    //host.provide ( );
    
};

void loop ( ) {
    ledOn.out ( );
    //ch.out ( );
    //host.listen ( );
    //host.response ( );
};