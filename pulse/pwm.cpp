 /*
 * pulse_new Example
 * Autor Lucas Costa
 * Agosto de 2018
 */

#include "Arduino.h"
#include "pwm.h"

// Método de construção da classe
Pwm::Pwm ( int pin )
{
    // Carrega o pino de sáida na classe PWM
    _pin = pin;

    // Configura o pino para saída de sinal
    pinMode( _pin, OUTPUT );
    // Escreve 0 V no pino de saída
    digitalWrite ( _pin, LOW );
};

// Método para carregar o pino de controle do duty cicle
void Pwm::controller ( int control )
{
    // carrega o pino de entrada
    _control = control;
    pinMode( _control, INPUT );
};

// Método que configura a frequência
void Pwm::frequency ( float frequency )
{
    // Carrega a frequência de sáida na classe PWM
    _frequency = frequency;
};

// Método que configura o ciclo ativo
void Pwm::duty ( float dutyCycle )
{
    // Carrega o tempo ativo de sáida na classe PWM
    _dutyCycle = dutyCycle;
};

// Método que atualiza os parânmetros da classe
void Pwm::update ( ) 
{
    if ( _control ) {
        _dutyCycle = ( 100.0 / 1024.0 ) * analogRead ( _control );
    };

    // Período da frequência escolhida
    _period =  ( ( 1.0 / _frequency ) * 1000000 );
    // Tempo de sinal ativo
    _tOn = ( ( _period / 100.0 ) * _dutyCycle );
    // Tempo de sinal inativo
    _tOff = ( _period - _tOn );
};

// Método que gera o PWM
bool Pwm::out ( )
{   
    // Captura o tempo corrente
    _current = micros ( );

    // Testa se o intervalo  de tOn foi ultrapassado
    if ( _status == false && _current > _interval ) {
        _status = true; // Muda o status
        _interval = ( _current + _tOn ); // Reinicia o intervalo
        digitalWrite ( _pin, HIGH ); // Escreve o valor ativo na porta
      // Testa de o intervalo de tOff foi ultrapassado  
    } else if ( _status == true && _current > _interval ) {
        _status = false; // Muda o status
        _interval = ( _current + _tOff ); // Reinicia o intervalo
        digitalWrite ( _pin, LOW ); // Escreve o valor inativo na porta
    };

    // retorna o status do pwm;
    return _status;
};