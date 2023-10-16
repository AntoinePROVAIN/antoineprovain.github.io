#include "biblio.h"
#include "advanced.h"
#include "population.h"

void ancetre(la_personne* tab[],la_personne* tabAncetre[],int taille){
  printf("\nAncetre, sur deux génerations, de (id de la personne) > ");
  int id;
  scanf("%d",&id);
  if(id < 0 ) {
      printf("\nLe nombre est négatif, /!\\ ATTENTION /!\\ \n");
      id = id*(-1);
      printf("Le nouveau nombre est : %d\n", id);
  }
  if(id > taille) {
      printf("\nLe nombre est trop grand, /!\\ ATTENTION /!\\ \n");
      id = id%taille;
      printf("Le nouveau nombre est : %d\n", id);
  }

  printf("\n");
  tabAncetre[0]=tab[id];
  tabAncetre[1]=tabAncetre[0]->pere;
  tabAncetre[2]=tabAncetre[0]->mere;
  tabAncetre[3]=tabAncetre[1]->pere;
  tabAncetre[4]=tabAncetre[1]->mere;
  tabAncetre[5]=tabAncetre[2]->pere;
  tabAncetre[6]=tabAncetre[2]->mere;

  /*for(int i = 0; i< 7; i++) {  
    printf("%d %d %d %s %s %s %s\n", tabAncetre[i]->id_person,tabAncetre[i]->id_pere,tabAncetre[i]->id_mere,tabAncetre[i]->nom,tabAncetre[i]->prenom,tabAncetre[i]->date,tabAncetre[i]->region_naissance);
  }*/
}
la_fratrie* creationDeLaListeDeLaFratrie(la_fratrie* frerePrecedent,la_fratrie* dernierFrere ,la_personne* frere){

  la_fratrie* fratri= (la_fratrie*)malloc(sizeof(la_fratrie));
  fratri->personne=frere;
  fratri->frereSuivant=dernierFrere->frereSuivant;
  dernierFrere->frereSuivant=fratri;
  fratri->frerePrecedent=dernierFrere;
  
  return fratri;
}


la_fratrie* fratrie(la_personne* tab[],int taille,int* tailleFratrie){
  printf("\nFratrie de (mettre son ID) > ");
  int id;
  scanf("%d",&id);
  printf("\n");
  la_fratrie* premierFrere = (la_fratrie*)malloc(sizeof(la_fratrie));
  premierFrere->frereSuivant=NULL;
  premierFrere->frerePrecedent=NULL;
  la_fratrie* fare;
  fare=premierFrere;
   for (int i=1;i<= taille; i++){
    if (tab[id]->id_pere == tab[i]->id_pere && tab[id]->id_mere == tab[i]->id_mere) {
      if (*tailleFratrie==0){
        premierFrere->personne=tab[i];
        *tailleFratrie+=1;
        //printf("%s %s\n",fare->personne->nom, fare->personne->prenom);
      }else{
        fare=creationDeLaListeDeLaFratrie(premierFrere,fare, tab[i]);
        //printf("%s\n", premierFrere->personne->prenom);
        
        *tailleFratrie+=1;
      }
      //printf("%s  %p\n",fare->personne->prenom,fare->frereSuivant);
    }
   // printf("%s\n",premierFrere->personne->nom);
    /*do{
      printf("%s %s\n",fare->personne->nom,fare->personne->prenom);
      fare=fare->frereSuivant;
    }while(fare!=NULL);*/
  }
  return premierFrere;

}

void libereTab(la_personne* tab[], int taille){
  for(int i = 0;i<taille;i++){
    free(tab[i]);
  }
}
void libereFratri(la_fratrie* fratrie){
  while(fratrie!=NULL){
    if(fratrie->frereSuivant != NULL){
      fratrie=fratrie->frereSuivant;
      free(fratrie->frerePrecedent);
    }else{
      free(fratrie);
    }
  }
}