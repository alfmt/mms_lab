#include <stdio.h>
#include <wiringPi.h>

#define LED1 1
#define LED2 4
#define BUTTON 5
int main(){
  if(wiringPiSetup() == -1)
 	  return 1;
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);

  digitalWrite(LED1, 1);
  while(1){
    digitalWrite(LED1, 0);
    delay(2000);
    digitalWrite(LED1, 1);
    delay(2000);

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
