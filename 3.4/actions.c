#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "donnee.h"


void affichage_tableau(structure tableau[], int TAILLE) // Cette fonction sert a afficher toutes le contenu d'un tableau structure
{
    int i;
    for (i=0; i< (TAILLE+1); i++)
    {
        printf("Temps : %f\t/\tPouls : %d\n", tableau[i].temps, tableau[i].pouls); //Affichage des composantes de rang i+1
    }
}

//--------------------------------------------------------------------------------------

 // Cette fonction permet de trier les composantes temps par ordre croissant
void tri_bulles_croissant_par_temps(structure tabl[], int Taille)
{
    short tab_en_ordre = 0;
    float temp; //variable permettant l'echange de 2 valeurs du temps qui se suivent
    int temp_2; //variable permettant l'echange de 2 valeurs du pouls qui se suivent
    while(!tab_en_ordre)
    {
        tab_en_ordre = 1;
        int i;
        for(i=0 ; i < Taille ; i++)
        {
            if(tabl[i].temps > tabl[i+1].temps) //Si la valeur de rang i est superieure a celle de rang i+1,
            {                                   //nous les interchangeons
                temp = tabl[i].temps;             // la variable temp stock temporairement la valeur du temps en i pour...
                tabl[i].temps = tabl[i+1].temps;  //...permettre l'echange des valeurs du temps et i+1 et celle ci
                tabl[i+1].temps = temp;
                temp_2 = tabl[i].pouls; // la meme chose est faite avec le pouls pour que le pouls associé au temps reste la bonne valeur
                tabl[i].pouls = tabl[i+1].pouls;
                tabl[i+1].pouls = temp_2;
                tab_en_ordre = 0;
            }
        }
        Taille-- ;
    }

}

//--------------------------------------------------------------------------------------

// Cette fonction permet de trier les composantes pouls par ordre croissant
void tri_bulles_croissant_par_pouls(structure tabl[], int Taille)
{
    short tab_en_ordre = 0;
    int temp;
    float temp_2;
    while(!tab_en_ordre)
    {
        tab_en_ordre = 1;
        int i;
        for(i=0 ; i < Taille ; i++)
        {
            if(tabl[i].pouls > tabl[i+1].pouls) //Si la valeur de rang i est superieure a celle de rang i+1,
            {                                   //nous les interchangeons
                temp = tabl[i].pouls;
                tabl[i].pouls = tabl[i+1].pouls;
                tabl[i+1].pouls = temp;
                temp_2 = tabl[i].temps;
                tabl[i].temps = tabl[i+1].temps;
                tabl[i+1].temps = temp_2;
                tab_en_ordre = 0;
            }
        }
        Taille-- ;
    }

}

//--------------------------------------------------------------------------------------

// Cette fonction permet de trier les composantes temps par ordre decroissant
void tri_bulles_decroissant_par_temps(structure tabl[], int Taille)
{
    short tab_en_ordre = 0;
    float temp;
    int temp_2;
    while(!tab_en_ordre)
    {
        tab_en_ordre = 1;
        int i;
        for(i=0 ; i < Taille ; i++)
        {
            if(tabl[i].temps < tabl[i+1].temps) //Si la valeur de rang i est superieure a celle de rang i+1,
            {                                   //nous les interchangeons
                temp = tabl[i].temps;
                tabl[i].temps = tabl[i+1].temps;
                tabl[i+1].temps = temp;
                temp_2 = tabl[i].pouls;
                tabl[i].pouls = tabl[i+1].pouls;
                tabl[i+1].pouls = temp_2;
                tab_en_ordre = 0;
            }
        }
        Taille-- ;
    }

}

//--------------------------------------------------------------------------------------

// Cette fonction permet de trier les composantes pouls par ordre decroissant
void tri_bulles_decroissant_par_pouls(structure tabl[], int Taille)
{
    short tab_en_ordre = 0;
    int temp;
    float temp_2;
    while(!tab_en_ordre)
    {
        tab_en_ordre = 1;
        int i;
        for(i=0 ; i < Taille; i++)
        {
            if(tabl[i].pouls < tabl[i+1].pouls )//Si la valeur de rang i est inferieure a celle de rang i+1,
            {                                   //nous les interchangeons
                temp = tabl[i].pouls ;
                tabl[i].pouls  = tabl[i+1].pouls ;
                tabl[i+1].pouls  = temp;
                temp_2 = tabl[i].temps ;
                tabl[i].temps  = tabl[i+1].temps ;
                tabl[i+1].temps  = temp_2;
                tab_en_ordre = 0;
            }
        }
        Taille-- ;
    }

}

//--------------------------------------------------------------------------------------

