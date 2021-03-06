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
	8900 3950 9000 3950
Wire Wire Line
	9000 5000 9600 5000
Wire Wire Line
	8900 3850 9100 3850
Wire Wire Line
	9100 4900 9600 4900
$Comp
L Display_Character:CC56-12EWA U1
U 1 1 6044A9CC
P 7800 3550
F 0 "U1" H 7800 4217 50  0000 C CNN
F 1 "HS420561K-32" H 7800 4126 50  0000 C CNN
F 2 "Display_7Segment:CA56-12EWA" H 7800 2950 50  0001 C CNN
F 3 "http://www.kingbrightusa.com/images/catalog/SPEC/CA56-12EWA.pdf" H 7370 3580 50  0001 C CNN
	1    7800 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3750 9200 3750
Wire Wire Line
	9200 4800 9600 4800
Wire Wire Line
	8900 3650 9300 3650
Wire Wire Line
	9300 4600 9600 4600
Wire Wire Line
	9600 5700 6600 5700
Wire Wire Line
	6600 5700 6600 3850
Wire Wire Line
	6600 3850 6700 3850
Wire Wire Line
	9600 5600 6500 5600
Wire Wire Line
	6500 5600 6500 3750
Wire Wire Line
	6500 3750 6700 3750
Wire Wire Line
	9600 5500 6400 5500
Wire Wire Line
	6400 5500 6400 3650
Wire Wire Line
	6400 3650 6700 3650
Wire Wire Line
	9600 5400 6300 5400
Wire Wire Line
	6300 5400 6300 3550
Wire Wire Line
	6300 3550 6700 3550
Wire Wire Line
	9600 5300 6200 5300
Wire Wire Line
	6200 5300 6200 3450
Wire Wire Line
	6200 3450 6700 3450
Wire Wire Line
	9600 5200 6100 5200
Wire Wire Line
	6100 5200 6100 3350
Wire Wire Line
	6100 3350 6700 3350
Wire Wire Line
	9600 5100 6000 5100
Wire Wire Line
	6000 5100 6000 3250
Wire Wire Line
	6000 3250 6700 3250
$Comp
L Device:R_US R1
U 1 1 6046CA5C
P 9300 3800
F 0 "R1" H 9368 3846 50  0000 L CNN
F 1 "330 Ω" H 9368 3755 50  0000 L CNN
F 2 "" V 9340 3790 50  0001 C CNN
F 3 "~" H 9300 3800 50  0001 C CNN
	1    9300 3800
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
P 9100 4400
F 0 "R3" H 9168 4446 50  0000 L CNN
F 1 "330 Ω" H 9168 4355 50  0000 L CNN
F 2 "" V 9140 4390 50  0001 C CNN
F 3 "~" H 9100 4400 50  0001 C CNN
	1    9100 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R4
U 1 1 6046ECA8
P 9000 4700
F 0 "R4" H 9068 4746 50  0000 L CNN
F 1 "330 Ω" H 9068 4655 50  0000 L CNN
F 2 "" V 9040 4690 50  0001 C CNN
F 3 "~" H 9000 4700 50  0001 C CNN
	1    9000 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 4600 9300 3950
Wire Wire Line
	9200 3750 9200 3950
Wire Wire Line
	9200 4250 9200 4800
Wire Wire Line
	9100 3850 9100 4250
Wire Wire Line
	9100 4550 9100 4900
Wire Wire Line
	9000 3950 9000 4550
Wire Wire Line
	9000 4850 9000 5000
Wire Wire Line
	10600 5000 10700 5000
Wire Wire Line
	10700 5000 10700 3550
Wire Wire Line
	10700 3550 9900 3550
Wire Wire Line
	9900 3550 9900 3350
Wire Wire Line
	10400 3350 10400 3450
Wire Wire Line
	10400 3450 10800 3450
Wire Wire Line
	10800 3450 10800 5100
Wire Wire Line
	10800 5100 10600 5100
Wire Wire Line
	10200 6100 10200 6200
Wire Wire Line
	10200 6200 10900 6200
Wire Wire Line
	10900 6200 10900 3150
Wire Wire Line
	10050 3150 10050 2850
Wire Wire Line
	10050 2850 10900 2850
Wire Wire Line
	10900 2850 10900 3150
Connection ~ 10900 3150
Wire Wire Line
	10300 4000 10300 3750
Wire Wire Line
	10300 3750 9650 3750
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
$Comp
L power:+5V #PWR?
U 1 1 60490986
P 10400 3750
F 0 "#PWR?" H 10400 3600 50  0001 C CNN
F 1 "+5V" V 10415 3878 50  0000 L CNN
F 2 "" H 10400 3750 50  0001 C CNN
F 3 "" H 10400 3750 50  0001 C CNN
	1    10400 3750
	0    1    1    0   
$EndComp
Text Notes 10900 3600 0    50   ~ 0
GND
Text Notes 10700 3600 0    50   ~ 0
VRy
Text Notes 9650 3600 0    50   ~ 0
+5V
Wire Wire Line
	10400 3750 10300 3750
Connection ~ 10300 3750
Wire Notes Line
	9550 2650 9550 3650
Wire Notes Line
	9550 3650 11000 3650
Wire Notes Line
	11000 3650 11000 2650
Wire Notes Line
	11000 2650 9550 2650
Wire Wire Line
	10900 3150 10550 3150
Text Notes 10800 3750 0    50   ~ 0
VRx
$Comp
L Device:R_POT_Dual J1
U 1 1 6047EFB9
P 10150 3250
F 0 "J1" H 10150 2925 50  0000 C CNN
F 1 "Analog_Joystick_Module" H 10150 3016 50  0000 C CNN
F 2 "" H 10400 3175 50  0001 C CNN
F 3 "~" H 10400 3175 50  0001 C CNN
	1    10150 3250
	1    0    0    1   
$EndComp
$EndSCHEMATC
