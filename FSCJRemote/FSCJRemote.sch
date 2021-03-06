EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 7350 7500 0    50   ~ 0
FSCJ STEM Expo Arduino Project
Text Notes 7000 6700 0    50   ~ 0
Author:\nAerick Stephans
Text Notes 8100 7650 0    50   ~ 0
03/06/2021
$Comp
L Display_Character:CC56-12EWA U1
U 1 1 6044A9CC
P 7450 3550
F 0 "U1" H 7450 4217 50  0000 C CNN
F 1 "HS420561K-32" H 7450 4126 50  0000 C CNN
F 2 "Display_7Segment:CA56-12EWA" H 7450 2950 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CA56-12EWA.pdf" H 7020 3580 50  0001 C CNN
	1    7450 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 5700 6250 3850
Wire Wire Line
	6250 3850 6350 3850
Wire Wire Line
	6150 5600 6150 3750
Wire Wire Line
	6150 3750 6350 3750
Wire Wire Line
	6050 5500 6050 3650
Wire Wire Line
	6050 3650 6350 3650
Wire Wire Line
	5950 5400 5950 3550
Wire Wire Line
	5950 3550 6350 3550
Wire Wire Line
	5850 5300 5850 3450
Wire Wire Line
	5850 3450 6350 3450
Wire Wire Line
	5750 5200 5750 3350
Wire Wire Line
	5750 3350 6350 3350
Wire Wire Line
	5650 5100 5650 3250
Wire Wire Line
	5650 3250 6350 3250
$Comp
L Device:R_US R1
U 1 1 6046CA5C
P 9450 3800
F 0 "R1" H 9518 3846 50  0000 L CNN
F 1 "330 Ω" H 9518 3755 50  0000 L CNN
F 2 "" V 9490 3790 50  0001 C CNN
F 3 "~" H 9450 3800 50  0001 C CNN
	1    9450 3800
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 6046DCBF
P 9200 4100
F 0 "R2" H 9268 4146 50  0000 L CNN
F 1 "330 Ω" H 9268 4055 50  0000 L CNN
F 2 "" V 9240 4090 50  0001 C CNN
F 3 "~" H 9200 4100 50  0001 C CNN
	1    9200 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 6046E3E8
P 8950 4400
F 0 "R3" H 9018 4446 50  0000 L CNN
F 1 "330 Ω" H 9018 4355 50  0000 L CNN
F 2 "" V 8990 4390 50  0001 C CNN
F 3 "~" H 8950 4400 50  0001 C CNN
	1    8950 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R4
U 1 1 6046ECA8
P 8700 4700
F 0 "R4" H 8768 4746 50  0000 L CNN
F 1 "330 Ω" H 8768 4655 50  0000 L CNN
F 2 "" V 8740 4690 50  0001 C CNN
F 3 "~" H 8700 4700 50  0001 C CNN
	1    8700 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4250 9200 4800
Wire Wire Line
	10700 3550 9900 3550
Wire Wire Line
	9900 3550 9900 3350
Wire Wire Line
	10400 3350 10400 3450
Wire Wire Line
	10850 3450 10850 5100
Wire Wire Line
	10200 6100 10200 6200
Wire Wire Line
	10050 3150 10050 2850
Wire Wire Line
	11000 2850 11000 3150
Connection ~ 11000 3150
Wire Wire Line
	9650 3750 9650 3150
Wire Wire Line
	9650 3150 9750 3150
Wire Wire Line
	10250 3150 10250 2750
Wire Wire Line
	10250 2750 9650 2750
Wire Wire Line
	9650 2750 9650 3150
Connection ~ 9650 3150
$Comp
L power:GNDREF #PWR?
U 1 1 604902AF
P 10200 6200
F 0 "#PWR?" H 10200 5950 50  0001 C CNN
F 1 "GNDREF" H 10205 6027 50  0000 C CNN
F 2 "" H 10200 6200 50  0001 C CNN
F 3 "" H 10200 6200 50  0001 C CNN
	1    10200 6200
	1    0    0    -1  
