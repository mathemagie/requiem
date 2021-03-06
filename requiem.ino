#include <Bridge.h>
#include <HttpClient.h>

///////////////////////
//
// Defines and variables
//
///////////////////////

#define PULSE_DELAY 10	// Delay used to pulse solenoids 
						// Should be long enough to trigger them properly
						// But not too long to avoid overheating
int solPin[] = {2,3,4,5,6,7,8,9,10,11,12,13};	// Define solenoid output pins
int chord[12];	// Array used to define the chord played by the function pulseChord()

String stringOne = "carmen de la zou";
String stringTweet = "";
char charBuf[50];
int delayTime;





///////////////////////
//
// Code
//
/////////////////////////

void setup()
{
	setupSolPins();
        Bridge.begin();
        Serial.begin(9600);
        while(!Serial);
}

void loop()
{
  HttpClient client;
  client.get("http://mathemagie.net/projects/requiem/");

  while (client.available()) {
    char c = client.read();
    stringTweet = stringTweet + c;

  }
  Serial.flush();
  Serial.println("========================");
  Serial.println(stringTweet);
  //stringTweet = "T aurelien";//for test 
  
  stringTweet.toCharArray(charBuf, 50) ;
  for (int i = 0; i < stringTweet.length(); i++) {
     Serial.println(charBuf[i]);
     tradChar(charBuf[i]);
     delay(500);
  }
  Serial.println();
  delay(2000);
  stringTweet = "";
}

