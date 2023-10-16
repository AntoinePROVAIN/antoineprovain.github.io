#ifndef CODE_EXPORT_H
#define CODE_EXPORT_H

#include "biblio.h"
#include "population.h"
#include "advanced.h"

//Creation de l'entete pour les fichiers HTML
void enteteHtml(long int* positionInHTML, char* fich);

//encapsule le nom et prenom d'une personne dans une balise HTML
char* encapsulation(la_personne* personne,int colspan);

//Sert a créer tous les fichiers HTML lié aux ancetres
void afficheAncetre (la_personne* tableau[]);

//Creation de la fin du fichier HTML
void finHTML(long int* positionInHTML, char* fich);

//Creation des fiches HTML des personnes
void fichePath(la_personne* personne, long int* positionHTML);

//Sert a créer tous les fichiers HTML lié aux freres/soeurs
void afficheFratrie (la_fratrie* premierFrere, long int* positionInHTML);

//Creation de la feuille de style du HTML
void creationCSS ();


#endif 
