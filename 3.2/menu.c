#include "menu.h"
#include "generationCode.h"

//Code de la premi�re fonction, affiche un menu de choix pour allumer les leds de diff�rents fa�ons

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

    //Une fois le num�ro saisi, la deuxi�me fonction est ex�cut�e avec la variable choix comme param�tre

    generation(choix);
}
