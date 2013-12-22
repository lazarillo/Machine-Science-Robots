#include <mxapi.h>
#include <servo.h>
#include <adc.h>
#include <sound.h>

int main(void)
{
  servo_init();
  adc_init();
  signed int newSpeed= 0;
  int sensorRead= 650;
  int scalarSpeed= 0;
  int visionSweep= 0;
  while(1==1)
    {
      visionSweep= 0;
      sensorRead = adc_read(ADC5);
      while(visionSweep < 30)
	{
	  if (adc_read(ADC5) > sensorRead) {
	    sensorRead= adc_read(ADC5);
	  }
	  servo_robot(SPIN_RIGHT, 20);
	  delay_ms( 10 );
	  visionSweep= visionSweep + 1;
	}
      visionSweep= 0;
      while(visionSweep < 60)
	{
	  if (adc_read(ADC5) > sensorRead) {
	    sensorRead= adc_read(ADC5);
	  }
	  servo_robot(SPIN_LEFT, 15);
	  delay_ms( 10 );
	  visionSweep= visionSweep + 1;
	}
      visionSweep= 0;
      while(visionSweep < 30)
	{
	  if (adc_read(ADC5) > sensorRead) {
	    sensorRead= adc_read(ADC5);
	  }
	  servo_robot(SPIN_RIGHT, 20);
	  delay_ms( 10 );
	  visionSweep= visionSweep + 1;
	}
      newSpeed= ( ( (sensorRead * -4) + 1700) / 9);
      if (newSpeed < 0)
	{
	  if (newSpeed < -95)
	    {
	      newSpeed= -95;
	    }
	  scalarSpeed= (-1 * newSpeed);
	  servo_robot(REVERSE, scalarSpeed);
	  delay_ms( 500 );
	} else {
	if (newSpeed > 95)
	  {
	    newSpeed= 95;
	  }
	scalarSpeed= newSpeed;
	servo_robot(FORWARD, scalarSpeed);
      }
      delay_ms( ( (newSpeed * 3) + 500) );
      if ( (sensorRead % 2) == 0)
	{
	  servo_robot(SPIN_RIGHT, ( (scalarSpeed % 20) * 5) );
	} else {
	servo_robot(SPIN_LEFT, ( (scalarSpeed % 20) * 5) );
      }
      delay_ms( ( (newSpeed * -2) + 300) );

      if ( (sensorRead % 10) == 0)
	{
	  servo_robot(STOP, 0);
	  if ( (sensorRead % 20) == 0)
	    {
	      tone_out(PORT_D4, A4N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, A4N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, A4N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, F4N, Nd04);
	      tone_out(PORT_D4, C5N, No08);

	      delay_ms( 50 );
	      tone_out(PORT_D4, A4N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, F4N, Nd04);
	      tone_out(PORT_D4, C5N, No08);
	      delay_ms( 50 );
	      tone_out(PORT_D4, A4N, No01);

	      delay_ms( 50 );
	      tone_out(PORT_D4, E5N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, E5N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, E5N, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, F5N, Nd04);
	      tone_out(PORT_D4, C5N, No08);

	      delay_ms( 50 );
	      tone_out(PORT_D4, A4F, No02);
	      delay_ms( 50 );
	      tone_out(PORT_D4, F4N, Nd04);
	      tone_out(PORT_D4, C5N, No08);
	      delay_ms( 50 );
	      tone_out(PORT_D4, A4N, No01);
	    }
	  else
	    {
	      tone_out(PORT_D4, G4N, No08);
	      tone_out(PORT_D4, G4N, No08);
	      tone_out(PORT_D4, A4N, No04);
	      tone_out(PORT_D4, G4N, No04);
	      tone_out(PORT_D4, C5N, No04);
	      tone_out(PORT_D4, B4N, No02);
	      delay_ms( 200 );

	      tone_out(PORT_D4, G4N, No08);
	      tone_out(PORT_D4, G4N, No08);
	      tone_out(PORT_D4, A4N, No04);
	      tone_out(PORT_D4, G4N, No04);
	      tone_out(PORT_D4, D5N, No04);
	      tone_out(PORT_D4, C5N, No02);
	      delay_ms( 200 );

	      tone_out(PORT_D4, G4N, No08);
	      tone_out(PORT_D4, G4N, No08);
	      tone_out(PORT_D4, G5N, No04);
	      tone_out(PORT_D4, E5N, No04);
	      tone_out(PORT_D4, C5N, No04);
	      tone_out(PORT_D4, B4N, No04);
	      tone_out(PORT_D4, A4N, No02);
	      delay_ms( 200 );

	      tone_out(PORT_D4, F5N, No08);
	      tone_out(PORT_D4, F5N, No08);
	      tone_out(PORT_D4, E5N, No04);
	      tone_out(PORT_D4, C5N, No04);
	      tone_out(PORT_D4, D5N, No04);
	      tone_out(PORT_D4, C5N, No02);
	    }
	}
    }
}
