#include "stopWatch.h"
#include "Arduino.h"



void stopWatch::start(){
  InitT = millis();
}

void stopWatch::stop(){
  DenitT = millis();
}

void stopWatch::reset(){
  InitT = 0;
  DenitT = 0;
}

int stopWatch::elapsed(){
  if(InitT == 0){
    return(0);
  }
  else if(DenitT == 0){
    return(millis() - InitT);
  }
  else{
    ElapT = DenitT - InitT;
    return(ElapT);
  }
} 
