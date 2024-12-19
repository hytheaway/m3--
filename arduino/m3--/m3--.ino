#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// GUItool: begin automatically generated code
AudioSynthWaveform waveform1;  //xy=459,249
AudioSynthSimpleDrum drum1;
AudioSynthSimpleDrum drum2;
AudioSynthSimpleDrum drum3;
AudioEffectGranular granular1;
AudioMixer4 mixer1;
// AudioEffectFreeverbStereo freeverbs1;
AudioOutputI2S i2s1;  //xy=952,252
AudioConnection patchCord1(waveform1, granular1);
AudioConnection patchCord2(drum1, 0, mixer1, 1);
AudioConnection patchCord3(drum2, 0, mixer1, 2);
AudioConnection patchCord4(drum3, 0, mixer1, 3);
AudioConnection patchCord5(granular1, 0, mixer1, 0);
AudioConnection patchCord6(mixer1, 0, i2s1, 0);
AudioConnection patchCord7(mixer1, 0, i2s1, 1);
// AudioConnection patchCord6(mixer1, freeverbs1);
// AudioConnection patchCord7(freeverbs1, 0, i2s1, 0);
// AudioConnection patchCord8(freeverbs1, 1, i2s1, 1);
AudioControlSGTL5000 sgtl5000_1;  //xy=671,370
// GUItool: end automatically generated code

int buttonPin1 = 32;
int buttonPin2 = 31;
int buttonPin3 = 30;
int buttonPin4 = 29;
int buttonPin5 = 28;
int buttonPin6 = 27;
int buttonPin7 = 26;
int buttonPin8 = 25;

int wasdDown = 36;
int wasdUp = 35;
int wasdLeft= 34;
int wasdRight = 33;
int hatAngle = -1;

int buttonPressCounter;
int buttonPressCounterMax = 2;

int a = 220;
int a_sharp = 233;
int b = 247;
int c = 130;
int c_sharp = 139;
int d = 147;
int d_sharp = 156;
int e = 165;
int f = 175;
int f_sharp = 185;
int g = 196;
int g_sharp = 208;

int e_sharp = f;
int b_sharp = c;
int f_flat = e;
int c_flat = b;

int b_flat = a_sharp;
int a_flat = g_sharp;
int g_flat = f_sharp;
int e_flat = d_sharp;
int d_flat = c_sharp;

int c_major[] = { c, e, g };  //c
int c_minor[] = { c, e_flat, g };
int c_dim[] = { c, e_flat, g_flat };
int c_sharp_major[] = { c_sharp, e_sharp, g_sharp };
int c_sharp_minor[] = { c_sharp, e, g_sharp };
int c_sharp_dim[] = { c_sharp, e, g };
int d_major[] = { d, f_sharp, a };
int d_minor[] = { d, f, a };  //d
int d_dim[] = { d, f, a_flat };
int d_sharp_major[] = { d_sharp, g, a_sharp };
int d_sharp_minor[] = { d_sharp, f_sharp, a_sharp };
int d_sharp_dim[] = { d_sharp, f, a };
int e_major[] = { e, g_sharp, b };
int e_minor[] = { e, g, b };  //e
int e_dim[] = { e, g, b_flat };
int f_major[] = { f, a, (c * 2) };int f_minor[] = { f, a_flat, (c * 2) };
int f_dim[] = { f, a_flat, (c_flat * 2) };
int f_sharp_major[] = { f_sharp, a_sharp, (c_sharp * 2) };
int f_sharp_minor[] = { f_sharp, a, (c_sharp * 2) };
int f_sharp_dim[] = { f_sharp, a, (c * 2) };
int g_major[] = { g, b, (d * 2) };
int g_minor[] = { g, b_flat, (d * 2) };
int g_dim[] = { g, b_flat, (d_flat * 2) };
int g_sharp_major[] = { g_sharp, b_sharp, (d_sharp * 2) };
int g_sharp_minor[] = { g_sharp, b, (d_sharp * 2) };
int g_sharp_dim[] = { g_sharp, b, (d * 2) };
int a_major[] = { a, (c_sharp * 2), (e * 2) };
int a_minor[] = { a, (c * 2), (e * 2) };
int a_dim[] = { a, (c * 2), (e_flat * 2) };
int a_sharp_major[] = { a_sharp, (d * 2), (e_sharp * 2) };
int a_sharp_minor[] = { a_sharp, (c_sharp * 2), (e_sharp * 2) };
int a_sharp_dim[] = { a_sharp, (c_sharp * 2), (e * 2) };
int b_major[] = { b, (d_sharp * 2), (f_sharp * 2) };
int b_minor[] = { b, (d * 2), (f_sharp * 2) };
int b_dim[] = { b, (d * 2), (f * 2) };

