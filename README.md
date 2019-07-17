# Lab_FlagWaver

Background subtraction and stepper motors to create a waving flag sculpture as part of Window Dressings Installation / Laboratory Spokane located in Spokane, Washington. 

This code runs on a Raspberry Pi with both an Arduino and a USB camera attached (I'm using Raspberry Pi B+ V2, anything newer should be fine)

When the camera senses a change in the image (as compared to the previous number of images) greater than the threshold value (scaled to location), the python program will send a character to the Arduino to activate a set of stepper motors. 