$EndComp
Connection ~ 10200 6200
Text Notes 11000 3600 0    50   ~ 0
GND
Text Notes 10700 3600 0    50   ~ 0
VRy
Text Notes 9650 3600 0    50   ~ 0
+5V
Wire Notes Line
	9550 2650 9550 3650
Wire Notes Line
	11150 3650 11150 2650
Text Notes 10850 3600 0    50   ~ 0
VRx
$Comp
L Device:R_POT_Dual J1
U 1 1 6047EFB9
P 10150 3250
F 0 "J1" H 10150 2925 50  0001 C CNN
F 1 "Analog_Joystick_Module" H 10150 3016 50  0001 C CNN
F 2 "" H 10400 3175 50  0001 C CNN
F 3 "~" H 10400 3175 50  0001 C CNN
	1    10150 3250
	1    0    0    1   
$EndComp
Wire Wire Line
	9650 3750 10450 3750
Connection ~ 10450 4000
Wire Wire Line
	6250 5700 9600 5700
Wire Wire Line
	9200 3950 9200 3750
Wire Wire Line
	9200 3750 8550 3750
Wire Wire Line
	8550 3650 9450 3650
Wire Wire Line
	9450 3950 9450 4600
Wire Wire Line
	8950 4900 8950 4550
Wire Wire Line
	8950 4250 8950 3850
Wire Wire Line
	8950 3850 8550 3850
Wire Wire Line
	8700 5000 8700 4850
Wire Wire Line
	8700 4550 8700 3950
Wire Wire Line
	8700 3950 8550 3950
Wire Wire Line
	10550 3150 11000 3150
Wire Wire Line
	10050 2850 11000 2850
Wire Wire Line
	10400 3450 10850 3450
Wire Wire Line
	10200 6200 11000 6200
Wire Notes Line
	9550 3650 11150 3650
Wire Notes Line
	9550 2650 11150 2650
Wire Wire Line
	10600 5100 10850 5100
Wire Wire Line
	10600 5000 10700 5000
Wire Wire Line
	10450 4000 10300 4000
Wire Wire Line
	10700 5000 10700 3550
Wire Wire Line
	11000 6200 11000 3150
Wire Wire Line
	10450 3750 10450 4000
Wire Wire Line
	6150 5600 9600 5600
Wire Wire Line
	6050 5500 9600 5500
Wire Wire Line
	5950 5400 9600 5400
Wire Wire Line
	5850 5300 9600 5300
Wire Wire Line
	5750 5200 9600 5200
Wire Wire Line
	5650 5100 9600 5100
Wire Wire Line
	9600 5000 8700 5000
Wire Wire Line
	9600 4900 8950 4900
Wire Wire Line
	9200 4800 9600 4800
Wire Wire Line
	9450 4600 9600 4600
$Comp
L power:+5V #PWR?
U 1 1 60490986
P 10600 4000
F 0 "#PWR?" H 10600 3850 50  0001 C CNN
F 1 "+5V" V 10615 4128 50  0000 L CNN
F 2 "" H 10600 4000 50  0001 C CNN
F 3 "" H 10600 4000 50  0001 C CNN
	1    10600 4000
	-1   0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_UNO_R3 A1
U 1 1 60448671
P 10100 5000
F 0 "A1" H 10100 6181 50  0000 C CNN
F 1 "Arduino_UNO_R3" H 10100 6090 50  0000 C CNN
F 2 "Module:Arduino_UNO_R3" H 10100 5000 50  0001 C CIN
F 3 "https://www.arduino.cc/en/Main/arduinoBoardUno" H 10100 5000 50  0001 C CNN
	1    10100 5000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 4000 10600 4000
Text Notes 10600 7650 0    50   ~ 0
2
Text Notes 9950 2600 0    50   ~ 0
Analog_Joystick_Module
Text Notes 10300 2500 0    50   ~ 0
J1
$EndSCHEMATC
