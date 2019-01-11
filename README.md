# MyoSense
## Overview
MyoSense is a armband designed to wirelessly track and interpret muscle activity in the forearm to predict handmovements. It uses a custom designed 2.4GHz interface to transmit the signals collected by up to eight sensors to a receiver that can be read out over a standard serial interface. The armband uses dry stainless steel electrodes incorporated into the sensor modules that can pick up the electromygraphic signal generated by muscle activity. Using external adhesive electrodes that can be attached to each sensor MyoSense is also able to read out activity of bigger muscles extendig it's possible usecases to tracking movements of all extremities. 
![test image size](https://github.com/timohueser/MyoSense/blob/master/Picture_Gallery/MyoSense_Armband.jpeg){:height="50%" width="50%"}

## Technical Details
### Sensor Modules
As mentioned before the MyoSense Sensor Modules use dry stainless steel electrodes to pick up the small voltages generated by muscle activity on the skin above the monitored muscle. These voltages get amplified, bandpass-filtered and rectified using analog circuitry. The processed signal gets digitized by an Attiny85 microcontroller that in turn uses an I2C interface to send the measured voltages to the control module. A push-button on the sensor allows the user to set the I2C adress of the module, allowing up to eight sensors to be used with one control module. The modules consist of a custom design PCB, 3 stainless steel plates serving as the electrodes and a 3D-printed housing. The Kicad design files for the PCB and STL files of the housing can be found in the repository. 

### Control Module
The control module not only is responsible for reading out the senors and transmitting the collected data via a 2.4GHz interface, it also contains circuitry to charge a 250 mAh Lipo Battery and supply the requiered 3V and -3V power rails to the sensors. In addition it also contains a MCP2221 I2C/UART to USB interface IC enabeling direct wired acces to the I2C bus. The wireless communication module used is custom designed and uses the Nordic Semi nRF24L01 2.4GHz transciever controlled by an Attiny85 mircrocontroller.

### Wireless receiver and GUI
The wireless receiver also uses the nRF24L01 transciever and Attiny85 microcontroller as the transmitter module. The microcontroller then connects to another MCP2221 USB interface IC to be able to transmit the received data to a computer over a standard serial interface. The repository also contains an UI-Program implementet in c++ using QT that allows easy access to the receiver module and visualizes the data collected. The repository also contains a python script that implements a neural network that can be used to classify different movement patterns. At the moment this functionality is not available in the GUI, but it is planned to integrate this feature. 
