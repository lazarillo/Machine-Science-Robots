#include <mxapi.h>
#include <servo.h>
#include <adc.h>
#include <sound.h>

int main(void)
{
  servo_init();
  adc_init();
  int turnDir= 0;
  while(1==1)
    {
      if(adc_read(ADC5)>100)
	{
	  if(turnDir == 0)
	    {
	      servo_robot(SPIN_RIGHT, 60);
	      turnDir= 1;
	    } else {
	    servo_robot(SPIN_LEFT, 60);
	    turnDir= 0;
	  }
	  servo_robot(REVERSE, 100);
	}
      else
	{
	  servo_robot(FORWARD, 100);
	}
    }
}
