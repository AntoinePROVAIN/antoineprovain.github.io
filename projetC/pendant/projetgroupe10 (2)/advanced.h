#ifndef FILE_ADVANCED_H
#define FILE_ADVANCED_H

#include "biblio.h"
#include "population.h"
#include "filemanager.h"

typedef struct Fratrie {
  struct Fratrie* frereSuivant;
  struct Fratrie* frerePrecedent;
  la_personne* personne;
}la_fratrie;

void ancetre(la_personne* tab[],la_personne* tabAncetre[],int taille);
la_fratrie* fratrie(la_personne* tab[], int taille, int* tailleFratrie);
void libereTab(la_personne* tab[], int taille);
void libereFratri(la_fratrie* fratrie);
la_fratrie* creationDeLaListeDeLaFratrie(la_fratrie* frerePrecedent,la_fratrie* dernierFrere ,la_personne* frere);

#endif