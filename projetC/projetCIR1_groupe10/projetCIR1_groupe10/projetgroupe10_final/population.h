#ifndef CODE_POPULATION_H
#define CODE_POPULATION_H

//inclusion de la bibliothéque contenant tous les includes
#include "biblio.h"

#define TAILLE_MAX 25

// Struct personne definit la_personne
typedef struct Personne {                   
  
    //identifiant de la personne, du pere, de la mere
    int id_person, id_pere, id_mere;
    //nom de la personne;
    char nom[TAILLE_MAX];
    //prenom de la personne;
    char prenom[TAILLE_MAX];
    //date de naissance de la personne;
    char date[TAILLE_MAX];
    //char* region_naissance;
    char region_naissance[TAILLE_MAX];
    // pointeur vers pere
    struct Personne* pere;
    //pointeur vers mere
    struct Personne* mere;
}la_personne;

//Relie les enfants a leur parents grace a des pointeurs
void linkPopulation (la_personne* tab[], int taille);

#endif //CODE_POPULATION_H
 