//Cette fonction tri et recherche un pouls en fonction de son temps correspondant
int Rechercher_et_afficher_donnees_en_fonction_du_temps(structure tab[], int nb_lignes)
    {
    tri_bulles_croissant_par_temps(tab, nb_lignes); //tri du tableau
    float val;
    printf("Inserer la valeur que vous souhaitez rechercher :");
    scanf("%f", &val);
    int position;
    int id, ifin, im; //indice de d�but, indice de fin et indice de milieu.
    id = 0;         // intervalle de recherche compris entre 0,
    ifin = nb_lignes; // ,et le nombre de lignes.
    position = -1;  //position initialisee a -1
    while ((id<=ifin) && (position==-1))    //tant que nous ne sommes pas arrives a la fin de l'intervalle et que position n'a pas chang�
        {
         im=(ifin+id)/2;                    //calcul du milieu de l'intervalle
         if (val < tab[im].temps)           //determine si la valeur cherchee est inferieure ou superieure au milieu de l'intervalle
               ifin=im-1;
         else if (val > tab[im].temps)
               id=im+1;
         else                               //Si elle n'est ni superieure ni inferieure, elle est egale,
               position=im;               //le pouls cherche est trouve
        }
    if (position != -1)                     //Si la valeur est trouvee, on la retourne

        printf("%d",
               tab[position].pouls);

    else                                    //Sinon cela signifie que la valeur n'existe pas

        printf("Cette valeur n'est pas presente dans le tableau");
        return -1;
}

//--------------------------------------------------------------------------------------

//Cette fonction affiche les donnees dans l'ordre dans lequel elles apparaissent dans le fichier
void Donnee_ordre_du_fichier(structure tab[], int nb_lignes)
{
   affichage_tableau(tab, nb_lignes);   //Appel de la fonction realisant cette tache
}

//--------------------------------------------------------------------------------------

//Cette fonction permet a l'utilisateur de chosir entre 4 modes d'affichage...
void Ordre_croissant_ou_decroissant(structure tab[], int nb_lignes)
{
    int choix1, choix2, i;
    printf("Si ordre croissant, inserer 0 \n Si ordre decroissant, inserer 1\n");
    scanf("%d", &choix1);
    switch (choix1)
    {
        case 0: printf("Si le temps doit etre trie, inserer 0 \n Si le pouls doit etre trie, inserer 1\n");
                scanf("%d", &choix2);
                switch (choix2)
                {
                    case 0 : printf("Classement selon temps par ordre croissant\n");      //... 1 , selon le temps par ordre croissant
                             tri_bulles_croissant_par_temps(tab,nb_lignes);               //Appel de la fonction realisant la tache souhaitee
                             affichage_tableau(tab, nb_lignes);
                             return -1;
                    case 1 : printf("Classement selon pouls par ordre croissant\n");      //... 2 , selon le pouls par ordre croissant
                             tri_bulles_croissant_par_pouls(tab,nb_lignes);               //Appel de la fonction realisant la tache souhaitee
                             affichage_tableau(tab, nb_lignes);
                             return -1;
                    default :printf("Le second choix n'est pas correct\n");               //Envoie un message d'erreur si le choix2 rentre n'est pas valide
                             return -1;
                }
        case 1 : printf("Si le temps doit etre trie, inserer 0 \n Si le pouls doit etre trie, inserer 1\n");
                 scanf("%d", &choix2);
                 switch (choix2)
                 {
                    case 0 : printf("Classement selon temps par ordre decroissant\n");     //... 1 , selon le temps par ordre decroissant
                             tri_bulles_decroissant_par_temps(tab,nb_lignes);              //Appel de la fonction realisant la tache souhaitee
                             affichage_tableau(tab, nb_lignes);
                             return -1;
                    case 1 : printf("Classement selon pouls par ordre decroissant\n");     //... 1 , selon le pouls par ordre decroissant
                             tri_bulles_decroissant_par_pouls(tab,nb_lignes);              //Appel de la fonction realisant la tache souhaitee
                             affichage_tableau(tab, nb_lignes);
                             return -1;
                    default :printf("Le second choix n'est pas correct\n");                //Envoie un message d'erreur si le choix2 rentre n'est pas valide
                             return -1;
                }
        default : printf("Le premier choix n'est pas correct");                            //Envoie un message d'erreur si le choix1 rentre n'est pas valide
                  return -1;
    }
}

//--------------------------------------------------------------------------------------

//Cette fonction calcul le pouls moyen
int Moyenne_pouls(structure tab[], int nb_lignes)
{
    int somme = 0, i ;
    for (i=0; i < nb_lignes;i++)    //Nous calculons d'abord la somme de tous les pouls
    {
        somme += tab[i].pouls;
    }
    int resultat = somme/nb_lignes;
    printf("Le pouls est d'en moyenne %d battements par minute",resultat);       //Nous divisons la somme par le nombre total afin d'obtenir la moyenne
}

//--------------------------------------------------------------------------------------

//Cette fonction affiche le nombre de ligne du tableau utilisees pour stocker des donnees
void Afficher_nbr_lignes_de_donnees(structure tab[],int nb_lignes)
{
    printf("Nous trouvons %d lignes de donnees",nb_lignes);    //Nous avons deja une fonction realisant cette tache dans donnee.c
}

//--------------------------------------------------------------------------------------

//Cette fonction tri la tableau afin de trouver le pouls minimum et maximum du tableau
void Max_et_Min_pouls(structure tab[], int nb_lignes)
{
    tri_bulles_croissant_par_pouls(tab , nb_lignes);    //Tri des composantes pouls du tableau
    printf("Le minimun est %d et le maximum est %d", tab[0].pouls, tab[nb_lignes].pouls);   //Affichage des pouls de premier et dernier rang

}

//--------------------------------------------------------------------------------------


