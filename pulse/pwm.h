 /*
 * pulse_new Example
 * Autor Lucas Costa
 * Agosto de 2018
 * A base de temo da classe é micro segundo (us), a função micors reseta a cada 70 min.
 */

#ifndef pulse_width_modulation
#define pulse_width_modulation

class Pwm
{
    private:
        int _pin; // Pino de saída do isnal PWM
        int _control; // Pino para controlar duty cicle
        float _frequency = 0; // Hz - Frequência do sinal de saída
        float _dutyCycle = 50; // Porcentagem do ciclo ativo
        float _period = 1000000; // us - Microsegundos | Período da frequência
        float _tOn = 50000; // Tempo do ciclo ativo do sinal 
        float _tOff = 50000 ; // Tempo inativo do sinal
        unsigned long _current = 0; // Armazena o tempo corrente
        bool _status = false; // Status do sinal 
        float _interval = 500000; // us - microsegundos | intervalo entre tempo atual
    public:
        Pwm ( int pin ); // Método de construção da classe
        void frequency ( float frequency ); // Método que configura a frequência
        void duty ( float dutyCycle ); // Método que configura o ciclo ativo
        void update ( ); // Método que atualiza os parânmetros da classe
        void controller ( int control );
        bool out ( ); // Método que gera o PWM
};

#endif