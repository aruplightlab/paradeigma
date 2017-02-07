/*
Paradeigma Arduino controller
2017-02-06 francesco.anselmo@arup.com
*/

int waitgap = 2000;         // how long to wait
int times = 3;              // how many times to loop
int fadeAmount = 1;         // how many points to fade the LED by
int wait = 10;              // fading wait time between values

int dimTiles[] = {0,0,0,0}; // array for holding dimming values
int cctTiles[] = {0,0,0,0}; // array for holding cct values

int dimPins[] = {3,5,7,9};  // array for holding dimming output pins values (orange)
int cctPins[] = {2,4,6,8};  // array for holding cct output pins values (green)

int value = 0;              // dimming value
int mode = -1;               // 0 = change smoothly colour temperature
                            // 1 = switch between colour temperatures and dark


int tilesNumber = sizeof(dimTiles)/sizeof(int);

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // declare pins to be output:
  for (int i=0; i<tilesNumber; i++) {
    pinMode(dimPins[i], OUTPUT);
    pinMode(cctPins[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  
    // mode 0
    Serial.println("mode 0");
    for (int t=1; t<=times; t++) {
      Serial.print("mode 0 time: ");
      Serial.println(t);
      for (int i=0; i<tilesNumber; i++) {
        for (int j=0; j<255; j++) {
          //Serial.print(i);
          //Serial.println(millis());
          analogWrite(dimPins[i], 255);
          analogWrite(cctPins[i], j);
          delay(wait);
        }
        delay(waitgap);
        for (int j=255; j>0; j--) {
          
          //Serial.print(i);
          //Serial.print(j);
          //Serial.println(millis());
          analogWrite(dimPins[i], 255);
          analogWrite(cctPins[i], j);
          delay(wait);
        }
      }
    }
    
    // mode 1
    Serial.println("mode 1");
    for (int t=1; t<=times; t++) { 
      Serial.print("mode 1 time: ");
      Serial.println(t);
       for (int i=0; i<tilesNumber; i++) {
        for (int j=0; j<255; j++) {
          //Serial.print(i);
          //Serial.print(j);
          analogWrite(dimPins[i], 0);
          analogWrite(cctPins[i], 255);
          delay(wait);
        }
        delay(waitgap);
        for (int j=255; j>0; j--) {
          
          //Serial.print(i);
          //Serial.print(j);
          analogWrite(dimPins[i], 255);
          analogWrite(cctPins[i], 255);
          delay(wait);
        }
      }
    
  }
  
}
