from RPLCD.gpio import CharLCD
from RPi import GPIO


lcd = CharLCD(pin_rs=15, pin_rw=18, pin_e=16, pins_data=[21, 22, 23, 24],
              numbering_mode=GPIO.BOARD,
              cols=24, rows=2)

lcd.clear()

lcd.cursor_pos = (0, 0)

lcd.write_string('HackDavis 2022')
lcd.cursor_pos = (1, 0)
lcd.write_string('tell me your secrets or something')
GPIO.cleanup()
