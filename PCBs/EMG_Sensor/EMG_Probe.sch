EESchema Schematic File Version 4
LIBS:EMG_Probe-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "EMG Probe "
Date "2016-10-01"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EMG_Probe-rescue:PWR_FLAG-EMG_Probe-rescue #FLG01
U 1 1 57F02E05
P 5900 7400
F 0 "#FLG01" H 5900 7495 50  0001 C CNN
F 1 "PWR_FLAG" H 5900 7580 50  0000 C CNN
F 2 "" H 5900 7400 50  0000 C CNN
F 3 "" H 5900 7400 50  0000 C CNN
	1    5900 7400
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:PWR_FLAG-EMG_Probe-rescue #FLG02
U 1 1 57F02E17
P 6300 7400
F 0 "#FLG02" H 6300 7495 50  0001 C CNN
F 1 "PWR_FLAG" H 6300 7580 50  0000 C CNN
F 2 "" H 6300 7400 50  0000 C CNN
F 3 "" H 6300 7400 50  0000 C CNN
	1    6300 7400
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:Sensor_Connect-EMG_Probe-rescue J1
U 1 1 57F032E3
P 1400 1350
F 0 "J1" H 1550 900 60  0000 C CNN
F 1 "Sensor_Connect" H 1600 1300 60  0000 C CNN
F 2 "Pin_Headers_2:Header_Angled_03" H 1700 1350 60  0001 C CNN
F 3 "" H 1700 1350 60  0001 C CNN
	1    1400 1350
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:INA126-EMG_Probe-rescue U3
U 1 1 57F03779
P 3000 1550
F 0 "U3" H 3000 1350 60  0000 C CNN
F 1 "INA126" H 3000 1750 60  0000 C CNN
F 2 "Housings_SOIC:SOIC-8_3.9x4.9mm_Pitch1.27mm" H 3050 1550 60  0001 C CNN
F 3 "" H 3050 1550 60  0000 C CNN
	1    3000 1550
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:PWR_FLAG-EMG_Probe-rescue #FLG03
U 1 1 57F0716A
P 6700 7400
F 0 "#FLG03" H 6700 7495 50  0001 C CNN
F 1 "PWR_FLAG" H 6700 7580 50  0000 C CNN
F 2 "" H 6700 7400 50  0000 C CNN
F 3 "" H 6700 7400 50  0000 C CNN
	1    6700 7400
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR04
U 1 1 57F076E1
P 6600 4850
F 0 "#PWR04" H 6600 4600 50  0001 C CNN
F 1 "GND" H 6600 4700 50  0000 C CNN
F 2 "" H 6600 4850 50  0000 C CNN
F 3 "" H 6600 4850 50  0000 C CNN
	1    6600 4850
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R6
U 1 1 57F07990
P 2350 1500
F 0 "R6" V 2430 1500 50  0000 C CNN
F 1 "1.5k" V 2350 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 2280 1500 50  0001 C CNN
F 3 "" H 2350 1500 50  0000 C CNN
	1    2350 1500
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR05
U 1 1 57F09765
P 6700 4750
F 0 "#PWR05" H 6700 4600 50  0001 C CNN
F 1 "VCC" H 6700 4900 50  0000 C CNN
F 2 "" H 6700 4750 50  0000 C CNN
F 3 "" H 6700 4750 50  0000 C CNN
	1    6700 4750
	0    -1   -1   0   
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR06
U 1 1 57F0979A
P 6700 4650
F 0 "#PWR06" H 6700 4500 50  0001 C CNN
F 1 "VSS" H 6700 4800 50  0000 C CNN
F 2 "" H 6700 4650 50  0000 C CNN
F 3 "" H 6700 4650 50  0000 C CNN
	1    6700 4650
	0    -1   -1   0   
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR07
U 1 1 57F09A9F
P 5900 7500
F 0 "#PWR07" H 5900 7350 50  0001 C CNN
F 1 "VCC" H 5900 7650 50  0000 C CNN
F 2 "" H 5900 7500 50  0000 C CNN
F 3 "" H 5900 7500 50  0000 C CNN
	1    5900 7500
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR08
U 1 1 57F09ABD
P 6300 7500
F 0 "#PWR08" H 6300 7350 50  0001 C CNN
F 1 "VSS" H 6300 7650 50  0000 C CNN
F 2 "" H 6300 7500 50  0000 C CNN
F 3 "" H 6300 7500 50  0000 C CNN
	1    6300 7500
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR09
U 1 1 57F09ADB
P 6700 7500
F 0 "#PWR09" H 6700 7250 50  0001 C CNN
F 1 "GND" H 6700 7350 50  0000 C CNN
F 2 "" H 6700 7500 50  0000 C CNN
F 3 "" H 6700 7500 50  0000 C CNN
	1    6700 7500
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR010
U 1 1 57F09CF7
P 3000 800
F 0 "#PWR010" H 3000 650 50  0001 C CNN
F 1 "VCC" H 3000 950 50  0000 C CNN
F 2 "" H 3000 800 50  0000 C CNN
F 3 "" H 3000 800 50  0000 C CNN
	1    3000 800 
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR011
U 1 1 57F09D15
P 3000 2250
F 0 "#PWR011" H 3000 2100 50  0001 C CNN
F 1 "VSS" H 3000 2400 50  0000 C CNN
F 2 "" H 3000 2250 50  0000 C CNN
F 3 "" H 3000 2250 50  0000 C CNN
	1    3000 2250
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR012
U 1 1 57F07964
P 1900 2100
F 0 "#PWR012" H 1900 1850 50  0001 C CNN
F 1 "GND" H 1900 1950 50  0001 C CNN
F 2 "" H 1900 2100 50  0000 C CNN
F 3 "" H 1900 2100 50  0000 C CNN
	1    1900 2100
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C1
U 1 1 57F0A6AD
P 3850 1300
F 0 "C1" H 3875 1400 50  0000 L CNN
F 1 "220n" H 3875 1200 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 3888 1150 50  0001 C CNN
F 3 "" H 3850 1300 50  0000 C CNN
	1    3850 1300
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R8
U 1 1 57F0ACF0
P 4150 1550
F 0 "R8" V 4230 1550 50  0000 C CNN
F 1 "100k" V 4150 1550 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4080 1550 50  0001 C CNN
F 3 "" H 4150 1550 50  0000 C CNN
	1    4150 1550
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR013
U 1 1 57F0ADED
P 4150 1800
F 0 "#PWR013" H 4150 1550 50  0001 C CNN
F 1 "GND" H 4150 1650 50  0001 C CNN
F 2 "" H 4150 1800 50  0000 C CNN
F 3 "" H 4150 1800 50  0000 C CNN
	1    4150 1800
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR014
U 1 1 57F0B235
P 4700 1100
F 0 "#PWR014" H 4700 950 50  0001 C CNN
F 1 "VCC" H 4700 1250 50  0000 C CNN
F 2 "" H 4700 1100 50  0000 C CNN
F 3 "" H 4700 1100 50  0000 C CNN
	1    4700 1100
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR015
U 1 1 57F0B300
P 4700 1700
F 0 "#PWR015" H 4700 1550 50  0001 C CNN
F 1 "VSS" H 4700 1850 50  0000 C CNN
F 2 "" H 4700 1700 50  0000 C CNN
F 3 "" H 4700 1700 50  0000 C CNN
	1    4700 1700
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R10
U 1 1 57F0B5DD
P 4900 2000
F 0 "R10" V 4980 2000 50  0000 C CNN
F 1 "100k" V 4900 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4830 2000 50  0001 C CNN
F 3 "" H 4900 2000 50  0000 C CNN
	1    4900 2000
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R13
U 1 1 57F0B798
P 4500 2250
F 0 "R13" V 4580 2250 50  0000 C CNN
F 1 "2k2" V 4500 2250 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4430 2250 50  0001 C CNN
F 3 "" H 4500 2250 50  0000 C CNN
	1    4500 2250
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR016
U 1 1 57F0BA86
P 4500 2450
F 0 "#PWR016" H 4500 2200 50  0001 C CNN
F 1 "GND" H 4500 2300 50  0001 C CNN
F 2 "" H 4500 2450 50  0000 C CNN
F 3 "" H 4500 2450 50  0000 C CNN
	1    4500 2450
	1    0    0    -1  
