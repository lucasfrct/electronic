#include <voltDC.h>

// *****************   pin  *************************
voltDC voltmeterDC (   A1   );

float value = 0;

void setup ( ) {
   
   Serial.begin ( 115200 );
   
   //voltmeterDC.sampleRate = 10 // amostas por segundo;
   //voltmeterDC.offset = 1; // correção de fuga DC

};

void loop ( ) {

    //value = voltmeterDC.sample ( );
  	//value = voltmeterDC.meter ( );
  	value = voltmeterDC.voltage ( );

  	value = voltmeterDC.map ( value, 2.5, 380 ); // map from 2.5V to 380V

  	Serial.println ( value );

};