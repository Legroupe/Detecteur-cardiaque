

#include "cardio.h"
#include <Arduino.h>



long CalculPoul(long tempspoul, long tempsIntermediaire)
{
  return (1000.0 * 60.0) / (tempspoul - tempsIntermediaire); //Dans ce calcul, nous convertissons la difference du temps lors de la detection d'un pouls
}                                                            //et du temps de detection d'un precedent pouls