const int arrsize = 3;
int d_flat_major[] = {0, 0, 0};
int d_flat_minor[] = {0, 0, 0};
int d_flat_dim[] = {0, 0, 0};
int e_flat_major[] = {0, 0, 0};
int e_flat_minor[] = {0, 0, 0};
int e_flat_dim[] = {0, 0, 0};
int g_flat_major[] = {0, 0, 0};
int g_flat_minor[] = {0, 0, 0};
int g_flat_dim[] = {0, 0, 0};
int a_flat_major[] = {0, 0, 0};
int a_flat_minor[] = {0, 0, 0};
int a_flat_dim[] = {0, 0, 0};
int b_flat_major[] = {0, 0, 0};
int b_flat_minor[] = {0, 0, 0};
int b_flat_dim[] = {0, 0, 0};

//freaky chords
int weirdFreq1[] = { 111, 11, 152 };
int weirdFreq2[] = { 666, 970, 654 };
int weirdFreq3[] = { 420, 873, 251 };
int weirdFreq4[] = { 735, 340, 1003 };
int weirdFreq5[] = { 420, 421, 964 };
int weirdFreq6[] = { 999, 373, 932 };
int weirdFreq7[] = { 575, 778, 193 };

int chordFreq1[arrsize];
int chordFreq2[arrsize];
int chordFreq3[arrsize];
int chordFreq4[arrsize];
int chordFreq5[arrsize];
int chordFreq6[arrsize];
int chordFreq7[arrsize];

int16_t granularArray[16];

float output_level = 0.5;

int timer;
int arp_speed;
int ctrl_arp_speed;

bool bool_fightstick_mode;
bool reverb_on;

void copyArr(int arr[], int arr2[], int n){
  for (int i = 0; i < n; i++) {
    arr[i] = arr2[i];
  }
}

