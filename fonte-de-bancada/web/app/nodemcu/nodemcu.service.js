/*************************************************************
                                    ________________
                         (A0) D17 -|  ____________  |- D16 (D0)
                             --   -| |            | |- D05 (D1) Ler Tensão V1
                             --   -| |            | |- D04 (D2) Ler Tensão V2
     Regular Tensão Vo3 (SD3) D10 -| |            | |- D0  (D3) Ler Tensao V3
                        (SD2) D09 -| |            | |- D02 (D4) Ler Ampere A1
                         (SD1) -- -| |            | |- 3.3V
                         (CMD) -- -| |____________| |- GND
                         (SD0) -- -|                |- D14 (D5) Ler Ampere A2
                         (CLK) -- -|                |- D12 (D6) Ler Ampere A3
                              GND -|                |- D13 (D7) Regular Tensão Vo1
                             3.3V -|                |- D15 (D8) Regular Tensão Vo2
                               -- -|                |- D03 (RX) Comunicar com Arduino
                               -- -|                |- D01 (TX) Comunicar com Arduino
                              GND -|                |- GND
                              Vin -|________________|- 3.3V

 *************************************************************/


( function ( ) {
    "use strict";

    angular
        .module ( "smartsource" )
        .service ( "$nodemcu", [ "$http", NodeMcu ] );

    function NodeMcu ( $http ) {

        var $node = this;

        var $baseURL = "http://blynk-cloud.com/d87577a3e4354088a0ac3c519bd2579c/";

        $node.getURL = function ( $pin ) {
            return String ( $baseURL + "get/"+ $pin );
        };

        $node.setURL = function ( $pin, $value ) {
            return String ( $baseURL + "update/" + $pin + "?value=" + $value );
        };

        $node.query = function ( $url, $fn = null ) {

            $http
                .get ( $url )
                .then ( function ( $data ) {
                   if ( null !== $fn ) {
                       $fn ( $data.data );
                   };
                } );    
        };

        $node.voltage = function ( $pin, $fn ) {
            $node.query ( $node.getURL ( $pin ), $fn );
        }

        
    };

} ) ( );