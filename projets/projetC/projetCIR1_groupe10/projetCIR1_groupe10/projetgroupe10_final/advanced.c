#include "advanced.h"


void ancetreTab(la_personne* tab[],la_personne* tabAncetre[],int taille){
  
  //Demande l'id de la personne rechercher
  printf("\nAncetre, sur deux génerations, de (id de la personne) > ");
  int id;
  
  //Recupere la saisie de l'utilateur
  scanf("%d",&id);
  //Cas particulier : id rentrée inferieur a 0
  if(id < 0 ) {
      printf("\nLe nombre est négatif, /!\\ ATTENTION /!\\ \n");
      id = id*(-1);
      printf("Le nouveau nombre est : %d\n", id);
  }
  //Cas particulier : id rentré est superieur a l'ID max ==> rectification de l'ID par le modulo de la taille
  if(id > taille) {
      printf("\nLe nombre est trop grand, /!\\ ATTENTION /!\\ \n");
      id = id%taille;
      printf("Le nouveau nombre est : %d\n", id);
  }

  printf("\n");
  //Remplissage du tableau tabAncetres
  tabAncetre[0]=tab[id];
  tabAncetre[1]=tabAncetre[0]->pere;
  tabAncetre[2]=tabAncetre[0]->mere;
  tabAncetre[3]=tabAncetre[1]->pere;
  tabAncetre[4]=tabAncetre[1]->mere;
  tabAncetre[5]=tabAncetre[2]->pere;
  tabAncetre[6]=tabAncetre[2]->mere;
}

la_fratrie* creationDeLaListeDeLaFratrie(la_fratrie* frerePrecedent,la_fratrie* dernierFrere ,la_personne* frere){

//allocation dynamique de la_fratrie pour utilisation en dehors de la fonction
  la_fratrie* fratri= (la_fratrie*)malloc(sizeof(la_fratrie));

  //Lien entre les freres/soeurs
  fratri->personne=frere;
  fratri->frereSuivant=dernierFrere->frereSuivant;
  dernierFrere->frereSuivant=fratri;
  fratri->frerePrecedent=dernierFrere;
  
  //retour de la valeur de fratri
  return fratri;
}


la_fratrie* fratrie(la_personne* tab[],int taille){
  //demande l'ID de la personne
  printf("\nFratrie de (mettre son ID) > ");
  int id;
  //Recupere la saisie de l'utilisateur
  scanf("%d",&id);
  //Cas particulier : id rentrée inferieur a 0
  if(id < 0 ) {
      printf("\nLe nombre est négatif, /!\\ ATTENTION /!\\ \n");
      id = id*(-1);
      printf("Le nouveau nombre est : %d\n", id);
  }
  //Cas particulier : id rentré est superieur a l'ID max ==> rectification de l'ID par le modulo de la taille
  if(id > taille) {
      printf("\nLe nombre est trop grand, /!\\ ATTENTION /!\\ \n");
      id = id%taille;
      printf("Le nouveau nombre est : %d\n", id);
  }
  printf("\n");
  int tailleFratrie;
  
  //allocation dynamique du premierFrere pour utilisation en dehors de la fonction
  la_fratrie* premierFrere = (la_fratrie*)malloc(sizeof(la_fratrie));
  
  //initialisation des pointeurs frereSuiant et FrerePrecedent
  premierFrere->frereSuivant=NULL;
  premierFrere->frerePrecedent=NULL;

  //Creation d'un pointeur qui va se deplacer sur la liste chainée
  la_fratrie* fare;

  //initialisation de fare sur premierFrere
  fare=premierFrere;

  //Creation de la liste chainée de la fratrie par rapport au tableau sorti du CSV
   for (int i=1;i<= taille; i++){
     //Si la personne a les memes parents que la personne ayant l'ID rentré précedement
    if (tab[id]->id_pere == tab[i]->id_pere && tab[id]->id_mere == tab[i]->id_mere) {
      //Si la fratrie n'a pas commencé a etre initialisé, initialiser premierFrere en debut de la Fratrie
      if (tailleFratrie==0){
        premierFrere->personne=tab[i];
        tailleFratrie+=1;
      // Sinon rajouter le frere en derniere position  
      }else{
        fare=creationDeLaListeDeLaFratrie(premierFrere,fare, tab[i]);
        tailleFratrie+=1;
      }
    }
   
  }

  //retour de la valeur de premierFrere
  return premierFrere;
}

void libereTab(la_personne* tab[], int taille){

  //Libere la memoire en parcourant chaque personne du tableau
  for(int i = 0;i<taille;i++){
    free(tab[i]);
  }
}
void libereFratri(la_fratrie* fratrie){

  //Libere la memoire en parcourant chaque personne de la liste chainée
  while(fratrie!=NULL){
    if(fratrie->frereSuivant != NULL){
      fratrie=fratrie->frereSuivant;
      free(fratrie->frerePrecedent);
    }else{
      free(fratrie);
    }
  }
}