#include <stdio.h>
#include <wiringPi.h>

#define LED1 1
#define LED2 4
#define BUTTON 5
void inter(){
  for(int i=0; i<5; i++){
    digitalWrite(LED2, 0);
    delay(200);
    digitalWrite(LED2, 1);
    delay(200);
  }

}
int main(){
  if(wiringPiSetup() == -1)
 	  return 1;
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);

  digitalWrite(LED1, 1);
  wiringPiISR(BUTTON,INT_EDGE_FALLING,&inter);
  while(1){
    digitalWrite(LED1, 0);
    delay(2000);
    digitalWrite(LED1, 1);
    delay(2000);
  }

  return 0;

}
