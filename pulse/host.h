 /*
 * pulse_new Example
 * Autor Lucas Costa
 * Agosto de 2018
 * A base de tempo da classe é micro segundo (us), a função micors reseta a cada 70 min.
 */

#ifndef host_provider
#define host_provider

#include "Arduino.h"
#include <ESP8266WiFi.h>

class Host
{
    private:
        const char *_ssid;
        const char *_password;
        bool _status = false;
        IPAddress _ip;
        WiFiClient _client;
        String _request;
        bool _response = false;
        int _value = 0;

    public:
        Host ( const char* ssid, const char* password  );
        void provide ( );
        String listen ( );
        int response ( );
        void off ( );
};

#endif