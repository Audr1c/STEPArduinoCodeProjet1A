/*
  LiquidCrystal Library - Custom Characters

 Demonstrates how to add custom characters on an LCD  display.
 The LiquidCrystal library works with all LCD displays that are
 compatible with the  Hitachi HD44780 driver. There are many of
 them out there, and you can usually tell them by the 16-pin interface.

 This sketch prints "I <heart> Arduino!" and a little dancing man
 to the LCD.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 10K poterntiometer on pin A0

 created 21 Mar 2011
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 7 Nov 2016
 by Arturo Guadalupi

 Based on Adafruit's example at
 https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde

 This example code is in the public domain.
 https://docs.arduino.cc/learn/electronics/lcd-displays#custom-character

 Also useful:
 http://icontexto.com/charactercreator/

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters:
byte one[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
};

// cree un varaible qui decide si on est en mode 1 ou 2
int mode = 1;

unsigned long end, deltaT, somme, frequency;
const unsigned int length = 10;
unsigned long times[length];
int currentpos = 0;

void setup()
{
  mode = 1;
  // initailaise times array
  for (int i = 0; i < length; i++)
  {
    times[i] = 0;
  }
  // initialize LCD
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.createChar(1, one);

  end = millis();
  somme = 0;

  // for debugging purposes
  Serial.begin(9600);
}

void loop()
{

  // calculate time of loop and modifie times array
  deltaT = millis() - end;
  end = millis();
  somme += deltaT - times[(currentpos + 1) % length];
  times[currentpos] = deltaT;
  currentpos++;
  currentpos %= length;
  frequency = 1000 / (somme / length); // Hz

  // on every 2 second change mode
  if (int((millis()) / 1000) % 2 == 0)
  {
    mode = 2;
  }
  else
  {
    mode = 1;
  }
  // set one line in full One
  for (int i = 0; i < 16; i++)
  {
    lcd.setCursor(i, mode % 2);
    lcd.write((byte)1);
  }
  // set the four caracters of second line with random caracters
  for (int i = 0; i < 4; i++)
  {
    lcd.setCursor(i, 1 - mode % 2);
    lcd.write(random(32, 127));
  }
  // write the frequency on the left side of the secon line
  // lcd.rightToLeft();
  lcd.setCursor(5, 1 - mode % 2);
  lcd.print("Freq: ");
  lcd.print(frequency);
  lcd.print("Hz");
  // lcd.leftToRight();

  // debug
  // print times array
  /*
  Serial.print("times: ");
  for (int i = 0; i < length; i++)
  {
    Serial.print(times[i]);
    Serial.print("  ");
  }
  Serial.println(" Freq = " + String(frequency) + "Hz");
  */
}