$EndComp
Text Notes 2400 3250 0    60   ~ 0
Signal Aquisition (60 Gain)\n
Text Notes 4100 3450 0    60   ~ 0
Band Pass Filter \n(200 Gain /  7Hz and 330 HZ Cut Off)\nTakes Out DC-Offset and high Freq Noise
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R3
U 1 1 57F0F42C
P 5550 1300
F 0 "R3" V 5630 1300 50  0000 C CNN
F 1 "2k2" V 5550 1300 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5480 1300 50  0001 C CNN
F 3 "" H 5550 1300 50  0000 C CNN
	1    5550 1300
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C4
U 1 1 57F0FC3B
P 5800 1550
F 0 "C4" H 5825 1650 50  0000 L CNN
F 1 "220n" H 5825 1450 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5838 1400 50  0001 C CNN
F 3 "" H 5800 1550 50  0000 C CNN
	1    5800 1550
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR017
U 1 1 57F0FCFA
P 5800 1800
F 0 "#PWR017" H 5800 1550 50  0001 C CNN
F 1 "GND" H 5800 1650 50  0001 C CNN
F 2 "" H 5800 1800 50  0000 C CNN
F 3 "" H 5800 1800 50  0000 C CNN
	1    5800 1800
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R7
U 1 1 57F133D3
P 6400 1500
F 0 "R7" V 6480 1500 50  0000 C CNN
F 1 "10k" V 6400 1500 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6330 1500 50  0001 C CNN
F 3 "" H 6400 1500 50  0000 C CNN
	1    6400 1500
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR018
U 1 1 57F13782
P 7000 1100
F 0 "#PWR018" H 7000 950 50  0001 C CNN
F 1 "VCC" H 7000 1250 50  0000 C CNN
F 2 "" H 7000 1100 50  0000 C CNN
F 3 "" H 7000 1100 50  0000 C CNN
	1    7000 1100
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR019
U 1 1 57F13938
P 7000 1700
F 0 "#PWR019" H 7000 1550 50  0001 C CNN
F 1 "VSS" H 7000 1850 50  0000 C CNN
F 2 "" H 7000 1700 50  0000 C CNN
F 3 "" H 7000 1700 50  0000 C CNN
	1    7000 1700
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R1
U 1 1 57F13D1F
P 7000 750
F 0 "R1" V 7080 750 50  0000 C CNN
F 1 "68k" V 7000 750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6930 750 50  0001 C CNN
F 3 "" H 7000 750 50  0000 C CNN
	1    7000 750 
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C3
U 1 1 57F1462C
P 7650 1400
F 0 "C3" H 7675 1500 50  0000 L CNN
F 1 "47n" H 7675 1300 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 7688 1250 50  0001 C CNN
F 3 "" H 7650 1400 50  0000 C CNN
	1    7650 1400
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R11
U 1 1 57F1570A
P 7000 2000
F 0 "R11" V 7080 2000 50  0000 C CNN
F 1 "10k" V 7000 2000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6930 2000 50  0001 C CNN
F 3 "" H 7000 2000 50  0000 C CNN
	1    7000 2000
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C2
U 1 1 57F16D59
P 6350 1300
F 0 "C2" H 6375 1400 50  0000 L CNN
F 1 "47n" H 6375 1200 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6388 1150 50  0001 C CNN
F 3 "" H 6350 1300 50  0000 C CNN
	1    6350 1300
	0    -1   -1   0   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R9
