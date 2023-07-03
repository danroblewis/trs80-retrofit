// #include "Keyboard.h"

//                     0  1  2  3  4  5  6  7  8
const int WHITEN = 9;
int whites[WHITEN] = { 8, 7, 6, 5, 4, 3, 2, 1, 0 };

//                     0   1   2   3   4   5   6   7   8   9
const int BLACKN = 10;
int blacks[BLACKN] = { 23, 22, 21, 20, 14, 15, 16, 17, 18, 19 };


// STATES:
// 0 unpressed
// 1 pressed
uint16_t mapping[WHITEN][BLACKN] = {
/*          0    1              2       3                4    5    6    7     8    9   <-- black */
/* 0 */  { '_', '_',           '_',    '_',             '_', '_', '_', '_',  '_', '_' },
/* 1 */  { '_', KEY_LEFT_SHIFT,KEY_F1, ' ',             'z', 'a', 'q', 'o',  '1', '9' },
/* 2 */  { '_', KEY_LEFT_CTRL, KEY_F2, KEY_BACKSPACE,   'x', 's', 'w', 'p',  '2', '0' },
/* 3 */  { '_', KEY_LEFT_ALT,  KEY_F3, KEY_TAB,         'c', 'd', 'e', '[',  '3', '-' },
/* 4 */  { '_', KEY_LEFT_ALT,  KEY_F4, KEY_ESC,         'v', 'f', 'r', ';',  '4', '=' },
/* 5 */  { '_', '_',           KEY_F5, '`',             'b', 'g', 't', '\'', '5', KEY_LEFT_ARROW },
/* 6 */  { '_', KEY_CAPS_LOCK, KEY_F6, '{',             'n', 'h', 'y', ',',  '6', KEY_RIGHT_ARROW },
/* 7 */  { '_', 'N',           KEY_F7, KEY_PRINTSCREEN, 'm', 'j', 'u', '.',  '7', KEY_UP_ARROW },
/* 8 */  { '_', KEY_BACKSLASH, KEY_F8, KEY_ENTER,       'l', 'k', 'i', '/',  '8', KEY_DOWN_ARROW }
};


uint16_t shiftMapping[WHITEN][BLACKN] = {
/*          0    1              2       3                4    5    6    7     8    9   <-- black */
/* 0 */  { '_', '_',           '_',    '_',             '_', '_', '_', '_',  '_', '_' },
/* 1 */  { '_', KEY_LEFT_SHIFT,KEY_F1, ' ',             'Z', 'A', 'Q', 'O',  '!', '(' },
/* 2 */  { '_', KEY_LEFT_CTRL, KEY_F2, KEY_DELETE,      'X', 'S', 'W', 'P',  '@', ')' },
/* 3 */  { '_', KEY_LEFT_ALT, KEY_F3, KEY_TAB,          'C', 'D', 'E', ']',  '#', '_' },
/* 4 */  { '_', KEY_LEFT_ALT, KEY_F4, KEY_ESC,          'V', 'F', 'R', ':',  '$', '+' },
/* 5 */  { '_', '_',           KEY_F5, '~',             'B', 'G', 'T', '"',  '%', KEY_LEFT_ARROW },
/* 6 */  { '_', KEY_CAPS_LOCK, KEY_F6, '}',             'N', 'H', 'Y', '<',  '^', KEY_RIGHT_ARROW },
/* 7 */  { '_', 'N',           KEY_F7, KEY_PRINTSCREEN, 'M', 'J', 'U', '>',  '&', KEY_UP_ARROW },
/* 8 */  { '_', KEY_BACKSLASH, KEY_F8, KEY_ENTER,       'L', 'K', 'I', '?',  '*', KEY_DOWN_ARROW }
};

uint16_t numMapping[WHITEN][BLACKN] = {
/*          0    1              2       3                4    5    6    7    8    9   <-- black */
/* 0 */  { '_', '_',           '_',    '_',             '_', '_', '_', '_', '_', '_' },
/* 1 */  { '_', KEY_LEFT_SHIFT,KEY_F1, ' ',             'z', 'a', 'q', '6', '1', '9' },
/* 2 */  { '_', KEY_LEFT_CTRL, KEY_F2, KEY_BACKSPACE,   'x', 's', 'w', 'p', '2', '0' },
/* 3 */  { '_', KEY_LEFT_ALT,  KEY_F3, KEY_TAB,         'c', 'd', 'e', '[', '3', '-' },
/* 4 */  { '_', KEY_LEFT_ALT,  KEY_F4, KEY_ESC,         'v', 'f', 'r', ';', '4', '=' },
/* 5 */  { '_', '_',           KEY_F5, '{',             'b', 'g', 't', '\'','5', KEY_LEFT_ARROW },
/* 6 */  { '_', KEY_CAPS_LOCK, KEY_F6, '}',             'n', 'h', 'y', ',', '6', KEY_RIGHT_ARROW },
/* 7 */  { '_', 'N',           KEY_F7, KEY_PRINTSCREEN, '0', '1', '4', '.', '7', KEY_UP_ARROW },
/* 8 */  { '_', KEY_PAUSE,     KEY_F8, KEY_ENTER,       '3', '2', '5', '/', '8', KEY_DOWN_ARROW }
};

#define SHIFT_WHITE 1
#define SHIFT_BLACK 1
#define CTRL_WHITE 2
#define CTRL_BLACK 1
#define ALT_WHITE 3
#define ALT_BLACK 1
#define ALT2_WHITE 4
#define ALT2_BLACK 1
#define CAPS_WHITE 6
#define CAPS_BLACK 1
#define NUM_WHITE 5
#define NUM_BLACK 1


