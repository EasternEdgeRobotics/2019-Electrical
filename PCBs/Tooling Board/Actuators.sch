EESchema Schematic File Version 4
LIBS:Tooling Board-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 8340 6970 0    197  Italic 39
Actuators
$Sheet
S 2020 1540 2330 2030
U 5C4C657D
F0 "DCMotor1-2" 50
F1 "DCMotor1-2.sch" 50
$EndSheet
Text Notes 2230 2660 0    157  Italic 31
DC Motors 1-2
$Sheet
S 4860 1540 2330 2030
U 5C4D499E
F0 "DCMotor3-4" 50
F1 "DCMotor3-4.sch" 50
$EndSheet
Text Notes 5100 2680 0    157  Italic 31
DC Motors 3-4
Text HLabel 1410 5450 0    50   Input ~ 0
+12V
Wire Wire Line
	1410 5450 1650 5450
Wire Wire Line
	1650 5450 1650 5380
$Comp
L power:+12V #PWR0127
U 1 1 5C4DB93C
P 1650 5380
F 0 "#PWR0127" H 1650 5230 50  0001 C CNN
F 1 "+12V" H 1665 5553 50  0000 C CNN
F 2 "" H 1650 5380 50  0001 C CNN
F 3 "" H 1650 5380 50  0001 C CNN
	1    1650 5380
	1    0    0    -1  
$EndComp
Text Notes 6170 4240 0    79   ~ 16
LED Control 
$Comp
L Connector_Generic:Conn_01x02 J301
U 1 1 5C4DC4EB
P 6140 4740
F 0 "J301" H 6220 4732 50  0000 L CNN
F 1 "Conn_01x02" H 6220 4641 50  0000 L CNN
F 2 "EER:1x2_molex_llc_new" H 6140 4740 50  0001 C CNN
F 3 "~" H 6140 4740 50  0001 C CNN
F 4 "WM4800-ND" H 6140 4740 50  0001 C CNN "Digikey"
	1    6140 4740
	1    0    0    -1  
$EndComp
Wire Wire Line
	5940 4840 5840 4840
$Comp
L power:GND #PWR0128
U 1 1 5C4DC54D
P 5840 5680
F 0 "#PWR0128" H 5840 5430 50  0001 C CNN
F 1 "GND" H 5845 5507 50  0000 C CNN
F 2 "" H 5840 5680 50  0001 C CNN
F 3 "" H 5840 5680 50  0001 C CNN
	1    5840 5680
	1    0    0    -1  
$EndComp
Wire Wire Line
	4820 4740 4820 4620
$Comp
L power:+12V #PWR0129
U 1 1 5C4DC71D
P 4820 4620
F 0 "#PWR0129" H 4820 4470 50  0001 C CNN
F 1 "+12V" H 4835 4793 50  0000 C CNN
F 2 "" H 4820 4620 50  0001 C CNN
F 3 "" H 4820 4620 50  0001 C CNN
	1    4820 4620
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q301
U 1 1 5C4DC8F0
P 5740 5270
F 0 "Q301" H 5945 5316 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 5945 5225 50  0000 L CNN
F 2 "EER:TRANS_DMN2020UFCL-7" H 5940 5370 50  0001 C CNN
F 3 "https://www.digikey.ca/product-detail/en/diodes-incorporated/DMN2020UFCL-7/DMN2020UFCL-7DICT-ND/4794805" H 5740 5270 50  0001 C CNN
	1    5740 5270
	1    0    0    -1  
$EndComp
Wire Wire Line
	5840 4840 5840 5070
Wire Wire Line
	5840 5470 5840 5680
Text GLabel 4940 5270 0    50   Input ~ 0
LED
$Comp
L Connector_Generic:Conn_01x02 J302
U 1 1 5C4DD714
P 8570 4730
F 0 "J302" H 8650 4722 50  0000 L CNN
F 1 "Conn_01x02" H 8650 4631 50  0000 L CNN
F 2 "EER:1x2_molex_llc_new" H 8570 4730 50  0001 C CNN
F 3 "~" H 8570 4730 50  0001 C CNN
F 4 "WM4800-ND" H 8570 4730 50  0001 C CNN "Digikey"
	1    8570 4730
	1    0    0    -1  
$EndComp
Wire Wire Line
	8370 4830 8270 4830
$Comp
L power:GND #PWR0130
U 1 1 5C4DD71B
P 8270 5680
F 0 "#PWR0130" H 8270 5430 50  0001 C CNN
F 1 "GND" H 8275 5507 50  0000 C CNN
F 2 "" H 8270 5680 50  0001 C CNN
F 3 "" H 8270 5680 50  0001 C CNN
	1    8270 5680
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 4730 7250 4610
$Comp
L power:+12V #PWR0131
U 1 1 5C4DD723
P 7250 4610
F 0 "#PWR0131" H 7250 4460 50  0001 C CNN
F 1 "+12V" H 7265 4783 50  0000 C CNN
F 2 "" H 7250 4610 50  0001 C CNN
F 3 "" H 7250 4610 50  0001 C CNN
	1    7250 4610
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NMOS_DGS Q302
U 1 1 5C4DD729
P 8170 5260
F 0 "Q302" H 8375 5306 50  0000 L CNN
F 1 "Q_NMOS_DGS" H 8375 5215 50  0000 L CNN
F 2 "EER:TRANS_DMN2020UFCL-7" H 8370 5360 50  0001 C CNN
F 3 "https://www.digikey.ca/product-detail/en/diodes-incorporated/DMN2020UFCL-7/DMN2020UFCL-7DICT-ND/4794805" H 8170 5260 50  0001 C CNN
	1    8170 5260
	1    0    0    -1  
$EndComp
Wire Wire Line
	8270 4830 8270 5060
Wire Wire Line
	8270 5460 8270 5680
Wire Wire Line
	7250 4730 8370 4730
Wire Wire Line
	4820 4740 5940 4740
Text GLabel 7370 5260 0    50   Input ~ 0
LED
Wire Wire Line
	7370 5260 7970 5260
Wire Wire Line
	4940 5270 5540 5270
$EndSCHEMATC
