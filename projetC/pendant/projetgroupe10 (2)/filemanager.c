
#include "filemanager.h"


la_personne* read_CSV(la_personne* inconu,long int* positionInCSV,char* fich){
  FILE *fichier;
  fichier = fopen(fich, "r");
  la_personne* personne =(la_personne*)malloc(sizeof(la_personne));
  if (fichier == NULL){
    printf ("Fichier non trouvé");
  }
  else{
    fseek(fichier,*positionInCSV,SEEK_SET);
    fscanf(fichier,"%d,%d,%d,%[^,],%[^,],%[^,],%[^\n]",&personne->id_person,&personne->id_pere,&personne->id_mere,personne->nom,personne->prenom,personne->date,personne->region_naissance);
    if (inconu==NULL){
      personne->mere = personne;
      personne->pere = personne;
    }else {
      personne->mere = inconu;
      personne->pere = inconu;
    }
    *positionInCSV = ftell(fichier);
    
  }
  fclose(fichier);

  return personne;
}