int states[2][WHITEN][BLACKN] = {
  {
  /*        0 1 2 3 4 5 6 7 8 9 */
  /* 0 */  {0,0,0,0,0,0,0,0,0,0},
  /* 1 */  {0,0,0,0,0,0,0,0,0,0},
  /* 2 */  {0,0,0,0,0,0,0,0,0,0},
  /* 3 */  {0,0,0,0,0,0,0,0,0,0},
  /* 4 */  {0,0,0,0,0,0,0,0,0,0},
  /* 5 */  {0,0,0,0,0,0,0,0,0,0},
  /* 6 */  {0,0,0,0,0,0,0,0,0,0},
  /* 7 */  {0,0,0,0,0,0,0,0,0,0},
  /* 8 */  {0,0,0,0,0,0,0,0,0,0}
  }, {
  /*        0 1 2 3 4 5 6 7 8 9 */
  /* 0 */  {0,0,0,0,0,0,0,0,0,0},
  /* 1 */  {0,0,0,0,0,0,0,0,0,0},
  /* 2 */  {0,0,0,0,0,0,0,0,0,0},
  /* 3 */  {0,0,0,0,0,0,0,0,0,0},
  /* 4 */  {0,0,0,0,0,0,0,0,0,0},
  /* 5 */  {0,0,0,0,0,0,0,0,0,0},
  /* 6 */  {0,0,0,0,0,0,0,0,0,0},
  /* 7 */  {0,0,0,0,0,0,0,0,0,0},
  /* 8 */  {0,0,0,0,0,0,0,0,0,0}
  }
};


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (int white=0; white<WHITEN; white++) {
    pinMode(whites[white], OUTPUT);
    digitalWrite(whites[white], LOW);
  }

  for (int black=0; black<BLACKN; black++) {
    pinMode(blacks[black], INPUT);
  }

  Serial.begin(19200);
}



int shift, ctrl, alt, num;

int val = 0;
int buff = 1;
int lastbuff = 0;
uint16_t modifiers = 0;
uint16_t key = 0;

int frame = 0;
void loop() {
  lastbuff = buff;
  buff = (buff + 1) % 2;
  shift = 0;
  ctrl = 0;
  alt = 0;
  num = 0;


  // collect states
  for (int white=1; white<WHITEN; white++) {
    digitalWrite(whites[white], HIGH);
    for (int black=1; black<BLACKN; black++) {
      states[buff][white][black] = (digitalRead(blacks[black]) == HIGH);
    }
    digitalWrite(whites[white], LOW);
    delayMicroseconds(10);
  }


  // check modifier states
  shift = states[buff][SHIFT_WHITE][SHIFT_BLACK];
  ctrl = states[buff][CTRL_WHITE][CTRL_BLACK];
  alt = states[buff][ALT_WHITE][ALT_BLACK] || states[buff][ALT2_WHITE][ALT2_BLACK];
  num = states[buff][NUM_WHITE][NUM_BLACK];

  int shift_modifier = 0, ctrl_modifier = 0, alt_modifier = 0;
  if (shift) shift_modifier = MODIFIERKEY_SHIFT;
  if (ctrl) ctrl_modifier = MODIFIERKEY_CTRL;
  if (alt) alt_modifier = MODIFIERKEY_ALT;
  modifiers = shift_modifier | ctrl_modifier | alt_modifier;
  
  if (shift) modifiers |= MODIFIERKEY_SHIFT;
  if (ctrl) modifiers |= MODIFIERKEY_CTRL;
  if (alt) modifiers |= MODIFIERKEY_ALT;
  Keyboard.set_modifier(modifiers);

  int last, curr;
  // actually send the messages
  for (int white=1; white<WHITEN; white++) {
    for (int black=1; black<BLACKN; black++) {
      if (white == SHIFT_WHITE && black == SHIFT_BLACK) continue; // num lock key
      if (white == CAPS_WHITE && black == CAPS_BLACK) continue; // caps lock key
      if (white == NUM_WHITE && black == NUM_BLACK) continue; // num lock key

      last = states[lastbuff][white][black];
      curr = states[buff][white][black];

      // if (shift) {
      //   Serial.print(frame);
      //   Serial.println(" shifty");
      // }
      if (shift) {
        key = shiftMapping[white][black];
      } else if (num) {   // num lock key
        key = numMapping[white][black];
      } else {
        key = mapping[white][black];
      }

      if (last != curr) {
        // handle weird exceptions

        // shift-[ is ]
        if (white == 3 && black == 7 && shift) { // the [ and ] key
          Keyboard.set_modifier(ctrl_modifier | alt_modifier);
          if (last == 0 && curr == 1) Keyboard.press(']');
          if (last == 1 && curr == 0) Keyboard.release(']');
          Keyboard.set_modifier(modifiers);
          continue;
        }
        

        // otherwise, do the normal things
        if (last == 0 && curr == 1) Keyboard.press(key); // keydown
        if (last == 1 && curr == 0) Keyboard.release(key); // keyup

        Serial.print(frame);
        Serial.print(" ");
        Serial.print(white);
        Serial.print(",");
        Serial.print(black);
        Serial.print(" '");
        Serial.print(key);
        Serial.print("' => ");
        Serial.print(' ');
        Serial.print(shift);
        Serial.print(" ");
        Serial.print(ctrl);
        Serial.print(" ");
        Serial.print(alt);
        Serial.print("\n");
      }
    }
  }
  Keyboard.set_modifier(0);
  frame++;
}
