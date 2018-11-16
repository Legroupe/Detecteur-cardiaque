#include "menu.h"
#include "generationCode.h"

//Code de la première fonction, affiche un menu de choix pour allumer les leds de différents façons

void choixFonction()
{

    int choix;
    printf("Choisir la fonction\n");
    printf("1. Serpentin\n");
    printf("2. Clignotement rapide\n");
    printf("3. Allumage eteignage bizzare\n");
    printf("4. Allumage progressif\n");
    printf("5. Battement de coeur\n");
    printf("6. Clignotement de ouf\n");
    printf("7. Clignotement de ouf ralenti\n");
    printf("8. Allumer perma\n");
    printf("9. Eteint pour la vie\n");
    scanf("%d",&choix);

    //Une fois le numéro saisi, la deuxième fonction est exécutée avec la variable choix comme paramètre

    generation(choix);
}
