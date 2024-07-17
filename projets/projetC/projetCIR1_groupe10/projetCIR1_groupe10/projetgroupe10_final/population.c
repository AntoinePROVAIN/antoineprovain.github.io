
#include "population.h"


void linkPopulation (la_personne* tab[], int taille) {
  
//boucle parcourant le tableau de personne pour relier les enfants a leur parents (via les pointeurs)
  for(int i = 0; i < taille; i++) { 
    tab[i]->pere = tab[tab[i]->id_pere];
    tab[i]->mere = tab[tab[i]->id_mere];

  }
}
