#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include <TouchScreen.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

#define YP A2  // must be an analog pin, use "An" notation!
#define XM A3 // must be an analog pin, use "An" notation!
#define YM 8   // can be a digital pin
#define XP 9   // can be a digital pin

//Size of the area of LCD display
#define TS_MINX 150
#define TS_MINY 940
#define TS_MAXX 920
#define TS_MAXY 120

//Coordinates
int X;
int Y;
int Z;

//Colors
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define ROZ     0xFBE0
#define GRI     0xBDF7

#define BOXHIGHT 240
#define BOXWIDTH 43

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
  tft.reset();
  uint16_t identifier = tft.readID(); //reads the driver version of LCD

  tft.begin(identifier);
  tft.fillScreen(BLACK);
  tft.fillRect(0, 0, 320, 240, BLACK);

  tft.setRotation(0);
  tft.fillRect(0, 0, BOXHIGHT, BOXWIDTH, WHITE);//Do
  tft.fillRect(0, BOXWIDTH*1+2, BOXHIGHT, BOXWIDTH, WHITE);//Re
  tft.fillRect(0, BOXWIDTH*2+4, BOXHIGHT, BOXWIDTH, WHITE);//Mi
  tft.fillRect(0, BOXWIDTH*3+6, BOXHIGHT, BOXWIDTH, WHITE);//Fa
  tft.fillRect(0, BOXWIDTH*4+8, BOXHIGHT, BOXWIDTH, WHITE);//Sol
  tft.fillRect(0, BOXWIDTH*5+10, BOXHIGHT, BOXWIDTH, WHITE);//La
  tft.fillRect(0, BOXWIDTH*6+12, BOXHIGHT, BOXWIDTH, WHITE);//Si
  //tft.fillRect(0, BOXWIDTH*7+14, BOXHIGHT, BOXWIDTH, WHITE);//Do

  tft.fillRect(0, BOXWIDTH-6, BOXHIGHT/2, BOXWIDTH/2, BLACK);
  tft.fillRect(0, BOXWIDTH*2-6, BOXHIGHT/2, BOXWIDTH/2, BLACK);
  tft.fillRect(0, BOXWIDTH*3-6, BOXHIGHT/2, BOXWIDTH/2, BLACK);
  tft.fillRect(0, BOXWIDTH*5, BOXHIGHT/2, BOXWIDTH/2, BLACK);
  tft.fillRect(0, BOXWIDTH*6, BOXHIGHT/2, BOXWIDTH/2, BLACK);
  //tft.fillRect(0, BOXWIDTH*7, BOXHIGHT/2, BOXWIDTH/2, BLACK);
  
}

#define MINPRESSURE 200
#define MAXPRESSURE 1000

void loop() {
  //Getting the touch point
  digitalWrite(13, HIGH);
  TSPoint p = ts.getPoint();
  digitalWrite(13, LOW);
  
  //Direction of the touch
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);

  //Getting the coordinates
  X = p.y;
  Y = p.x;
  Z = p.z;  

  if (Z > MINPRESSURE && Z < MAXPRESSURE) {
    X = tft.width()-(map(X, TS_MINX, TS_MAXX, 0, tft.width()));
    Y = tft.height()-(map(Y, TS_MINY, TS_MAXY, 0, tft.height()));

    if (Y < BOXWIDTH) {
      Serial.print("Si");
      delay(150);}
      else if (Y < BOXWIDTH*2+2) {
      Serial.print("La");
      delay(150);
      }
      else if (Y < BOXWIDTH*3+4) {
      Serial.print("Sol");
      delay(150);
      }
      else if (Y < BOXWIDTH*4+6) {
      Serial.print("Fa");
      delay(150);
      }
      else if (Y < BOXWIDTH*5+8) {
      Serial.print("Mi");
      delay(150);
      }
      else if (Y < BOXWIDTH*6+10) {
      Serial.print("Re");
      delay(150);
      }
      else if (Y < BOXWIDTH*7+12) {
      Serial.print("Do");
      delay(150);
      }
      /*else if (Y < BOXWIDTH*8+14) {
      Serial.print("Do");
      delay(200);
      }*/
    }
}
