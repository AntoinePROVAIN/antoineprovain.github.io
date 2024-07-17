#ifndef CODE_POPULATION_H
#define CODE_POPULATION_H

#include "biblio.h"

#define TAILLE_MAX 25

typedef struct Personne {
    int id_person, id_pere, id_mere;        // identifiant de la personne, du pere, de la mere
    char nom[TAILLE_MAX];                   //char* nom;
    char prenom[TAILLE_MAX];                //char* prenom;
    char date[TAILLE_MAX];                  //int j, m, a;
    char region_naissance[TAILLE_MAX];      //char* region_naissance;
    struct Personne* pere;                  // pointeur vers pere
    struct Personne* mere;                  //pointeur vers mere
}la_personne;

void insert(la_personne* tab);

void affiche();

void linkPopulation (la_personne* tab[], int taille);

#endif //CODE_POPULATION_H
 