U 1 1 57F171D8
P 6600 1800
F 0 "R9" V 6680 1800 50  0000 C CNN
F 1 "68k" V 6600 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 6530 1800 50  0001 C CNN
F 3 "" H 6600 1800 50  0000 C CNN
	1    6600 1800
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR020
U 1 1 57F182B2
P 6600 2050
F 0 "#PWR020" H 6600 1800 50  0001 C CNN
F 1 "GND" H 6600 1900 50  0001 C CNN
F 2 "" H 6600 2050 50  0000 C CNN
F 3 "" H 6600 2050 50  0000 C CNN
	1    6600 2050
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR021
U 1 1 57F274FB
P 9450 1200
F 0 "#PWR021" H 9450 1050 50  0001 C CNN
F 1 "VCC" H 9450 1350 50  0000 C CNN
F 2 "" H 9450 1200 50  0000 C CNN
F 3 "" H 9450 1200 50  0000 C CNN
	1    9450 1200
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR022
U 1 1 57F2753B
P 9450 1800
F 0 "#PWR022" H 9450 1650 50  0001 C CNN
F 1 "VSS" H 9450 1950 50  0000 C CNN
F 2 "" H 9450 1800 50  0000 C CNN
F 3 "" H 9450 1800 50  0000 C CNN
	1    9450 1800
	-1   0    0    1   
$EndComp
Text Notes 9050 3300 0    60   ~ 0
Precision Rectifier\n
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R15
U 1 1 57F3CBF0
P 2050 4750
F 0 "R15" V 2130 4750 50  0000 C CNN
F 1 "100k" V 2050 4750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1980 4750 50  0001 C CNN
F 3 "" H 2050 4750 50  0000 C CNN
	1    2050 4750
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C5
U 1 1 57F3D445
P 2300 4900
F 0 "C5" H 2325 5000 50  0000 L CNN
F 1 "220n" H 2325 4800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2338 4750 50  0001 C CNN
F 3 "" H 2300 4900 50  0000 C CNN
	1    2300 4900
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C6
U 1 1 57F3DD4B
P 2600 4900
F 0 "C6" H 2625 5000 50  0000 L CNN
F 1 "220n" H 2625 4800 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2638 4750 50  0001 C CNN
F 3 "" H 2600 4900 50  0000 C CNN
	1    2600 4900
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR023
U 1 1 57F3DF9F
P 2450 5150
F 0 "#PWR023" H 2450 4900 50  0001 C CNN
F 1 "GND" H 2450 5000 50  0001 C CNN
F 2 "" H 2450 5150 50  0000 C CNN
F 3 "" H 2450 5150 50  0000 C CNN
	1    2450 5150
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR024
U 1 1 57F40707
P 3250 4550
F 0 "#PWR024" H 3250 4400 50  0001 C CNN
F 1 "VCC" H 3250 4700 50  0000 C CNN
F 2 "" H 3250 4550 50  0000 C CNN
F 3 "" H 3250 4550 50  0000 C CNN
	1    3250 4550
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VSS-EMG_Probe-rescue #PWR025
U 1 1 57F409D0
P 3250 5150
F 0 "#PWR025" H 3250 5000 50  0001 C CNN
F 1 "VSS" H 3250 5300 50  0000 C CNN
F 2 "" H 3250 5150 50  0000 C CNN
F 3 "" H 3250 5150 50  0000 C CNN
	1    3250 5150
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R16
U 1 1 57F42FE0
P 3450 5450
F 0 "R16" V 3530 5450 50  0000 C CNN
F 1 "100k" V 3450 5450 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 3380 5450 50  0001 C CNN
F 3 "" H 3450 5450 50  0000 C CNN
	1    3450 5450
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR026
U 1 1 57F47A11
P 2700 5800
F 0 "#PWR026" H 2700 5550 50  0001 C CNN
F 1 "GND" H 2700 5650 50  0001 C CNN
F 2 "" H 2700 5800 50  0000 C CNN
F 3 "" H 2700 5800 50  0000 C CNN
	1    2700 5800
	1    0    0    -1  
$EndComp
Text Notes 2050 6450 0    60   ~ 0
Low Pass (Variable Gain 10-50)\nSmoothing Signal
Text Notes 6550 3350 0    60   ~ 0
Notch Filter (50Hz)\nFilters Out Mains Noise
Text GLabel 10600 1500 2    60   UnSpc ~ 0
Signal
Text GLabel 1650 4750 0    60   UnSpc ~ 0
Signal
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR027
U 1 1 57F79E64
P 3700 1850
F 0 "#PWR027" H 3700 1600 50  0001 C CNN
F 1 "GND" H 3700 1700 50  0001 C CNN
F 2 "" H 3700 1850 50  0000 C CNN
F 3 "" H 3700 1850 50  0000 C CNN
	1    3700 1850
	1    0    0    -1  
$EndComp
Text GLabel 8200 3400 2    60   UnSpc ~ 0
Raw_Output
Text GLabel 8850 3750 0    60   UnSpc ~ 0
Ard_Output
Text GLabel 8850 3950 0    60   UnSpc ~ 0
Raw_Output
$Comp
L EMG_Probe-rescue:POT-RESCUE-EMG_Probe-EMG_Probe-rescue RV1
U 1 1 57FAC0C9
P 2950 5700
F 0 "RV1" H 2950 5620 50  0000 C CNN
F 1 "POT" H 2950 5700 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer-EVM3E" H 2950 5700 50  0001 C CNN
F 3 "" H 2950 5700 50  0000 C CNN
	1    2950 5700
	0    -1   -1   0   
