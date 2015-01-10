
#include <stdio.h>
#include <wiringPi.h>

#define	BEEP 26
#define RELAY 1

int delayTime = 500;
int alarmTime = 0;

void clearLEDs(void)  {
    alarmTime = 0;
}

void turnOn(void) {
    digitalWrite(RELAY, HIGH);   
}

void turnOff(void) {
    digitalWrite(RELAY, LOW); 
    clearLEDs();

} 

void setAlarm(int time)
{
	int seconds = time;
	if (seconds == 0)
	    seconds = 240;//240;
		
	alarmTime = millis() + seconds*1000;
	printf("alarmTime: %d\n", alarmTime);
	turnOn();
}

void checkAlarm() {
    if (millis() >= alarmTime) {
        turnOff();

    }
}

// This routine runs only once upon reset
void setup() {
  pinMode(RELAY, OUTPUT);
  pinMode(BEEP, OUTPUT);
  
  digitalWrite(BEEP, LOW);
  digitalWrite(RELAY, LOW);

}

void loop() {  
  delay(delayTime);
  
  checkAlarm();

  delay(delayTime);
  
  checkAlarm();

}

int main (void)
{

  wiringPiSetup () ;

	setup();
	
	printf("start time: %d\n", millis());	
	setAlarm(0);
	
	digitalWrite(BEEP, HIGH); delay(200);
    digitalWrite(BEEP, LOW);
	
//  for (;;) {
	while (alarmTime > 0) {
  		loop();
  		printf("time: %d\n",millis());
  		
    }
  
  digitalWrite(BEEP, HIGH); delay(200);
  digitalWrite(BEEP, LOW); delay(200);
  digitalWrite(BEEP, HIGH); delay(200);
  digitalWrite(BEEP, LOW); delay(200);
  digitalWrite(BEEP, HIGH); delay(200);
  digitalWrite(BEEP, LOW); delay(200);
  return 0 ;
}

