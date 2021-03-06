( function ( ) {
	"use strict";
	angular
		.module ( "smartsource" )
		.controller ( "nodemcucontroller", [ "$scope", "$nodemcu", "$interval", NodeMcuController ] );

	function NodeMcuController ( $scope, $nodemcu, $interval ) {

		$scope.voltage = "100.00 V";
        $scope.channels = [
            { channel: 1, voltage: "1.00", ampere: "1.00" },
            { channel: 2, voltage: "1.00", ampere: "1.00" },
            { channel: 3, voltage: "1.00", ampere: "1.00" },
        ];

        $interval ( function ( ) { 
            $nodemcu.voltage ( "D17", function ( $data  ) { 

                $scope.channels [ 0 ].voltage = ( $data [ 0 ] * ( 3 / 1024 ) ).toFixed ( 2 );
                //$scope.channels [ 0 ].voltage = $data [ 0 ];

            } );

        }, 500 );
        console.log ( "teste" );

       
	};
} ) ( );