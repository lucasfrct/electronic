
#include "Arduino.h"
#include "voltAC.h"

voltAC::voltAC ( int pin )
{
	__pin = pin;
}

float voltAC::sample ( ) 
{	
    return analogRead ( __pin ) + offset;  
}

float voltAC::sineWave ( )
{
	return ( 512 - this->sample ( ) );
}

float voltAC::meter ( ) 
{
	__storage = 0;
	for ( i = 0; i < __rate; i++ ) {
    	__storage += this->sample ( );  
  	};
  	__meassure = ( __storage / __rate );
	__average =  ( __average + ( ( __meassure - __average ) / 2 ) );
	return __average;
}

float voltAC::voltage ( )
{
	__timeLoop = millis ( );
	
	if ( __timeLoop > ( __currentTimeMeassure + ( 64 ) ) ) {
		__currentTimeMeassure = __timeLoop;
		__storageHold += this->vpp ( );
		__indexhold++;
	};

	if ( __timeLoop > ( __currentTime + ( 1000 / sampleRate ) ) ) {
		__currentTime = __timeLoop;
		__voltage = this->mapVoltage ( ( __storageHold / __indexhold ) );
		__storageHold = 0;
		__indexhold = 0;
	};
	return __voltage;
}

float voltAC::vpp ( ) 
{
	__meter = this->meter ( );
	if ( __meter >= 512 && __meter > __hold - 8 ) {
		__hold = __meter;
	} else if ( __hold > 512 ) {
		__hold = __hold - ( __hold * 0.01 );
	};
	return ( abs ( __hold - 511 ) * 2 );
}

float voltAC::mapVoltage ( float value )
{
	// 0.00244140625 <=> ( 2.5V / 1024);
	return ( value * 0.00244140625 );
}

float voltAC::frequency ( )
{
	__source = this->sineWave ( );

	if ( __source > 0 && !__status ) {
		__status = true;
		__count++;
	};

	if ( __source < 0 && __status ) {
		__status = false;
	};

	__timeFrequency = millis ( );
	
	if ( __timeFrequency > ( __currentFrequency + ( 1000 / sampleRate ) ) ) {
		__currentFrequency = __timeFrequency;

		if ( __trigger < 3 ) {
			__buffer += __count; 
			__trigger++;
		};

		__frequency = ( __buffer / __trigger );

		__count = 0;

		if ( __trigger >= 3 ) {
			__trigger = 0;
			__buffer = 0;
		};
	};

	return __frequency;

}

float voltAC::map ( float value, float fromVoltage, float toVoltage )
{
	return ( value * ( toVoltage / fromVoltage ) );
}