$EndComp
$Comp
L EMG_Probe-rescue:D-EMG_Probe-rescue D2
U 1 1 57F2D331
P 10150 1500
F 0 "D2" H 10150 1600 50  0000 C CNN
F 1 "D" H 10150 1400 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 10150 1500 50  0001 C CNN
F 3 "" H 10150 1500 50  0000 C CNN
	1    10150 1500
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R2
U 1 1 591F84CC
P 8450 1600
F 0 "R2" V 8530 1600 50  0000 C CNN
F 1 "22k" V 8450 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 8380 1600 50  0001 C CNN
F 3 "" H 8450 1600 50  0001 C CNN
	1    8450 1600
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR028
U 1 1 591F9CC1
P 9100 1450
F 0 "#PWR028" H 9100 1200 50  0001 C CNN
F 1 "GND" H 9100 1300 50  0000 C CNN
F 2 "" H 9100 1450 50  0001 C CNN
F 3 "" H 9100 1450 50  0001 C CNN
	1    9100 1450
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R4
U 1 1 591F9D9C
P 9300 750
F 0 "R4" V 9380 750 50  0000 C CNN
F 1 "100k" V 9300 750 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 9230 750 50  0001 C CNN
F 3 "" H 9300 750 50  0001 C CNN
	1    9300 750 
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:D-EMG_Probe-rescue D1
U 1 1 591FA185
P 9650 900
F 0 "D1" H 9650 1000 50  0000 C CNN
F 1 "D" H 9650 800 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-323_HandSoldering" H 9650 900 50  0001 C CNN
F 3 "" H 9650 900 50  0001 C CNN
	1    9650 900 
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR029
U 1 1 591FFD7B
P 7250 5950
F 0 "#PWR029" H 7250 5700 50  0001 C CNN
F 1 "GND" H 7250 5800 50  0001 C CNN
F 2 "" H 7250 5950 50  0001 C CNN
F 3 "" H 7250 5950 50  0001 C CNN
	1    7250 5950
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR030
U 1 1 5920002A
P 7250 5450
F 0 "#PWR030" H 7250 5300 50  0001 C CNN
F 1 "VCC" H 7250 5600 50  0000 C CNN
F 2 "" H 7250 5450 50  0001 C CNN
F 3 "" H 7250 5450 50  0001 C CNN
	1    7250 5450
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:TLV274-EMG_Probe-rescue U1
U 2 1 5921D3AB
P 9550 1500
F 0 "U1" H 9550 1700 50  0000 L CNN
F 1 "TLV274" H 9550 1300 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 9500 1600 50  0001 C CNN
F 3 "" H 9600 1700 50  0001 C CNN
	2    9550 1500
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:TLV274-EMG_Probe-rescue U1
U 3 1 5921D860
P 3350 4850
F 0 "U1" H 3350 5050 50  0000 L CNN
F 1 "TLV274" H 3350 4650 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 3300 4950 50  0001 C CNN
F 3 "" H 3400 5050 50  0001 C CNN
	3    3350 4850
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:TLV274-EMG_Probe-rescue U1
U 4 1 5921D959
P 4800 1400
F 0 "U1" H 4800 1600 50  0000 L CNN
F 1 "TLV274" H 4800 1200 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 4750 1500 50  0001 C CNN
F 3 "" H 4850 1600 50  0001 C CNN
	4    4800 1400
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:TLV274-EMG_Probe-rescue U1
U 1 1 5921DE68
P 7100 1400
F 0 "U1" H 7100 1600 50  0000 L CNN
F 1 "TLV274" H 7100 1200 50  0000 L CNN
F 2 "Housings_SOIC:SOIC-14_3.9x8.7mm_Pitch1.27mm" H 7050 1500 50  0001 C CNN
F 3 "" H 7150 1600 50  0001 C CNN
	1    7100 1400
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:ATTINY85-20SU-EMG_Probe-rescue U2
U 1 1 5921E7EF
P 5800 5700
F 0 "U2" H 4650 6100 50  0000 C CNN
F 1 "ATTINY85-20SU" H 6800 5300 50  0000 C CNN
F 2 "Housings_SOIC:SOIJ-8_5.3x5.3mm_Pitch1.27mm" H 6750 5700 50  0001 C CIN
F 3 "" H 5800 5700 50  0001 C CNN
	1    5800 5700
	1    0    0    -1  
$EndComp
Text GLabel 4300 5450 0    60   Input ~ 0
SDA
Text GLabel 4300 5650 0    60   Input ~ 0
SCL
Text GLabel 6400 4850 0    60   Output ~ 0
SDA
Text GLabel 6400 5150 0    60   Output ~ 0
SCL
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R5
U 1 1 592EE490
P 1900 1350
F 0 "R5" V 1980 1350 50  0000 C CNN
F 1 "100k" V 1900 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1830 1350 50  0001 C CNN
F 3 "" H 1900 1350 50  0000 C CNN
	1    1900 1350
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R20
U 1 1 592EE511
P 2050 1600
F 0 "R20" V 2130 1600 50  0000 C CNN
F 1 "100k" V 2050 1600 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1980 1600 50  0001 C CNN
F 3 "" H 2050 1600 50  0000 C CNN
	1    2050 1600
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R21
U 1 1 592EE6B4
P 1900 1850
F 0 "R21" V 1980 1850 50  0000 C CNN
F 1 "100k" V 1900 1850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 1830 1850 50  0001 C CNN
F 3 "" H 1900 1850 50  0000 C CNN
	1    1900 1850
	1    0    0    -1  
