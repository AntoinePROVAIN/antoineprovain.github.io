#ifndef CODE_EXPORT_H
#define CODE_EXPORT_H

#include "biblio.h"
#include "population.h"
#include "advanced.h"

void enteteHtml(long int* positionInHTML, char* fich);
char* encapsulation(la_personne* personne,int colspan);
void titreHTMLPerson (la_personne* tableau[], long int* positionInHTML);
void finHTML(long int* positionInHTML, char* fich);
void fichePath(la_personne* personne, long int* positionHTML);
void afficheFratrie (la_fratrie* premierFrere, long int* positionInHTML);
void creationCSS ();


#endif 
