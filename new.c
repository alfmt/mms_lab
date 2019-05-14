#include <stdio.h>
#include <wiringPi.h>

#define LED1 1
#define LED2 4
#define BUTTON 5
int main(){
  if(wiringPiSetup() == -1)
 	  return 1;
  pinMode (LED1, PWM_OUTPUT);
  pinMode (LED2, OUTPUT);

  digitalWrite(LED1, 1);
  
  pwmSetClock(19);
  pwmSetMode(PWM_MODE_MS);

  pwmSetRange(4000000);
  pwmWrite(1, 2000000);
  
  while(1){
    int sw_in_val = digitalRead(BUTTON);
    if(!sw_in_val){
      for(int j=0; j<5; j++){
        digitalWrite(LED2, 0);
        delay(200);
        digitalWrite(LED2, 1);
        delay(200);
      }
    }
  }
  return 0;

}
