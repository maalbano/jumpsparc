

#include <stdio.h>
#include <wiringPi.h>

#define	BEEP 26
#define RELAY 1

int main (void)
{
  int i = 0;
  printf ("Raspberry Pi Beep\n") ;

  wiringPiSetup () ;
  pinMode (BEEP, OUTPUT) ;
  pinMode (RELAY, OUTPUT);

  for (i=0;i<5;i++)
  {
    digitalWrite (BEEP, HIGH) ;	// On
    delay (200) ;		// mS
    digitalWrite (BEEP, LOW) ;	// Off
    delay (400) ;
  }
  return 0 ;
}
