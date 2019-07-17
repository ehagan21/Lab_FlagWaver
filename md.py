import cv2 as cv
import numpy as np
import serial
import time
import datetime
import traceback

#how may different pixels trigger the motion
#change this as install happens
threshold = 1500

#video capture 
cam = cv.VideoCapture(0)

#history, threshold, DetectShadows, based on location
fgbg = cv.createBackgroundSubtractorMOG2(300, 400, True)

port = "/dev/ttyACM0"
rate = 115200

while True:
    try:
        print('open serial port')
        ser = serial.Serial(port, rate, timeout = None)
        print 'port Open'
        break
    except serial.SerialException:
        print 'port not available, wait'
        time.sleep(3)

try:
    while(True):
        ret, frame = cam.read()
        resizedFrame = cv.resize(frame, (0, 0), fx=0.5, fy=0.5)
        fgmask = fgbg.apply(resizedFrame)

        #Count all the non zero pixels within the mask
        count = np.count_nonzero(fgmask)

        #whats the serial issue cropping up here?
        if (count > threshold):
            print('detection! moving')
            #'C' turns on both flags
            ser.write('C')
            time.sleep(0.1)

        else:
            #stops the motors
            ser.write('S')
            time.sleep(0.1)

        #In GUI shows the image or the difference
        #cv.imshow('Frame', resizedFrame)
        #cv.imshow('Mask', fgmask)

except:
    #error handling and closing ports/camera
    traceback.print_exc()
    cam.release()
    ser.write('X')
    ser.close()
    now = datetime.datetime.now()
    print now.strftime("%m-%d %H:%M")
    print(' exited')
    cv.destroyAllWindows()
