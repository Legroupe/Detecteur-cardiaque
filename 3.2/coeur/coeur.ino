#include "coeur.h"
#include "param.h"
#include "coeur.c"

 
void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT); 
  pinMode(LED3, OUTPUT); 
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);  
}


void loop() {

switch(CHOIX)
    {
    case 1:
        serpentin();
        break;
    case 2:
        clignotementRapide();
        break;
    case 3:
       serpentinInverser();
        break;
    case 4:
        battementDeCoeur();
        break;
    case 5:
        battementDeCoeurBadass();
        break;
    case 6:
        clignotementDeOuf();
        break;
    case 7:
        allumageUnSurDeux();
        break;
    case 8:
        allumerPerma();
        break;
    case 9:
        eteintPourLaVie();
        break;
    }
}