void setup() {
  // put your setup code here, to run once:
  copyArr(d_flat_major, c_sharp_major, arrsize);
  copyArr(d_flat_minor, c_sharp_minor, arrsize);
  copyArr(d_flat_dim, c_sharp_dim, arrsize);
  copyArr(e_flat_major, d_sharp_major, arrsize);
  copyArr(e_flat_minor, d_sharp_minor, arrsize);
  copyArr(e_flat_dim, d_sharp_dim, arrsize);
  copyArr(g_flat_major, f_sharp_major, arrsize);
  copyArr(g_flat_minor, f_sharp_minor, arrsize);
  copyArr(g_flat_dim, f_sharp_dim, arrsize);
  copyArr(a_flat_major, g_sharp_major, arrsize);
  copyArr(a_flat_minor, g_sharp_minor, arrsize);
  copyArr(a_flat_dim, g_sharp_dim, arrsize);
  copyArr(b_flat_major, a_sharp_major, arrsize);
  copyArr(b_flat_minor, a_sharp_minor, arrsize);
  copyArr(b_flat_dim, a_sharp_dim, arrsize);

  copyArr(chordFreq1, weirdFreq1, arrsize);
  copyArr(chordFreq2, weirdFreq2, arrsize);
  copyArr(chordFreq3, weirdFreq3, arrsize);
  copyArr(chordFreq4, weirdFreq4, arrsize);
  copyArr(chordFreq5, weirdFreq5, arrsize);
  copyArr(chordFreq6, weirdFreq6, arrsize);
  copyArr(chordFreq7, weirdFreq7, arrsize);

  AudioMemory(12);
  sgtl5000_1.enable();
  sgtl5000_1.volume(output_level);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  granular1.begin(granularArray, 8);
  waveform1.begin(0, 100, WAVEFORM_TRIANGLE);

  mixer1.gain(0, 1.0);
  mixer1.gain(1, 1.0);
  mixer1.gain(2, 1.0);
  mixer1.gain(3, 1.0);

  // freeverbs1.roomsize(0.0);
  // freeverbs1.damping(1.0);

  //kick
  drum1.frequency(80);
  drum1.length(500);

  //snare
  drum2.frequency(1000);
  drum2.length(400);

  //tom
  drum3.frequency(500);
  drum3.length(800);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  pinMode(buttonPin6, INPUT_PULLUP);
  pinMode(buttonPin7, INPUT_PULLUP);
  pinMode(buttonPin8, INPUT_PULLUP);
  pinMode(wasdDown, INPUT_PULLUP);
  pinMode(wasdUp, INPUT_PULLUP);
  pinMode(wasdLeft, INPUT_PULLUP);
  pinMode(wasdRight, INPUT_PULLUP);

  buttonPressCounter = 0;
  timer = 0;
  arp_speed = 5;
  ctrl_arp_speed = arp_speed;
  bool_fightstick_mode = true;
  reverb_on = false;
}
//placement is based on how many characters are in the chord name, keeps it centered.
void drawToDisplayChords(char text[], int placement_x, int placement_y, int funcButtonPressCounter) {
  display.clearDisplay();
  display.setCursor(placement_x, placement_y);
  display.setTextSize(1);
  if (funcButtonPressCounter == 0) {
    display.setTextColor(SSD1306_WHITE);
    display.drawCircle(64, 32, 10, 1);
  }
  if (funcButtonPressCounter == 1) {
    display.setTextColor(BLACK, SSD1306_WHITE);
    display.fillCircle(64, 32, 20, 1);
  }
  if (funcButtonPressCounter == 2) {
    display.setTextColor(SSD1306_WHITE);
    display.drawCircle(64, 32, 30, 1);
  }
  if (funcButtonPressCounter == 3) {
    display.setTextColor(BLACK, SSD1306_WHITE);
    display.fillCircle(64, 32, 40, 1);
  }
  display.println(text);
  display.display();
}

void drawToDisplayMenu(char title[], char options[], int placement_x, int placement_y) {
  display.clearDisplay();
  display.setCursor(placement_x, placement_y);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(title);
  display.setTextWrap(0);
  display.setCursor(49, 37);
  display.println("");
  display.setTextWrap(0);
  display.setCursor(43, 37);
  display.println(options);
  display.display();
}

void drawOverlay(char text[], int placement_x, int placement_y) {
  display.setCursor(placement_x, placement_y);
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(text);
  display.display();
}

