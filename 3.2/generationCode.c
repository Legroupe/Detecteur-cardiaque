#include "generationCode.h"
#include <stdlib.h>
#include <stdio.h>

//Code de la deuxième fonction

void generation(int choix)
{
    FILE *fichier = NULL;

    fichier =  fopen("coeur/param.h", "w+"); //ouvre le fichier param.h en lecture/écriture avec supression du contenu au préalable

    if(fichier!=NULL)
    {

    //En fonction du choix, ajoute dans le fichier param.h une nouvelle valeur de CHOIX qui influencera le programme Arduino

    switch(choix)
    {
    case 1:
        fputs("#define CHOIX 1", fichier);
        fclose(fichier);
        break;
    case 2:
        fputs("#define CHOIX 2", fichier);
        fclose(fichier);
        break;
    case 3:
        fputs("#define CHOIX 3", fichier);
        fclose(fichier);
        break;
    case 4:
        fputs("#define CHOIX 4", fichier);
        fclose(fichier);
        break;
    case 5:
        fputs("#define CHOIX 5", fichier);
        fclose(fichier);
        break;
    case 6:
        fputs("#define CHOIX 6", fichier);
        fclose(fichier);
        break;
    case 7:
        fputs("#define CHOIX 7", fichier);
        fclose(fichier);
        break;
    case 8:
        fputs("#define CHOIX 8", fichier);
        fclose(fichier);
        break;
    case 9:
        fputs("#define CHOIX 9", fichier);
        fclose(fichier);
        break;
    }

    }
}
