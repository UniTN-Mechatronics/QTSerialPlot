#define PLOT Serial.print("#!"); Serial.print("\t");
#include "low_pass.h"

Low_pass lpf1(1);
Low_pass lpf2(1);

int counter = 0;
int step = 0;
unsigned long time;
double sig1;
double sig2;

void setup() {
  // put your setup code here, to run once:
	Serial.begin(115200);
}



void loop() {
  // put your main code here, to run repeatedly:
	counter++;
	if(counter == 101) {
		counter = 0;
		if(step == 0) {
			step = 100;
		}else{
			step = 0;
		}
	}

	sig1 = lpf1.update(counter, 0.01);
	sig2 = lpf2.update(step, 0.01);

	time = millis();
	PLOT;
	Serial.print(time/1000.0, 4);
	Serial.print("\t");
	Serial.print(counter/1.0, 4);
	Serial.print("\t");
	Serial.print(sig1, 4);
	Serial.print("\t");
	Serial.print(step/1.0, 4);
	Serial.print("\t");
	Serial.println(sig2, 4);

  delay(10);


}