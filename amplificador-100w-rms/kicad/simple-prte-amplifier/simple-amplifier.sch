EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Single Amplifier"
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R1
U 1 1 5E5886E9
P 5450 3500
F 0 "R1" H 5520 3546 50  0000 L CNN
F 1 "1M" H 5520 3455 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5380 3500 50  0001 C CNN
F 3 "~" H 5450 3500 50  0001 C CNN
	1    5450 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5E58A6DC
P 5450 4400
F 0 "R2" H 5520 4446 50  0000 L CNN
F 1 "100k" H 5520 4355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5380 4400 50  0001 C CNN
F 3 "~" H 5450 4400 50  0001 C CNN
	1    5450 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E58B4C9
P 5950 3500
F 0 "R3" H 6020 3546 50  0000 L CNN
F 1 "2k2" H 6020 3455 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5880 3500 50  0001 C CNN
F 3 "~" H 5950 3500 50  0001 C CNN
	1    5950 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E58BA69
P 5950 4400
F 0 "R4" H 6020 4446 50  0000 L CNN
F 1 "150R" H 6020 4355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5880 4400 50  0001 C CNN
F 3 "~" H 5950 4400 50  0001 C CNN
	1    5950 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R5
U 1 1 5E58C067
P 6650 3950
F 0 "R5" H 6720 3996 50  0000 L CNN
F 1 "50k" H 6720 3905 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 6580 3950 50  0001 C CNN
F 3 "~" H 6650 3950 50  0001 C CNN
	1    6650 3950
	1    0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC547 Q1
U 1 1 5E58C98B
P 5850 3950
F 0 "Q1" H 6041 3996 50  0000 L CNN
F 1 "BC547" H 6041 3905 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 6050 3875 50  0001 L CIN
F 3 "http://www.fairchildsemi.com/ds/BC/BC547.pdf" H 5850 3950 50  0001 L CNN
	1    5850 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5E591736
P 6400 3700
F 0 "C2" V 6145 3700 50  0000 C CNN
F 1 "100uF" V 6236 3700 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 6438 3550 50  0001 C CNN
F 3 "~" H 6400 3700 50  0001 C CNN
	1    6400 3700
	0    -1   1    0   
$EndComp
Wire Wire Line
	6250 3700 5950 3700
Wire Wire Line
	5950 3700 5950 3750
Wire Wire Line
	5950 3650 5950 3700
Connection ~ 5950 3700
Wire Wire Line
	6550 3700 6650 3700
Wire Wire Line
	6650 3700 6650 3800
Wire Wire Line
	5650 3950 5450 3950
Wire Wire Line
	5450 3650 5450 3950
Connection ~ 5450 3950
Wire Wire Line
	5450 3950 5300 3950
Wire Wire Line
	5450 4250 5450 3950
Wire Wire Line
	5950 4250 5950 4150
Wire Wire Line
	5950 3350 5950 3250
Wire Wire Line
	5950 3250 5450 3250
Wire Wire Line
	5450 3250 5450 3350
Wire Wire Line
	5450 4550 5450 4650
Wire Wire Line
	5450 4650 5950 4650
Wire Wire Line
	5950 4650 5950 4550
$Comp
L Connector:Screw_Terminal_01x03 J2
U 1 1 5E5983A9
P 4300 4450
F 0 "J2" H 4218 4767 50  0000 C CNN
F 1 "Power" H 4218 4676 50  0000 C CNN
F 2 "Connector_JST:JST_EH_B3B-EH-A_1x03_P2.50mm_Vertical" H 4300 4450 50  0001 C CNN
F 3 "~" H 4300 4450 50  0001 C CNN
	1    4300 4450
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J3
U 1 1 5E59B35E
P 7250 3900
F 0 "J3" H 7330 3892 50  0000 L CNN
F 1 "Out" H 7330 3801 50  0000 L CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 7250 3900 50  0001 C CNN
F 3 "~" H 7250 3900 50  0001 C CNN
	1    7250 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4750 4850 4750
Connection ~ 6650 4750
Wire Wire Line
	4900 3250 5450 3250
Connection ~ 5450 3250
Wire Wire Line
	4900 4650 5450 4650
Connection ~ 5450 4650
Wire Wire Line
	6650 4100 6650 4750
Wire Wire Line
	6900 4750 6650 4750
$Comp
L Device:CP C1
U 1 1 5E5A4FEC
P 5150 3950
F 0 "C1" V 5405 3950 50  0000 C CNN
F 1 "2,2uF" V 5314 3950 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D4.0mm_P2.00mm" H 5188 3800 50  0001 C CNN
F 3 "~" H 5150 3950 50  0001 C CNN
	1    5150 3950
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J1
U 1 1 5E5A65F9
P 4300 3450
F 0 "J1" H 4218 3667 50  0000 C CNN
F 1 "Signal" H 4218 3576 50  0000 C CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 4300 3450 50  0001 C CNN
F 3 "~" H 4300 3450 50  0001 C CNN
	1    4300 3450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4500 3950 4500 3550
Wire Wire Line
	4500 3950 5000 3950
Wire Wire Line
	4900 3250 4900 4450
Wire Wire Line
	4900 4450 4500 4450
Wire Wire Line
	4900 4650 4900 4550
Wire Wire Line
	4900 4550 4500 4550
Wire Wire Line
	4850 4750 4850 4350
Wire Wire Line
	4850 3450 4500 3450
Wire Wire Line
	4500 4350 4850 4350
Connection ~ 4850 4350
Wire Wire Line
	4850 4350 4850 3450
Text Notes 4450 4350 0    50   ~ 0
GND
Text Notes 4450 4450 0    50   ~ 0
+VCC
Text Notes 4450 4550 0    50   ~ 0
-VCC
Text Notes 4450 3450 0    50   ~ 0
GND
Text Notes 4450 3550 0    50   ~ 0
+v
Wire Wire Line
	7050 3900 6900 3900
Wire Wire Line
	6900 3900 6900 3700
Wire Wire Line
	6900 3700 6650 3700
Connection ~ 6650 3700
Wire Wire Line
	6900 4750 6900 4000
Wire Wire Line
	6900 4000 7050 4000
Text Notes 6950 3900 0    50   ~ 0
+v
Text Notes 6950 4000 0    50   ~ 0
GND
Text Notes 7150 6750 0    79   ~ 0
Autor: Lucas Costa
$EndSCHEMATC
