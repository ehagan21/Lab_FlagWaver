#!/bin/bash

sudo chmod 666 /dev/ttyACM0

if [ $? -eq 0 ]; then 
    echo "launching script"
    python /home/pi/Desktop/Lab_FlagWaver/md.py
else
    echo "its cool and running probably"
fi
