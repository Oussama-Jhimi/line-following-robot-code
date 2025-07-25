
#include <Wire.h>
#include <MPU6050_light.h>
#include <Ultrasonic.h>
#include <QTRSensors.h>
#include <FastLED.h>
#include <LiquidCrystal.h>

MPU6050 mpu(Wire);

const int rs = 31, en = 33, d4 = 35, d5 = 37, d6 = 39, d7 = 41;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const PROGMEM uint8_t ENB = 7; // right
const PROGMEM uint8_t IN4 = 5; // right
const PROGMEM uint8_t IN3 = 6; // right

const PROGMEM uint8_t IN2 = 4; // left   
const PROGMEM uint8_t IN1 = 3; // left
const PROGMEM uint8_t ENA = 2; // left 

double elapsedTime, Time = 0, timePrev;

const PROGMEM uint8_t button = 10; // right

Ultrasonic ultrasonicF(49, 48); // trig echo
Ultrasonic ultrasonicR(47, 46); // trig echo
Ultrasonic ultrasonicL(45, 44); // trig echo

const PROGMEM uint8_t LED_PIN = A15;
const PROGMEM uint8_t NUM_LEDS = 8;

const uint8_t SensorCount = 16;
static uint8_t PathColorSettings[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0}; // fill it with number of sensors
static uint16_t lastIntDsensors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0};       // fill it with number of sensors


static const uint8_t analog_pins[] = {A15,A14, A13, A12, A11, A10, A9, A8, A7, A6, A5, A4, A3,A2,A1,A0};
// ********************************************* IMPORTANT PATH STRING : *************************************************************************
const int defaultTime = 300;

 const int pathDistances[] = {0};//
 const char path[] = "B";

//                           B D E  C   R C  C C   C  s
//const int pathDistances[] = {0,5,32,25,50,10,14,60,160,0};
//const char path[] = "BDECRCCCCs";
//const int pathDistances[] = {0,160,20,19,60};
//const char path[] = "BCCCC";
//const int pathDistances[] = {0,0,15,10,80,2};
//const char path[] = "B1WCEB";
//const int pathDistances[] = {0,0,12,3,110,60,15,152,25,10,120,2};
//const char path[] = "B1CCFCCEWCEB";




//                           B 1 C  C  F  D C  W   C  E  B   C   C 1  C  C   C  C  C
//const int pathDistances[] = {0,0,32,15,120,10,1,145,10,135,10,60,450,0,35,350,45,49,90};
//const char path[] = "B1CCFDCWCEBCC1CCCCC";


//                           B 1  C  C  L  C  L  R  C C   C  C  D   E  W  B  s
//const int pathDistances[] = {0,0,15,25,40,30,30,15,25,15,75,35,115,85,70,35,25};
//const char path[] = "B1CCLCLRCCCCDEWBs";

//                             B 1  f  C   C  C C  C
//const int pathDistances[] = {0,0,400,15,35,15,5,340,15,520,15,40,65,105 };//fablab kol
//const char path[] = "B1fCCCCCCCCCCC";


//const int pathDistances[] = {0, 0, 15, 520, 15, 40, 65, 105 }; //fablab chtar 2
//const char path[] = "B1CCCCCC";

// R= RIGHT    ;     L left : B  mode black  ;    W mode WHITE
// F forward tawwalii ;     S stop  ; C other conditions like distance based ones
// EXEMPLE "BRLWLRLRFBCLFCWRRRs"
// ********************************************* IMPORTANT PATH STRING : *************************************************************************

// vars

double  initialAngle = 0;


int pathTimes[sizeof(pathDistances) / sizeof(pathDistances[0])];
int distanceL, distanceR, distanceF;
int prev_i = 0, prev_error = 0;
QTRSensors qtr;
CRGB leds[NUM_LEDS];
uint8_t hue = 0;
long ledactiontime = 0;
int lastLeftSpeed = 0;
int lastRightSpeed = 0;
uint16_t sensors[SensorCount];
char Dsensors[SensorCount]; // Dsensors : W B , IntDsensors 1 line 0 background que ce soit B or W mode
static uint16_t IntDsensors[SensorCount];
int enetcomLedCounter = 0;
double lastIntDsensorstimes[SensorCount];
int otherconditionsCounter = 0;
char Prevc = 0, mode = 'S', currentLineColor;
long pos = 0, sv = 0;
uint16_t position;
double Taction = 0;
double GyroAngle = 0;
const PROGMEM double GyroOffset = 10000;
boolean updateLedsInSensorsFn = true;
boolean BLOCKMOVEMENT = false;
OfflineDirection offD = OfflineDirection::AUTO;
WhichLineToFollow direction = WhichLineToFollow::AUTO;
int pathSteps = 0;
boolean isPathTimesArrayCorrect = true;
boolean isPathArrayCorrect = true;
boolean stillWaiting = false;
boolean RUNROBOT = false;
int SetPoint = 7500; // 2000
// colors
int lineColor = 0;
int nextMoveColor = 0;
