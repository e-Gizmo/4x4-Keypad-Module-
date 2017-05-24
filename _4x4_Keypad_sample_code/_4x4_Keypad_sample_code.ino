/* 
  e-Gizmo 4x4 Keypad Sample code
  
  Displaying the Numbers and Letters assigned
  from the keypad using Serial Monitor.
  Add the Keypad Library.
  
  Wiring Connections:
  gizDuino  4x4 Keypad
  D2      - R1  }    
  D3      - R2   } ROWS
  D4      - R3   }
  D5      - R4  }
  D6      - C1  }
  D7      - C2   } COLUMNS
  D8      - C3   }
  D9      - C4  }
  
  Modified by
  e-Gizmo Mechatronix Central
  http://www.e-gizmo.com
  May 24,2017
  
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}
