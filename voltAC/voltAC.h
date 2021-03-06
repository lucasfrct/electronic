/*
* Para sine Wave funcionar é preciso ter um DC Offset de 2.5V
* A máxima Vpp (tensão pico-a-pico) no arduino é 5V 
* Sine Wave varia no ciclo positivo entre +2.5V e +5V
* Sine Wave varia no ciclo negativo entre +2.5V e 0V
* As máximas tensões em Sine Wave são +2.5V e -2.5V acrecidos do DC Offset de +2.5V
*/

#ifndef volt_ac
#define volt_ac

#include "Arduino.h"

class voltAC
{
	public:
		int sampleRate = 1;
		float offset = 0;

		voltAC ( int pin );
		float sample ( );
		float sineWave ( );
		float meter ( );
		float voltage ( );
		float vpp ( );
		float mapVoltage ( float value );
		float frequency ( );
		float map ( float value, float fromVoltage, float toVoltage );
	
	private:
		int i = 0;
		int __pin;

		int __rate = 8;
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

		float __source = 0;
		bool __status = false;
		int __count = 0;
		unsigned long __timeFrequency = 0;
		unsigned long __currentFrequency = 0;
		float __frequency;
		float __buffer = 0;
		int __trigger = 0;
};

#endif