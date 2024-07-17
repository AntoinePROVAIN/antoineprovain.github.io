#ifndef FILE_ADVANCED_H
#define FILE_ADVANCED_H

#include "biblio.h"
#include "population.h"
#include "filemanager.h"

// structure Fratrie definie par la_fratrie
typedef struct Fratrie {
  //pointeur sur FrereSuivant
  struct Fratrie* frereSuivant;
  //Pointeur sur FrerePrecedent
  struct Fratrie* frerePrecedent;
  //pointeur sur les donnees de la personne
  la_personne* personne;
}la_fratrie;


//fonction qui recherche les ancetres et les mets dans un tableau appelé tabAncetre
void ancetreTab(la_personne* tab[],la_personne* tabAncetre[],int taille);

//relie les freres/soeurs dans une liste chainée
la_fratrie* creationDeLaListeDeLaFratrie(la_fratrie* frerePrecedent,la_fratrie* dernierFrere ,la_personne* frere);

//fonction qui recherche les freres/soeurs
la_fratrie* fratrie(la_personne* tab[], int taille);

// libere la memoire alouee pour le tableau de personne
void libereTab(la_personne* tab[], int taille);

// libere la memoire alouee pour la fratrie
void libereFratri(la_fratrie* fratrie);


#endif