$EndComp
NoConn ~ 2950 5550
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR031
U 1 1 592FB593
P 3950 6150
F 0 "#PWR031" H 3950 6000 50  0001 C CNN
F 1 "VCC" H 3950 6300 50  0000 C CNN
F 2 "" H 3950 6150 50  0000 C CNN
F 3 "" H 3950 6150 50  0000 C CNN
	1    3950 6150
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C7
U 1 1 59300199
P 6050 6800
F 0 "C7" H 6075 6900 50  0000 L CNN
F 1 "100n" H 6075 6700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6088 6650 50  0001 C CNN
F 3 "" H 6050 6800 50  0000 C CNN
	1    6050 6800
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C8
U 1 1 59300236
P 6350 6800
F 0 "C8" H 6375 6900 50  0000 L CNN
F 1 "100n" H 6375 6700 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 6388 6650 50  0001 C CNN
F 3 "" H 6350 6800 50  0000 C CNN
	1    6350 6800
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C9
U 1 1 593015BE
P 3400 850
F 0 "C9" H 3425 950 50  0000 L CNN
F 1 "100n" H 3425 750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3438 700 50  0001 C CNN
F 3 "" H 3400 850 50  0000 C CNN
	1    3400 850 
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:CONN_01X02-EMG_Probe-rescue P1
U 1 1 59373C1E
P 9500 4350
F 0 "P1" H 9500 4500 50  0000 C CNN
F 1 "CONN_01X02" V 9600 4350 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 9500 4350 50  0001 C CNN
F 3 "" H 9500 4350 50  0000 C CNN
	1    9500 4350
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:CONN_02X04-EMG_Probe-rescue P2
U 1 1 59375746
P 6950 4700
F 0 "P2" H 6950 4950 50  0000 C CNN
F 1 "CONN_02X04" H 6950 4450 50  0000 C CNN
F 2 "Micro_Match:Micro_Match_02x04" H 6950 3500 50  0001 C CNN
F 3 "" H 6950 3500 50  0000 C CNN
	1    6950 4700
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:SW_PUSH-EMG_Probe-rescue SW2
U 1 1 59378353
P 5650 4650
F 0 "SW2" H 5800 4760 50  0000 C CNN
F 1 "SW_PUSH" H 5650 4570 50  0000 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_SKQG" H 5650 4650 50  0001 C CNN
F 3 "" H 5650 4650 50  0000 C CNN
	1    5650 4650
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R12
U 1 1 5937A1E8
P 6000 4850
F 0 "R12" V 6080 4850 50  0000 C CNN
F 1 "10k" V 6000 4850 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 5930 4850 50  0001 C CNN
F 3 "" H 6000 4850 50  0000 C CNN
	1    6000 4850
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR032
U 1 1 5937A88E
P 5250 4600
F 0 "#PWR032" H 5250 4350 50  0001 C CNN
F 1 "GND" H 5250 4450 50  0000 C CNN
F 2 "" H 5250 4600 50  0000 C CNN
F 3 "" H 5250 4600 50  0000 C CNN
	1    5250 4600
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:VCC-EMG_Probe-rescue #PWR033
U 1 1 5937AAD7
P 6000 5050
F 0 "#PWR033" H 6000 4900 50  0001 C CNN
F 1 "VCC" H 6000 5200 50  0000 C CNN
F 2 "" H 6000 5050 50  0000 C CNN
F 3 "" H 6000 5050 50  0000 C CNN
	1    6000 5050
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D3
U 1 1 5937CE2C
P 10050 5000
F 0 "D3" H 10050 5100 50  0000 C CNN
F 1 "LED" H 10050 4900 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10050 5000 50  0001 C CNN
F 3 "" H 10050 5000 50  0000 C CNN
	1    10050 5000
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D4
U 1 1 5937CF56
P 10400 5100
F 0 "D4" H 10400 5200 50  0000 C CNN
F 1 "LED" H 10400 5000 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10400 5100 50  0001 C CNN
F 3 "" H 10400 5100 50  0000 C CNN
	1    10400 5100
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D5
U 1 1 5937CFFF
P 10050 5200
F 0 "D5" H 10050 5300 50  0000 C CNN
F 1 "LED" H 10050 5100 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10050 5200 50  0001 C CNN
F 3 "" H 10050 5200 50  0000 C CNN
	1    10050 5200
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D6
U 1 1 5937D0AC
P 10400 5300
F 0 "D6" H 10400 5400 50  0000 C CNN
F 1 "LED" H 10400 5200 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10400 5300 50  0001 C CNN
F 3 "" H 10400 5300 50  0000 C CNN
	1    10400 5300
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D7
U 1 1 5937D1B0
P 10050 5400
F 0 "D7" H 10050 5500 50  0000 C CNN
F 1 "LED" H 10050 5300 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10050 5400 50  0001 C CNN
F 3 "" H 10050 5400 50  0000 C CNN
	1    10050 5400
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D8
U 1 1 5937D25B
P 10400 5500
F 0 "D8" H 10400 5600 50  0000 C CNN
F 1 "LED" H 10400 5400 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10400 5500 50  0001 C CNN
F 3 "" H 10400 5500 50  0000 C CNN
	1    10400 5500
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D9
U 1 1 5937D309
P 10050 5600
F 0 "D9" H 10050 5700 50  0000 C CNN
F 1 "LED" H 10050 5500 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10050 5600 50  0001 C CNN
F 3 "" H 10050 5600 50  0000 C CNN
	1    10050 5600
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:LED-RESCUE-EMG_Probe-EMG_Probe-rescue D10
U 1 1 5937D3BC
P 10350 5700
F 0 "D10" H 10350 5800 50  0000 C CNN
F 1 "LED" H 10350 5600 50  0001 C CNN
F 2 "LEDs:LED_0603" H 10350 5700 50  0001 C CNN
F 3 "" H 10350 5700 50  0000 C CNN
	1    10350 5700
	-1   0    0    1   
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R14
U 1 1 59380BDC
P 10700 6150
F 0 "R14" V 10780 6150 50  0000 C CNN
F 1 "470" V 10700 6150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 10630 6150 50  0001 C CNN
F 3 "" H 10700 6150 50  0000 C CNN
	1    10700 6150
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR034
U 1 1 59380D99
P 10700 6350
F 0 "#PWR034" H 10700 6100 50  0001 C CNN
F 1 "GND" H 10700 6200 50  0001 C CNN
F 2 "" H 10700 6350 50  0000 C CNN
F 3 "" H 10700 6350 50  0000 C CNN
	1    10700 6350
	1    0    0    -1  