// void chordSwap() {
// }

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(wasdDown) == LOW) {
    // hatAngle = 180;
    // Serial.println("down, pin 33");
    Joystick.Y(1023);
  }
  if (digitalRead(wasdUp) == LOW) {
    // hatAngle = 0;
    // Serial.println("up, pin 34");
    Joystick.Y(0);
  }
  if (digitalRead(wasdLeft) == LOW) {
    // hatAngle = 270;
    // Serial.println("left, pin 35");
    Joystick.X(0);
  }
  if (digitalRead(wasdRight) == LOW) {
    // Serial.println("right, pin 36");
    // hatAngle = 90;
    Joystick.X(1023);
  }
  if (digitalRead(wasdDown) == HIGH && digitalRead(wasdUp) == HIGH) {
    Joystick.Y(512);
  }
  if (digitalRead(wasdLeft) == HIGH && digitalRead(wasdRight) == HIGH) {
    Joystick.X(512);
  }
  if (digitalRead(wasdDown) == HIGH && digitalRead(wasdUp) == HIGH && digitalRead(wasdLeft) == HIGH && digitalRead(wasdRight) == HIGH) {
    // hatAngle = -1;
    Joystick.X(512);
    Joystick.Y(512);
  }
  if (digitalRead(buttonPin3) == LOW && digitalRead(buttonPin4) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH) {
    waveform1.amplitude(0);
    drawToDisplayMenu("Fightstick Mode\n(center neutrals)", "", 20, 20);
    const char* s_temp = (bool_fightstick_mode == true) ? "True" : "False";
    drawOverlay(s_temp, 50, 38);
    if (digitalRead(buttonPin1) == LOW) {
      bool_fightstick_mode = true;
    }
    if (digitalRead(buttonPin2) == LOW) {
      bool_fightstick_mode = false;
    }
  }
  if (bool_fightstick_mode == true) {
    // fightstick mode
    if (digitalRead(wasdDown) == LOW && digitalRead(wasdUp) == LOW) {
      Joystick.Y(512);
    }
    if (digitalRead(wasdLeft) == LOW && digitalRead(wasdRight) == LOW) {
      Joystick.X(512);
    }
  }

  Joystick.button(1, !digitalRead(buttonPin1));
  Joystick.button(2, !digitalRead(buttonPin2));
  Joystick.button(3, !digitalRead(buttonPin3));
  Joystick.button(4, !digitalRead(buttonPin4));
  Joystick.button(5, !digitalRead(buttonPin5));
  Joystick.button(6, !digitalRead(buttonPin6));
  Joystick.button(7, !digitalRead(buttonPin7));
  Joystick.button(8, !digitalRead(buttonPin8));
  Joystick.hat(hatAngle);

  if (timer % arp_speed == 0) {
    buttonPressCounter++;
  }

  if (digitalRead(buttonPin1) == LOW && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH) {
    drawToDisplayChords("chord 1", 50, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq1[buttonPressCounter]);
    timer++;
  }
  if (digitalRead(buttonPin2) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH) {
    drawToDisplayChords("chord none", 56, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq2[buttonPressCounter]);
    timer++;
  }
  if (digitalRead(buttonPin3) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin4) == HIGH) {
    drawToDisplayChords("chord 3", 50, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq3[buttonPressCounter]);
    timer++;
  }
  if (digitalRead(buttonPin4) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH) {
    drawToDisplayChords("4 chords", 56, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq4[buttonPressCounter]);
    timer++;
  }
  if (digitalRead(buttonPin5) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH) {
    drum1.noteOn();
  }
  if (digitalRead(buttonPin6) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH) {
    drum2.noteOn();
  }
  if (digitalRead(buttonPin7) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin8) == HIGH) {
    drum3.noteOn();
  }
  //pin 8 goes here
  if (digitalRead(buttonPin8) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH){
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    // display.setCursor(20, 20);
    // display.println("C");
    // display.setCursor(40, 10);
    // display.println("D");
    // display.setCursor(60, 10);
    // display.println("E");
    // display.setCursor(80, 10);
    // display.println("F");
    // display.setCursor(20, 40);
    // display.println("G");
    // display.setCursor(40, 30);
    // display.println("A");
    // display.setCursor(60, 30);
    // display.println("B");
    display.setCursor(20, 25);
    display.println("holding on!!1!");
    display.display();
    // if (digitalRead(wasdUp) == LOW){
    //   if(reverb_on == false){
    //     freeverbs1.roomsize(1.0);
    //     freeverbs1.damping(0.0);
    //     drawOverlay("On", 50, 38);
    //     reverb_on = true;
    //   }
    //   if(reverb_on == true){
    //     freeverbs1.roomsize(0.0);
    //     freeverbs1.damping(1.0);
    //     drawOverlay("Off", 50, 38);
    //     reverb_on = false;
    //   }
    //   delay(500);
    // }
  }
  if (digitalRead(wasdDown) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH){
    drawToDisplayChords("chord5", 56, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq5[buttonPressCounter]);
    timer++;
  }
  if (digitalRead(wasdLeft) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH){
    drawToDisplayChords("6hords", 56, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq6[buttonPressCounter]);
    timer++;
  }
  if (digitalRead(wasdRight) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH){
    drawToDisplayChords("chord 7!", 56, 29, buttonPressCounter);
    if (buttonPressCounter > buttonPressCounterMax) {
      buttonPressCounter = 0;
    }
    waveform1.amplitude(output_level);
    waveform1.frequency(chordFreq7[buttonPressCounter]);
    timer++;
  }
  // if (digitalRead(wasdUp) == LOW && digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH){
  //   drawToDisplayMenu("Reverb", "On/Off", 47, 20);
  //   if(reverb_on == false){
  //     reverb_on = true;
  //     freeverbs1.roomsize(1.0);
  //     freeverbs1.damping(0.0);
  //     drawOverlay("On", 50, 38);
  //   }
  //   if(reverb_on == true){
  //     reverb_on = false;
  //     freeverbs1.roomsize(0.0);
  //     freeverbs1.damping(1.0);
  //     drawOverlay("Off", 50, 38);
  //   }
  // }

  if (digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH && digitalRead(buttonPin5) == HIGH && digitalRead(buttonPin6) == HIGH && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH) {
    waveform1.amplitude(0);
    display.clearDisplay();
    display.display();
  }
  //volume control
  if (digitalRead(buttonPin1) == LOW && digitalRead(buttonPin2) == LOW && digitalRead(buttonPin3) == HIGH && digitalRead(buttonPin4) == HIGH) {
    drawToDisplayMenu("Volume", "Down/Up", 47, 20);
    if (digitalRead(buttonPin3) == LOW) {
      if (output_level >= 0.1) {
        output_level = output_level - 0.1;
      }
      if (output_level <= 0.0) {
        output_level = 0.0;
      }
      char str_output_level[5];
      itoa((output_level * 100), str_output_level, 10);
      drawOverlay(strcat(str_output_level, "%"), 60, 28);
    }
    if (digitalRead(buttonPin4) == LOW) {
      if (output_level < 1.0) {
        output_level = output_level + 0.1;
      }
      if (output_level == 1.0) {
        output_level = 1.0;
      }
      char str_output_level[5];
      itoa((output_level * 100), str_output_level, 10);
      drawOverlay(strcat(str_output_level, "%"), 60, 28);
    }
  }
  //arp speed control
  if (digitalRead(buttonPin5) == LOW && digitalRead(buttonPin6) == LOW && digitalRead(buttonPin7) == HIGH && digitalRead(buttonPin8) == HIGH) {
    drawToDisplayMenu("Arpeggio Speed", "Down/Up", 40, 20);
    char str_arp_speed[4];
    if (digitalRead(buttonPin7) == LOW) {
      if (ctrl_arp_speed < 10) {
        if (ctrl_arp_speed != arp_speed) {
          arp_speed = ctrl_arp_speed;
        }
        ctrl_arp_speed = ctrl_arp_speed + 1;
        arp_speed = arp_speed + 1;
      }
      if (ctrl_arp_speed == 10) {
        ctrl_arp_speed = 10;
        arp_speed = 0;
      }
      itoa((10 - ctrl_arp_speed), str_arp_speed, 10);
      drawOverlay(str_arp_speed, 60, 28);
    }
    if (digitalRead(buttonPin8) == LOW) {
      if (ctrl_arp_speed >= 1) {
        if (ctrl_arp_speed != arp_speed) {
          arp_speed = ctrl_arp_speed;
        }
        ctrl_arp_speed = ctrl_arp_speed - 1;
        arp_speed = arp_speed - 1;
      }
      if (ctrl_arp_speed <= 0) {
        ctrl_arp_speed = 0;
        arp_speed = 10;
      }
      itoa((10 - ctrl_arp_speed), str_arp_speed, 10);
      drawOverlay(str_arp_speed, 60, 28);
    }
  }
}
