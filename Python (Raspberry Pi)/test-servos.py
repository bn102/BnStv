import time
import serial

ser=serial.Serial(

port='/dev/ttyACM0',
baudrate=9600,
parity=serial.PARITY_NONE,
stopbits=serial.STOPBITS_ONE,
bytesize=serial.EIGHTBITS,
timeout=1
)

angle = 0

startmsg = "90, 90,"
ser.write(startmsg.encode())
time.sleep(2)

while angle <= 180:
    msg = str(angle) + ", " + str(angle) + ","
    ser.write(msg.encode())
    time.sleep(0.2)
    angle = angle+10
time.sleep(2)
finmsg = "0, 0,"
ser.write(finmsg.encode())

ser.close