$EndComp
NoConn ~ 6700 4550
Text GLabel 4100 4850 2    60   UnSpc ~ 0
Ard_Output
$Comp
L EMG_Probe-rescue:74HC595-EMG_Probe-rescue U5
U 1 1 5943C478
P 8900 5450
F 0 "U5" H 9050 6050 50  0000 C CNN
F 1 "74HC595" H 8900 4850 50  0000 C CNN
F 2 "Housings_SSOP:SSOP-16_5.3x6.2mm_Pitch0.65mm" H 8900 5450 50  0001 C CNN
F 3 "" H 8900 5450 50  0001 C CNN
	1    8900 5450
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R17
U 1 1 59452263
P 7950 5000
F 0 "R17" V 8030 5000 50  0000 C CNN
F 1 "1k5" V 7950 5000 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7880 5000 50  0001 C CNN
F 3 "" H 7950 5000 50  0001 C CNN
	1    7950 5000
	0    1    1    0   
$EndComp
$Comp
L EMG_Probe-rescue:C-EMG_Probe-rescue C10
U 1 1 59452535
P 8150 4750
F 0 "C10" H 8175 4850 50  0000 L CNN
F 1 "100n" H 8175 4650 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8188 4600 50  0001 C CNN
F 3 "" H 8150 4750 50  0001 C CNN
	1    8150 4750
	1    0    0    -1  
$EndComp
$Comp
L EMG_Probe-rescue:GND-EMG_Probe-rescue #PWR035
U 1 1 59453523
P 7900 5700
F 0 "#PWR035" H 7900 5450 50  0001 C CNN
F 1 "GND" H 7900 5550 50  0001 C CNN
F 2 "" H 7900 5700 50  0001 C CNN
F 3 "" H 7900 5700 50  0001 C CNN
	1    7900 5700
	1    0    0    -1  
$EndComp
NoConn ~ 9600 5900
Wire Wire Line
	5900 7400 5900 7450
Wire Wire Line
	6300 7400 6300 7450
Wire Wire Line
	6700 7400 6700 7450
Wire Wire Line
	2350 1350 2400 1350
Wire Wire Line
	2350 1650 2350 1700
Wire Wire Line
	2350 1700 2400 1700
Wire Wire Line
	3600 1300 3700 1300
Wire Wire Line
	5100 1400 5200 1400
Wire Wire Line
	5200 1300 5200 1400
Wire Wire Line
	5200 2000 5050 2000
Connection ~ 5200 1400
Wire Wire Line
	4750 2000 4500 2000
Wire Wire Line
	4500 1500 4500 2000
Connection ~ 4500 2000
Wire Wire Line
	4500 2400 4500 2450
Wire Notes Line
	3650 1600 4050 1600
Wire Notes Line
	4050 1600 4050 3100
Wire Notes Line
	3650 650  3650 1600
Wire Notes Line
	3600 650  3600 1650
Wire Notes Line
	3600 1650 4000 1650
Wire Notes Line
	4000 1650 4000 3100
Wire Notes Line
	4000 3100 2150 3100
Wire Notes Line
	2150 650  3600 650 
Wire Wire Line
	5200 1300 5400 1300
Wire Wire Line
	5700 1300 5800 1300
Wire Wire Line
	4000 1300 4150 1300
Wire Wire Line
	4150 1300 4150 1400
Connection ~ 4150 1300
Wire Wire Line
	5800 1300 5800 1400
Connection ~ 5800 1300
Wire Wire Line
	5800 1700 5800 1800
Wire Notes Line
	3650 650  5950 650 
Wire Notes Line
	4050 3100 5950 3100
Wire Notes Line
	5950 3100 5950 650 
Wire Wire Line
	6150 750  6150 1300
Wire Wire Line
	6150 750  6850 750 
Wire Wire Line
	7400 1400 7450 1400
Wire Wire Line
	7850 1400 7850 750 
Wire Wire Line
	7850 750  7150 750 
Connection ~ 7850 1400
Wire Wire Line
	7450 2000 7450 1400
Wire Wire Line
	7150 2000 7450 2000
Connection ~ 7450 1400
Wire Wire Line
	6550 1500 6750 1500
Wire Wire Line
	6850 2000 6750 2000
Wire Wire Line
	6750 2000 6750 1500
Connection ~ 6750 1500
Wire Wire Line
	6500 1300 6600 1300
Connection ~ 6150 1300
Wire Wire Line
	6600 1300 6600 1650
Connection ~ 6600 1300
Wire Wire Line
	4150 1700 4150 1800
Wire Wire Line
	6600 1950 6600 2050
Wire Notes Line
	6050 650  6050 3100
Wire Notes Line
	6050 3100 7950 3100
Wire Notes Line
	7950 3100 7950 650 
Wire Notes Line
	7950 650  6050 650 
Wire Notes Line
	8050 650  8050 3100
Wire Notes Line
	10500 3100 10500 650 
Wire Wire Line
	2200 4750 2300 4750
Connection ~ 2300 4750
Connection ~ 2600 4750
Wire Wire Line
	2300 5050 2450 5050
