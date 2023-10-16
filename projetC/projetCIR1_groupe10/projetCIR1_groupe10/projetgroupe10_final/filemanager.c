
#include "filemanager.h"

// la fonction de lecture du csv
la_personne* read_CSV(la_personne* inconu,long int* positionInCSV,char* fich){
  //on ouvre le fichier ayant pour nom la chaine de caractere contenue dans fiche
  FILE *fichier;
  fichier = fopen(fich, "r");
  la_personne* personne =(la_personne*)malloc(sizeof(la_personne));
  // On verifie si le fichier a bien ete ouvert
  if (fichier == NULL){
    printf ("Fichier non trouvé");
  }
  else{
    //on commence la lecture du fichier a partir de la position "positionInCSV"
    fseek(fichier,*positionInCSV,SEEK_SET);
    //on affecte a personne les informations lu pour une personne
    fscanf(fichier,"%d,%d,%d,%[^,],%[^,],%[^,],%[^\n]",&personne->id_person,&personne->id_pere,&personne->id_mere,personne->nom,personne->prenom,personne->date,personne->region_naissance);
    //les pointeur pere et mere pointe initialement sur l'inconu
    if (inconu==NULL){
      personne->mere = personne;
      personne->pere = personne;
    }else {
      personne->mere = inconu;
      personne->pere = inconu;
    }
    //on actualise "positionInCSV"
    *positionInCSV = ftell(fichier);
    
  }
  // on ferme le fichier
  fclose(fichier);

  return personne;
}