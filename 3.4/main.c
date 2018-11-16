#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "donnee.h"
#include "actions.h"

int main()
{
    int n = 5000;
    printf("Reccupecration des donnees en cours...       Veuillez patientez...\n\n", 130, 130, 130);
    structure tableau_donnees[n];
    RemplirTableau(tableau_donnees,n);
    menu(tableau_donnees,n);
}
