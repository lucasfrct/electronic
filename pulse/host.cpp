 /*
 * pulse_new Example
 * Autor Lucas Costa
 * Agosto de 2018
 */

#include "Arduino.h"
#include "host.h"

WiFiServer hostProvider ( 80 );

Host::Host ( const char* ssid, const char* password )
{
    _ssid = ssid;
    _password = password;  
};

void Host::provide (  )
{
    WiFi.mode ( WIFI_STA );
    WiFi.begin ( _ssid, _password );

    while ( WiFi.status ( ) != WL_CONNECTED ) {
        delay ( 500 );
        //Serial.print ( "." );
    };


    hostProvider.begin ( );

    delay ( 200 );

    Serial.println ( "" );
    Serial.println ( "" );
    Serial.print ( "WIFI conectado: " );
    Serial.print ( _ssid );
    Serial.print ( " :: HTTP server iniciado: " );
    Serial.println ( WiFi.localIP ( ) );

};

String Host::listen ( )
{
    _request = "";

    _client = hostProvider.available ( );

    if ( !_client ) { return _request; };

    Serial.println ( "Ouvindo..." );

    int count = 1;
    while ( !_client.available ( ) || count < 100 ) {
        count = count + 1;
        delay ( 1 );
    };

    _status = true;
    _request = _client.readStringUntil ( '\r' );

    Serial.print ( "Requisição: " );
    Serial.println ( _request );

    _client.flush ( );

    if ( _request.indexOf ( "/gpio/1" ) != -1 ) {
        _value = 0;
    } else if ( _request.indexOf ( "/gpio/0" ) != -1 ) {
        _value = 1;
    } else {
        _client.stop ( );
        return _request;
    };

    Serial.print ( "Value: " );
    Serial.println ( _value );

    return _request;
};

int Host::response ( )
{
    if ( _status != true ) { return 0 ; };

    Serial.println ( "Respondendo..." );
    _client.flush ( );

    String header = "HTTP/1.1 200 OK\r\n";
    header += "Content-Type: text/html\r\n";
    header += "Access-Control-Allow-Origin: *\r\n";
    header += "Vary: Origin\r\n";
    header += "Access-Control-Allow-Methods: POST, GET, OPTIONS, DELETE\r\n";
    header += "Access-Control-Request-Headers: X-PINGOTHER, Content-Type\r\n";

    String html = header;
    html += "\r\n<!DOCTYPE HTML>\r\n<html>\r\n";
    html = "GPIO: ";
    html += ( _value ) ? "high" : "low";
    html += "\r\n";
    html += "</html>\n";

    _client.print ( html );
    _status = false;

    return _value;
};

void Host::off ( )
{
    WiFi.mode ( WIFI_OFF );
    WiFi.forceSleepBegin ( );
    delay ( 10 );
}