Wire Wire Line
	2450 5050 2450 5150
Connection ~ 2450 5050
Wire Wire Line
	3050 4950 2950 4950
Wire Wire Line
	3650 4850 3750 4850
Wire Wire Line
	3750 4850 3750 5450
Wire Wire Line
	3750 5450 3600 5450
Connection ~ 3750 4850
Wire Wire Line
	2950 5450 3150 5450
Wire Notes Line
	1700 3900 1700 6150
Wire Notes Line
	1700 6150 3850 6150
Wire Notes Line
	3850 6150 3850 3900
Wire Notes Line
	3850 3900 1700 3900
Wire Notes Line
	8050 3100 10500 3100
Wire Notes Line
	10500 650  8050 650 
Wire Wire Line
	1650 4750 1900 4750
Wire Wire Line
	6150 1500 6250 1500
Wire Wire Line
	3600 1750 3700 1750
Wire Wire Line
	3700 1750 3700 1850
Wire Wire Line
	8000 1400 8000 3400
Wire Wire Line
	8000 3400 8200 3400
Connection ~ 8000 1400
Wire Wire Line
	2800 5700 2700 5700
Wire Wire Line
	2700 5700 2700 5800
Wire Wire Line
	7800 1400 7850 1400
Wire Wire Line
	8800 750  8800 900 
Wire Wire Line
	8600 1600 8800 1600
Wire Wire Line
	9250 1400 9100 1400
Wire Wire Line
	9100 1400 9100 1450
Wire Wire Line
	8800 750  9150 750 
Wire Wire Line
	9450 750  10350 750 
Wire Wire Line
	9850 1500 9950 1500
Wire Wire Line
	8800 900  9500 900 
Connection ~ 8800 900 
Wire Wire Line
	9800 900  9950 900 
Wire Wire Line
	9950 900  9950 1500
Connection ~ 9950 1500
Wire Wire Line
	10300 1500 10350 1500
Wire Wire Line
	8200 1400 8200 1600
Wire Wire Line
	8200 1600 8300 1600
Connection ~ 8800 1600
Wire Notes Line
	4000 6150 7400 6150
Wire Notes Line
	4000 6150 4000 3900
Wire Notes Line
	7400 6150 7400 3900
Wire Wire Line
	7150 5450 7250 5450
Wire Wire Line
	7150 5950 7250 5950
Wire Wire Line
	4300 5650 4450 5650
Wire Wire Line
	4450 5450 4300 5450
Wire Wire Line
	6550 4950 7300 4950
Wire Wire Line
	6550 4950 6550 4850
Wire Wire Line
	6550 4850 6400 4850
Wire Wire Line
	6600 4850 6700 4850
Wire Wire Line
	3850 5850 4450 5850
Wire Wire Line
	4400 5550 4450 5550
Wire Wire Line
	3950 5750 4450 5750
Wire Wire Line
	7300 4950 7300 4850
Wire Wire Line
	7300 4850 7200 4850
Wire Notes Line
	2150 3100 2150 650 
Wire Wire Line
	2300 1200 2300 1850
Wire Wire Line
	2300 1850 2400 1850
Wire Wire Line
	2200 1600 2200 1200
Wire Wire Line
	1900 2000 1900 2100
Wire Wire Line
	2950 4950 2950 5450
Wire Wire Line
	3150 5450 3150 5850
Wire Wire Line
	3150 5850 2950 5850
Connection ~ 3150 5450
Wire Wire Line
	10350 750  10350 1500
Connection ~ 10350 1500
Wire Wire Line
	5900 7450 5650 7450
Wire Wire Line
	5650 7450 5650 6950
Wire Wire Line
	5650 6950 6050 6950
Connection ~ 5900 7450
Wire Wire Line
	6050 6650 6350 6650
Wire Wire Line
	6900 6650 6900 7450
Wire Wire Line
	6900 7450 6700 7450
Connection ~ 6700 7450
Connection ~ 6350 6650
Wire Wire Line
	6300 7450 6450 7450
Wire Wire Line
	6450 7450 6450 7050
Wire Wire Line
	6450 7050 6350 7050
Wire Wire Line
	6350 7050 6350 6950
Connection ~ 6300 7450
Wire Wire Line
	3550 850  3550 2200
Wire Wire Line
	3000 800  3000 850 
Wire Wire Line
	3250 850  3000 850 
Connection ~ 3000 850 
Wire Wire Line
	3000 2150 3000 2200
Wire Wire Line
	3550 2200 3000 2200
Connection ~ 3000 2200
Wire Wire Line
	9100 3950 9100 4400
Wire Wire Line
	3950 6150 3950 5950
Wire Wire Line
	3950 5950 4000 5950
Wire Wire Line
	4300 5950 4350 5950
Wire Wire Line
	7600 6300 4350 6300
Wire Wire Line
	4350 6300 4350 5950
Connection ~ 4350 5950
Wire Wire Line
	7200 4650 7600 4650
Wire Wire Line
	9150 4300 9250 4300
Wire Wire Line
	9250 4300 9250 4400
Wire Wire Line
	9250 4400 9300 4400
Wire Wire Line
	9100 4400 9200 4400
Wire Wire Line
	9200 4400 9200 4350
Wire Wire Line
	9200 4350 9300 4350
Wire Wire Line
	9300 4350 9300 4300
Wire Wire Line
	6100 5250 4400 5250
Wire Wire Line
	4400 5250 4400 5550
Wire Wire Line
	6100 4350 6100 4650
Wire Wire Line
	5950 4650 6000 4650
Connection ~ 6100 4650
Wire Wire Line
	6000 4650 6000 4700
Connection ~ 6000 4650
Wire Wire Line
	6000 5000 6000 5050
