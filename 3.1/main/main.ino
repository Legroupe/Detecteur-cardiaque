

#include "cardio.c"
#include "simulateur.c"

int valeur_intermediaire = 0;       //Cette variable servira à stocker la valeur analogique du pouls de la boucle précédente
long temps_intermediaire = 0;       //Cette variable servira à stocker le temps du pouls de la boucle précédente
int seuil = 0;                      //Cette variable sert à savoir si nous sommes dans un état ou le sang passe ou non
int entree_analogique;              //Cette varaible sert à contenir les valeur lues par le capteur ou simulées
int val_pouls;                      //Variable contenant l'etat du pouls (0 ou 1) pour le programme coeur.ino
int valeur_repere = 500, repere_battement=10000;   //Ces variables sont respectivement un repere pour différencier un etat de pouls haut et bas
                                                    //Et un repere pour le simulateur pour la quantité de meme valeur à générer
long temps_debut_poul;              //Contient la valeur du temps du début de mesure du pouls
int choix = 0;                      //Permet de choisir entre lire les valeurs sur le capteur ou simuler ces valeurs

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}


void loop() {
  if (seuil >= repere_battement)                //Si repere dépasse notre encadrement, il est reinitialisé
  {  
    seuil = 0;
  }
  if (choix == 0)                               //Si on décide de générer les valeurs par le capteur
  {
    entree_analogique = analogRead(0);          //On affecte entree_analogique à la valeur analogique lue
  }
  else if (choix == 1)                          //Si on décide de générer les valeurs par le simulateur
  {
    entree_analogique = Simulation(seuil,repere_battement);   //On affecte entree_analogique à la valeur analogique simulée
  }
  else
  {
    Serial.println("Ce n'est pas un choix valide");   //Si le choix entré est incorrect, on envoie un message d'erreur
  }
  seuil++;                                            //On incrémente le seuil                             
  if (entree_analogique > valeur_repere) {            //On vérifie si entree_analogique est supérieur au repère afin de déterminer si du sang passe
    
    if (valeur_intermediaire <= valeur_repere) {      //On vérifie si le valeur du cycle de boucle précédent est inférieur au repere si oui, cela signifie qu'un nouveau battement commence
      temps_debut_poul = millis();                    //Le temps du debut du battement est affecté au temps qu'i s'est écoulé depuis l'exécution du programme
      if (temps_debut_poul > (temps_intermediaire + 200)){        //On détermine qu'il s'est écoulé 200 millisecondes depuis la mesure du début du battement précédent
        long poul = CalculPoul(temps_debut_poul, temps_intermediaire);      //On calcul le pouls à partir des informations récoltées
        Serial.print(temps_debut_poul);                                     //Affichage du temps associé au pouls
        Serial.print(";");                                                  //Affichage d'un ";" pour la lecture du port série par processing
        Serial.println(poul);                                               //Affichage du pouls
        temps_intermediaire = temps_debut_poul;                             //Le temps du pouls calculé est affecté comme étant le temps du battement précédent pour la boucle suivante
      }
    }
  }
  valeur_intermediaire = entree_analogique;     //La valeur lue est affecté comme étant la valeur précédente pour la boucle suivante
}

  
