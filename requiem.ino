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




///////////////////////
//
// Code
//
/////////////////////////

void setup()
{
	setupSolPins();
}

void loop()
{
	for(int i=0; i<3; i++)
	{
		//pulseOne(i);
		delay(1000);
                Serial.println("moteur " + String(i) );
	}

	//setChord(1,0,1,0,1,0,1,0,1,0,1,0);
	//pulseChord();
        //delay(200);
	//setChord(0,1,0,1,0,1,0,1,0,1,0,1);
	//pulseChord();
	//delay(200);
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