Wire Wire Line
	5350 4650 5250 4650
Wire Wire Line
	5250 4650 5250 4600
Wire Notes Line
	7400 3900 4000 3900
Wire Wire Line
	3850 5850 3850 6400
Wire Wire Line
	7750 6400 3850 6400
Wire Wire Line
	9600 5000 9850 5000
Wire Wire Line
	9600 5100 10200 5100
Wire Wire Line
	9600 5200 9850 5200
Wire Wire Line
	9600 5300 10200 5300
Wire Wire Line
	9600 5400 9850 5400
Wire Wire Line
	9600 5500 10200 5500
Wire Wire Line
	9600 5600 9850 5600
Wire Wire Line
	9600 5700 10150 5700
Wire Wire Line
	10250 5000 10700 5000
Wire Wire Line
	10700 5200 10250 5200
Wire Wire Line
	10700 5400 10250 5400
Wire Wire Line
	10700 5600 10250 5600
Wire Wire Line
	10700 5700 10550 5700
Wire Wire Line
	10700 5500 10600 5500
Wire Wire Line
	10700 5300 10600 5300
Wire Wire Line
	10600 5100 10700 5100
Connection ~ 10700 5100
Connection ~ 10700 5200
Connection ~ 10700 5300
Connection ~ 10700 5400
Connection ~ 10700 5500
Connection ~ 10700 5600
Connection ~ 10700 5700
Wire Wire Line
	10700 5000 10700 5100
Wire Wire Line
	10700 6300 10700 6350
Wire Wire Line
	6100 4350 7200 4350
Wire Wire Line
	7200 4350 7200 4550
Wire Wire Line
	8850 3750 9150 3750
Wire Wire Line
	8850 3950 9100 3950
Wire Wire Line
	7750 5000 7750 5200
Wire Wire Line
	7750 5200 8200 5200
Wire Wire Line
	8100 5300 8200 5300
Wire Wire Line
	8100 4850 8450 4850
Wire Wire Line
	8600 4850 8600 4900
Wire Wire Line
	7750 5000 7800 5000
Connection ~ 7750 5200
Wire Wire Line
	8100 5000 8150 5000
Wire Wire Line
	8150 5000 8150 4900
Connection ~ 8150 5000
Wire Wire Line
	8150 4600 8150 4550
Wire Wire Line
	8200 5600 7900 5600
Wire Wire Line
	7900 5600 7900 5700
Wire Wire Line
	8100 4850 8100 5300
Wire Wire Line
	8200 5500 7650 5500
Wire Wire Line
	7650 5500 7650 4350
Wire Wire Line
	7600 4650 7600 6300
Connection ~ 7200 4350
Wire Wire Line
	3950 5750 3950 4850
Connection ~ 3950 4850
$Comp
L EMG_Probe-rescue:R-EMG_Probe-rescue R18
U 1 1 594F6BFE
P 4150 5950
F 0 "R18" V 4230 5950 50  0000 C CNN
F 1 "10k" V 4150 5950 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4080 5950 50  0001 C CNN
F 3 "" H 4150 5950 50  0001 C CNN
	1    4150 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	8150 4550 8450 4550
Wire Wire Line
	8450 4550 8450 4850
Connection ~ 8450 4850
Wire Wire Line
	7200 4750 7350 4750
Wire Wire Line
	7350 4750 7350 5150
Wire Wire Line
	7350 5150 6400 5150
Wire Wire Line
	5200 1400 5200 2000
Wire Wire Line
	4500 2000 4500 2100
Wire Wire Line
	4150 1300 4500 1300
Wire Wire Line
	5800 1300 6150 1300
Wire Wire Line
	7850 1400 8000 1400
Wire Wire Line
	7450 1400 7500 1400
Wire Wire Line
	6750 1500 6800 1500
Wire Wire Line
	6150 1300 6150 1500
Wire Wire Line
	6150 1300 6200 1300
Wire Wire Line
	6600 1300 6800 1300
Wire Wire Line
	2300 4750 2600 4750
Wire Wire Line
	2600 4750 3050 4750
Wire Wire Line
	2450 5050 2600 5050
Wire Wire Line
	3750 4850 3950 4850
Wire Wire Line
	8000 1400 8200 1400
Wire Wire Line
	8800 900  8800 1600
Wire Wire Line
	9950 1500 10000 1500
Wire Wire Line
	8800 1600 9250 1600
Wire Wire Line
	3150 5450 3300 5450
Wire Wire Line
	10350 1500 10600 1500
Wire Wire Line
	5900 7450 5900 7500
Wire Wire Line
	6700 7450 6700 7500
Wire Wire Line
	6350 6650 6900 6650
Wire Wire Line
	6300 7450 6300 7500
Wire Wire Line
	3000 850  3000 900 
Wire Wire Line
	3000 2200 3000 2250
Wire Wire Line
	4350 5950 4450 5950
Wire Wire Line
	6100 4650 6100 5250
Wire Wire Line
	6000 4650 6100 4650
Wire Wire Line
	10700 5100 10700 5200
Wire Wire Line
	10700 5200 10700 5300
Wire Wire Line
	10700 5300 10700 5400
Wire Wire Line
	10700 5400 10700 5500
Wire Wire Line
	10700 5500 10700 5600
Wire Wire Line
	10700 5600 10700 5700
Wire Wire Line
	10700 5700 10700 6000
Wire Wire Line
	7750 5200 7750 6400
Wire Wire Line
	8150 5000 8200 5000
Wire Wire Line
	7200 4350 7650 4350
Wire Wire Line
	3950 4850 4100 4850
Wire Wire Line
	8450 4850 8600 4850
Wire Wire Line
	1900 1200 2400 1200
Wire Wire Line
	9150 3750 9150 4300
$EndSCHEMATC
