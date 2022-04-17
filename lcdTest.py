from RPLCD.gpio import CharLCD
from RPi import GPIO


lcd = CharLCD(pin_rs=15, pin_rw=18, pin_e=16, pins_data=[21, 22, 23, 24],
              numbering_mode=GPIO.BOARD)

lcd.write_string('Raspberry Pi HD44780')
lcd.cursor_pos = (2, 0)
lcd.write_string('https://github.com/\n\rdbrgn/RPLCD')