void tradChar(char c)                              // go function
{
   setChord(0,0,0,0,0,0,0,0,0,0,0,0);
  switch(c)                                  // Switch to code based on c
  {
    case 'a':
     setChord(1,0,0,0,0,0,0,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("a trouve");
      break;
    case 'b':
     setChord(0,1,0,0,0,0,0,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("b trouve");
      break;
    case 'c':
     setChord(0,0,1,0,0,0,0,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("c trouve");
      break;
    case 'd':
     setChord(0,0,0,1,0,0,0,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("d trouve");
      break;
    case 'e':
     setChord(0,0,0,0,1,0,0,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("e trouve");
      break;
    case 'f':
     setChord(0,0,0,0,0,1,0,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("f trouve");
      break;
    case 'g':
     setChord(0,0,0,0,0,0,1,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("g trouve");
      break;
    case 'h':
     setChord(0,0,0,0,0,0,0,1,0,0,0,0);
     delayTime = 50; 
      Serial.println("h trouve");
      break;
    case 'i':
     setChord(0,0,0,0,0,0,0,0,1,0,0,0);
     delayTime = 50; 
      Serial.println("i trouve");
      break;
    case 'j':
     setChord(0,0,0,0,0,0,0,0,0,1,0,0);
     delayTime = 50; 
      Serial.println("j trouve");
      break;
    case 'k':
     setChord(0,0,0,0,0,0,0,0,0,0,1,0);
     delayTime = 50; 
      Serial.println("k trouve");
      break;
    case 'l':
      setChord(0,0,0,0,0,0,0,0,0,0,0,1);
     delayTime = 50; 
      Serial.println("l trouve");
      break;
    case 'm':
      setChord(1,0,0,0,0,0,1,0,0,0,0,0);
     delayTime = 50; 
      Serial.println("m trouve");
      break;
    case 'n':
     setChord(0,0,1,0,0,0,0,0,0,1,0,0);
      delayTime = 50; 
      Serial.println("n trouve");
      break;
    case 'o':
     setChord(0,0,0,1,0,0,0,0,0,0,1,0);
      delayTime = 50; 
      Serial.println("o trouve");
      break;
    case 'p':
     setChord(0,0,0,0,1,0,0,0,0,0,0,1);
      delayTime = 50; 
      Serial.println("p trouve");
      break;
     case 'q':
     setChord(1,0,0,0,0,1,0,0,0,0,0,0);
      delayTime = 50; 
      Serial.println("q trouve");
      break;
    case 'r':
     setChord(0,1,0,0,0,0,1,0,0,0,0,0);
      delayTime = 50; 
      Serial.println("r trouve");
      break;
    case 's':
     setChord(0,0,1,0,0,0,0,1,0,0,0,0);
      delayTime = 50; 
      Serial.println("s trouve");
      break;
    case 't':
     setChord(0,0,0,1,0,0,0,0,1,0,0,0);
      delayTime = 50; 
      Serial.println("t trouve");
      break;
     case 'T':
     setChord(0,0,0,1,0,1,0,0,1,0,0,0);
      delayTime = 50; 
      Serial.println("T trouve");
      break;
     case 'u':
      setChord(0,0,0,0,1,0,0,0,0,1,0,0);
      delayTime = 50; 
      Serial.println("u trouve");
      break;
     case 'v':
      setChord(0,0,0,0,0,1,0,0,0,0,1,0);
      delayTime = 50; 
      Serial.println("v trouve");
      break;
     case 'w':
      setChord(0,0,0,0,0,1,0,0,0,0,1,0);
      delayTime = 50; 
      Serial.println("w trouve");
      break;
     case 'x':
      setChord(0,0,0,0,0,1,0,0,0,0,1,0);
      delayTime = 50; 
      Serial.println("x trouve");
      break;
     case 'y':
      setChord(0,0,0,0,0,0,0,0,0,0,1,0);
      delayTime = 50; 
      Serial.println("y trouve");
      break;
     case 'z':
      setChord(0,0,0,0,0,1,0,0,0,0,1,0);
      delayTime = 50; 
      Serial.println("z trouve");
      break;
     case ' ':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 1000; 
      Serial.println("espace trouve");
      break;
     case ':':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 1000; 
      Serial.println(": trouve");
      break;
     case '!':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 1100; 
      Serial.println("! trouve");
      break;
     case '?':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 500; 
      Serial.println("? trouve");
      break;
     case '.':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 1500; 
      Serial.println(". trouve");
      break;
     case ';':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 1000; 
      Serial.println("; trouve");
      break;
     case ',':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 800; 
      Serial.println("? trouve");
      break;
     case '/':
      setChord(0,0,0,0,0,0,0,0,0,0,0,0);
      delayTime = 700; 
      Serial.println("/ trouve");
      break;
     case '@':
      setChord(1,0,1,0,1,0,1,0,1,0,1,0);
      delayTime = 50; 
      Serial.println("@ trouve");
      break;  
     case 'é':
      setChord(1,1,1,0,0,0,0,0,0,0,0,0);
      delayTime = 500; 
      Serial.println("é trouve");
      break;
     case 'è':
      setChord(0,0,0,1,1,1,0,0,0,0,0,0);
      delayTime = 500; 
      Serial.println("è trouve");
      break;
  }
  pulseChord();   // Joue l'accord de la lettre
   delay(delayTime); 
 
    
}



///////////////////////
//
// Functions
//
///////////////////////


// Setup all solenoid pins as OUTPUTS
void setupSolPins()
{
	for(int i = 0; i<12; i++)
	{
		pinMode(solPin[i], OUTPUT);
		digitalWrite(solPin[i], LOW);
	}
}

// Only pulse one solenoid 
void pulseOne(int s)
{
	digitalWrite(solPin[s], HIGH);
	delay(PULSE_DELAY);
	digitalWrite(solPin[s], LOW);
}

// Pulse a whole chord
// Chord values are taken from the array : chord
// non-zero values indicate the solenoid is part of the chord and therefore to be played
void pulseChord()
{
	for(int i=0; i<12; i++){
	    if(chord[i]!=0){
	        digitalWrite(solPin[i], HIGH);
	    }
	}
	delay(PULSE_DELAY);
	for(int i=0; i<12; i++){
	    digitalWrite(solPin[i], LOW);
	}
}

// Sets a whole chord at a time
void setChord(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
	chord[0] = a;
	chord[1] = b;
	chord[2] = c;
	chord[3] = d;
	chord[4] = e;
	chord[5] = f;
	chord[6] = g;
	chord[7] = h;
	chord[8] = i;
	chord[9] = j;
	chord[10] = k;
	chord[11] = l;
}
