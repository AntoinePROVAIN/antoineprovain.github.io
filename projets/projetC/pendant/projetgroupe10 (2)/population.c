
#include "population.h"

/*void insert(la_personne* tab[]) {

  long int positionInCSV = 0;

  for(int i = 0; i< 41; i++) {
      tab[i] = read_CSV(tab[0], &positionInCSV);
      printf("%d %d %d %s %s %s %s\n", tab[i]->id_person,tab[i]->id_pere,tab[i]->id_mere,tab[i]->nom,tab[i]->prenom,tab[i]->date,tab[i]->region_naissance);
  }

}*/

void linkPopulation (la_personne* tab[], int taille) {
for(int i = 0; i < taille; i++) {
  tab[i]->pere = tab[tab[i]->id_pere];
  tab[i]->mere = tab[tab[i]->id_mere];
  
  /*printf("%d ",tab[i]->id_person);
  printf("%d ",tab[i]->id_pere);
  printf("%d ",tab[i]->id_mere);
  printf("%s ",tab[i]->nom);
  printf("%s ",tab[i]->prenom);
  printf("%s ",tab[i]->date);
  printf("%s \n",tab[i]->region_naissance);
  printf("Les adresses : %p ",&tab[i]);
  printf("%p ",tab[i]->pere);
  printf("%p \n\n",tab[i]->mere);*/
  }
}
