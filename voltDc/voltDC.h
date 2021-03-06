/*
* Para sine Wave funcionar é preciso ter um DC Offset de 2.5V
* A máxima Vpp (tensão pico-a-pico) no arduino é 5V 
* Sine Wave varia no ciclo positivo entre +2.5V e +5V
* Sine Wave varia no ciclo negativo entre +2.5V e 0V
* As máximas tensões em Sine Wave são +2.5V e -2.5V acrecidos do DC Offset de +2.5V
*/

#ifndef volt_dc
#define volt_dc

#include "Arduino.h"

class voltDC
{
	public:
		int sampleRate = 1;
		float offset = 0;

		voltDC ( int pin );
		float sample ( );
		float meter ( );
		float voltage ( );
		float mapVoltage ( float value );
		float map ( float value, float fromVoltage, float toVoltage );
	
	private:
		int i = 0;
		int __pin;

		int __rate = 16;
		float __storage = 0;
		float __meassure = 0;
		float __average = 0;

		unsigned long __timeLoop = 0;
		unsigned long __currentTime = 0;
		unsigned long __currentTimeMeassure = 0;
		float __voltage = 0;

		float __meter = 0;
		float __hold = 511;
		float __storageHold = 0;
		float __indexhold = 0;
};

#endif