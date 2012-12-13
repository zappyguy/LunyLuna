#include "stopWatch.h"
#include "update.h"
#include "arduino.h"

stopWatch SW;

void update::init(){
  while(innerAmb == 0 && outterAmb == 0){

    innerAmb = analogRead(0);
    outterAmb = analogRead(1);
  }
}

void update::ambiVals(){
  innerArray[i] = analogRead(0);
  outterArray[i] = analogRead(1);
  SW.reset();
  i++;

  if(i == 301){
    innerAmb = 0;
    outterAmb = 0;
    while(i != 0){
      i--;
      innerAmb += innerArray[i];
      outterAmb += outterArray[i];
    }
    innerAmb /= 300;
    outterAmb /= 300;
  }
}

bool update::checkIn(){
  return(analogRead(0) > (0.4 * innerAmb));
}

bool update::checkOut(){
  return(analogRead(1) > (0.4 * outterAmb));
}

int update::walkIn(){
  j = 0;
  Serial.println("Someone walking in");
  while(j == 0){
    if(!checkIn() && !checkOut()){
      Serial.println("going to walkInOut");
      walkIn2();
    }
    else if(checkIn() && checkOut()){
      break;
    }
    else{
    }
  }
  return j;
}

int update::walkOut(){
  j = 0;
  Serial.println("Someone walking out");
  while(j == 0){
    if(!checkIn() && !checkOut()){
      Serial.println("going to walkInOut");
      walkInOut();
    }
    else if(checkIn() && checkOut()){
      break;
    }
    else{
    }
  }
  return j;
}

void update::walkIn2(){
  while(j == 0){
    //Walking in

    if(!checkIn() && checkOut()){
      Serial.println("Someone walked in");
      j = 1;
      while(!checkIn() && checkOut()){
      }
    }

    //Walk out
    else if(checkIn() && !checkOut()){
      Serial.println("Someone walked out");
      j = 2;
      while(!checkIn() && checkOut()){
      }
    }
  }
}

