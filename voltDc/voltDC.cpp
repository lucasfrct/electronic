
#include "Arduino.h"
#include "voltDC.h"

voltDC::voltDC ( int pin )
{
	__pin = pin;
}

float voltDC::sample ( ) 
{	
    return analogRead ( __pin ) + offset;  
}

float voltDC::meter ( ) 
{
	__storage = 0;
	for ( i = 0; i < __rate; i++ ) {
    	__storage += this->sample ( );  
  	};
  	__meassure = ( __storage / __rate );
	__average =  ( __average + ( ( __meassure - __average ) / 2 ) );
	return __average;
}

float voltDC::voltage ( )
{
	__timeLoop = millis ( );
	
	if ( __timeLoop > ( __currentTimeMeassure + ( 256 ) ) ) {
		__currentTimeMeassure = __timeLoop;
		__storageHold += this->meter ( );
		__indexhold++;
	};

	if ( __timeLoop > ( __currentTime + ( 1000 / sampleRate ) ) ) {
		__currentTime = __timeLoop;
		__voltage = ( __storageHold / __indexhold );
		__storageHold = 0;
		__indexhold = 0;
		__voltage = this->mapVoltage ( __voltage );
	};
	return __voltage;
}

float voltDC::mapVoltage ( float value )
{
	// 0.00488758553 <=> ( 5V / 1023 );
	return ( value * 0.00488758553 );
}

float voltDC::map ( float value, float fromVoltage, float toVoltage )
{
	return ( value * ( toVoltage / fromVoltage ) );
}