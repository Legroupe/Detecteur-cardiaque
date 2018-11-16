

int Simulation(int repere,int repere_const)        //Dans cette fonction, nous simulons des valeurs basses et hautes à intervalle régulier correspondant à la durée d'un battement et l'écart entre deux battements.
{                                                  //Cet intervalle est aléaoire et importe peu, il suffit juste qu'il soit assez grand pour être identifiable par le système
  int m = 0;
  if (repere < (repere_const/2))                //Si repere est inferieur  à 25 (valeur aleatoire), on insere des valeurs correspondant à un etat bas
  { 
    m=rand()%20 + 300;       //On affecte la valeur aléatoire basse à 20% autour de 300
  }
  if (repere >=(repere_const/2) && repere <repere_const)  //Si repere est compris entre 25 et 50 (valeurs aleatoires), on insere des valeurs correspondant à un etat haut
  {
    m=rand()%20 + 700;       //On affecte la valeur aléatoire basse à 20% autour de 700
  } 
  
  return m;
} 
