#include <Arduino.h>
#include "interVolet.h"

int InterVolet::cptInter=0;
InterVolet* tblIntersVolets[10]={nullptr};

InterVolet::InterVolet(int pinInterMonte, int pinInterDescend){
    _pinInterMonte=pinInterMonte;
    _pinInterDescend=pinInterDescend;
    _numInter=cptInter;
    cptInter++;
    tblIntersVolets[_numInter]=this;
}
/*
Les interruptions ne peuvent être rattachées qu'à des fonctions et non des objets, la solution
est de créer des méthodes statiques et de les attachées au momment de l'instanciation des objets
pour que les méthodes puissent faire référence aux objets on les enregistres dans un tableau statiques
et chaque méthode appel un objet à un index différent
*/


void InterVolet::init(){
    pinMode(_pinInterMonte, INPUT_PULLUP);
    pinMode(_pinInterDescend, INPUT_PULLUP);
    switch  (_numInter){
        case 0:
            attachInterrupt(_pinInterMonte, ISRinterVolet0,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet0,CHANGE);
            break;
        case 1:
            attachInterrupt(_pinInterMonte, ISRinterVolet1,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet1,CHANGE);
            break;
        case 2:
            attachInterrupt(_pinInterMonte, ISRinterVolet2,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet2,CHANGE);
            break;
        case 3:
            attachInterrupt(_pinInterMonte, ISRinterVolet3,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet3,CHANGE);
            break;
        case 4:
            attachInterrupt(_pinInterMonte, ISRinterVolet4,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet4,CHANGE);
            break;
        case 5:
            attachInterrupt(_pinInterMonte, ISRinterVolet5,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet5,CHANGE);
            break;
        case 6:
            attachInterrupt(_pinInterMonte, ISRinterVolet6,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet6,CHANGE);
            break;
        case 7:
            attachInterrupt(_pinInterMonte, ISRinterVolet7,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet7,CHANGE);
            break;
        case 8:
            attachInterrupt(_pinInterMonte, ISRinterVolet8,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet8,CHANGE);
            break;
        case 9:
            attachInterrupt(_pinInterMonte, ISRinterVolet9,CHANGE);
            attachInterrupt(_pinInterDescend, ISRinterVolet9,CHANGE);
            break;

    }
}

void InterVolet::setSens(){
    if(digitalRead(_pinInterMonte)==LOW)_sens='M';
    else {
        if(digitalRead(_pinInterDescend)==LOW)_sens='D';
        else _sens='S';
    }
   
    Serial.print(_numInter);
    Serial.print(" : ");
    Serial.println(_sens);
}

volatile char InterVolet::sens(){
    return _sens;
}

void InterVolet::acknow(){
    _sens='0';
}

void ISRinterVolet0(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[0]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet1(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[1]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet2(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[2]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet3(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[3]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet4(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[4]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet5(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[5]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet6(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[6]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet7(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[7]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet8(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[8]->setSens();
        dateDernierChangement = date;
    }
}
void ISRinterVolet9(){
    static unsigned long dateDernierChangement = 0;
    
    unsigned long date = millis();
    if ((date - dateDernierChangement) > 20) {
        tblIntersVolets[9]->setSens();
        dateDernierChangement = date;
    }
}