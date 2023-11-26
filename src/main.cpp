#include <Arduino.h>
#include <TeensyTimerInterrupt.h>
#include <TeensyTimerInterrupt.hpp>
#include <Teensy_ISR_Timer.h>
#include <Teensy_ISR_Timer.hpp>



// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error

// #include "src/Teensy_ISR_Timer.h"           //https://github.com/khoih-prog/Teensy_TimerInterrupt

#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     2

// You can select Teensy Hardware Timer  from TEENSY_TIMER_1 or TEENSY_TIMER_3

// Init Teensy timer TEENSY_TIMER_1

TeensyTimer ITimer0(TEENSY_TIMER_1);

// may need to be timer 3 ....

// Interval (in microseconds)
// For Teensy 4.0/4.1, F_BUS_ACTUAL = 150 MHz => max interval/period is only 55922 us (~17.9 Hz)

bool setInterval(unsigned long interval, timerCallback callback);

// interval (in microseconds) and duration (in milliseconds). Duration = 0 or not specified => run indefinitely
// No params and duration now. To be added in the future by adding similar functions here or to NRF52-hal-timer.c
// Above or this one ...bool attachInterruptInterval(unsigned long interval, timerCallback callback);

void TimerHandler0(void)
{
  // Doing something here inside ISR Read ADC etc. 
  Serial.print("This is interrupt \n");
}

// For Teensy 4.0/4.1, F_BUS_ACTUAL = 150 MHz => max period is only 55922 us (~17.9 Hz)

#define TIMER0_INTERVAL_MS        50L

void setup()
{
  
  // Interval in microsecs ... suspect this SB seconds??
  if (ITimer0.attachInterruptInterval(TIMER0_INTERVAL_MS * 1000, TimerHandler0))
  {
    Serial.print("Starting ITimer0 OK, millis() = "); Serial.println(millis());
  }
  else
    Serial.println("Can't set ITimer0. Select another freq. or timer");
}  

int a = 0;
void loop(){
  Serial.print("This is loop ");
  Serial.println(a++);
  delay(500);
}

/*
main(){
  setup();
  while(1){
    loop();
  } 
}*/
