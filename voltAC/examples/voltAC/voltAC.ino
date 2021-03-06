#include <voltAC.h>

// *****************   pin  *************************
voltAC voltmeterAC (   A0   );

float value = 0;

void setup ( ) {
   
   Serial.begin ( 115200 );
   
   //voltmeterAC.sampleRate = 10 // amostas por segundo;
   //voltmeterAC.offset = 1; // correção de fuga DC

};

void loop ( ) {

	//value = voltmeterAC.sample ( );
  	//value = voltmeterAC.sineWave ( );
  	//value = voltmeterAC.meter ( );
  	value = voltmeterAC.voltage ( );
  	//value = voltmeterAC.vpp ( );
  	//value = voltmeterAC.frequency ( );

  	value = voltmeterAC.map ( value, 2.5, 380 ); // map from 2.5V to 380V

  	Serial.println ( value );

};