/*
  InterVolet.h - Library pour lire les interrupteurs de volet roulant
  Created by Nicolas Moine, January 26th, 2020.
*/
#ifndef InterVolet_h
  #define InterVolet_h

  #include <Arduino.h>

  class InterVolet
  {
    public:
        InterVolet(int pinInterMonte, int pinInterDescend);
        void init();
        void acknow();
        volatile char sens();
        void setSens();
       
      private:

        int _pinInterMonte;
        int _pinInterDescend;
        int _numInter;
        volatile char _sens='0';
        static int cptInter;
        
  };


extern void ISRinterVolet0();
extern void ISRinterVolet1();
extern void ISRinterVolet2();
extern void ISRinterVolet3();
extern void ISRinterVolet4();
extern void ISRinterVolet5();
extern void ISRinterVolet6();
extern void ISRinterVolet7();
extern void ISRinterVolet8();
extern void ISRinterVolet9();

#endif