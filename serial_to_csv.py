import serial
import csv
import time

# CHANGE THIS PORT
PORT = "COM3"   # Windows example: "COM3"
# PORT = "/dev/ttyUSB0"        # Linux
# PORT = "/dev/tty.usbserial-0001"  # macOS

BAUD_RATE = 115200
CSV_FILE = "soil_data.csv"

# Open serial port
ser = serial.Serial(PORT, BAUD_RATE)
time.sleep(2)  # wait for serial connection

with open(CSV_FILE, mode="w", newline="") as file:
    writer = csv.writer(file)

    # CSV header
    writer.writerow(["time_ms", "soil_moisture", "label"])
    print("Logging started... Press Ctrl+C to stop.")

    try:
        while True:
            line = ser.readline().decode().strip()
            if line:
                data = line.split(",")
                if len(data) == 3:
                    writer.writerow(data)
                    print(data)

    except KeyboardInterrupt:
        print("\nLogging stopped.")

ser.close()
