#include "export_html.h"
 
//<link href="fichier.css" rel="stylesheet" type="test.css"/>
void enteteHtml(long int* positionInHTML, char* fich) {
  //printf("error");
  FILE* fichier;
  
  fichier = fopen(fich, "w");

  if(fichier != NULL) {
    
    char* textHTML;
    textHTML ="<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n\t<meta charset=\"utf-8\">\n\t<link rel=\"stylesheet\" href=\"style.css\">\n\t<title>EnteteHTML</title>\n</head>\n<body>\n\t<h1>Arbre Généalogique</h1>\n\n<div id=\"tablo\">";
   
    fprintf(fichier,"%s", textHTML);
  }
  else{
    printf("erreur de creation du fichier HTML");
  }
  *positionInHTML = ftell(fichier);
  fclose(fichier);
}

char* encapsulation(la_personne* personne,int colspan){
  char capsule[100] = "<td colspan=\"";
         //colspan\"";
  char* leColspan;
  if (colspan == 4){
    leColspan = "4";
  } else if(colspan == 2) {
    leColspan = "2";
  } else if (colspan == 1) {
    leColspan = "1";
  }
  //printf("\n%s\n",leColspan);
  strcat(capsule, leColspan);
  strcat(capsule, "\"><a href =\"");
  strcat(capsule, personne->nom);
  strcat(capsule, personne->prenom);
  strcat(capsule, ".html\">");
  strcat(capsule, personne->nom);
  strcat(capsule, " ");
  strcat(capsule, personne->prenom);
  strcat(capsule, "</a></td>");
  return capsule;
}

void titreHTMLPerson (la_personne* tableau[], long int* positionInHTML) {
  
  char* buffer;
  int truc;
  int id = 0;
  FILE* fichier;
  fichier = fopen("dossierHTML/index.html", "r+");
  fseek(fichier, *positionInHTML, SEEK_SET);
  fprintf(fichier, "\t<table>\n");
  for(int i = 0; i<3;i++){
    fprintf(fichier, "\t\t<tr>\n");
    truc=pow(2,i);
    for(int j= 0; j< truc;j++){
      buffer = encapsulation(tableau[id], 4/truc);
      fprintf(fichier, "\t\t\t%s\n", buffer);
      id++;
    }
    fprintf(fichier, "\t\t</tr>\n");
  }
  fprintf(fichier, "\t</table>\n");

  *positionInHTML = ftell(fichier);
  fclose(fichier);
  
}
void finHTML(long int* positionInHTML, char* fich){
  FILE* fichier;
  fichier = fopen(fich, "r+");
  fseek(fichier, *positionInHTML, SEEK_SET);
  fprintf(fichier,"</body>\n</html>");
}

void fichePath(la_personne* personne, long int* positionHTML) {

char *fich = (char*)malloc(sizeof(char)*TAILLE_MAX*2);
strcpy(fich,"dossierHTML/");
strcat(fich, personne->nom);
strcat(fich, personne->prenom);
strcat(fich, ".html");
//printf("%s",fich);

enteteHtml(positionHTML, fich);

FILE* fichier;
fichier = fopen(fich, "r+");
fseek(fichier, *positionHTML, SEEK_SET);

fprintf(fichier, "<h1>Nom : %s</h1>\n<h1>Prenom : %s</h1>\n<h2>Date de naissance : %s</h2>\n<h2>Lieu de naissance : %s</h2>\n", personne->nom, personne->prenom, personne->date, personne->region_naissance);

fprintf(fichier, "<h2>Pere : <a href =\"%s%s.html\"> %s %s</h2>\n</a><h2>Mere : <a href =\"%s%s.html\"> %s %s</a></h2>\n", personne->pere->nom,personne->pere->prenom,personne->pere->nom,personne->pere->prenom,personne->mere->nom,personne->mere->prenom,personne->mere->nom,personne->mere->prenom);

fprintf(fichier, "<h2>Grand-Pere-Paternel : <a href =\"%s%s.html\"> %s %s</h2>\n</a><h2>Grand-Mere-Paternel : <a href =\"%s%s.html\"> %s %s</a></h2>\n", personne->pere->pere->nom,personne->pere->pere->prenom,personne->pere->pere->nom,personne->pere->pere->prenom,personne->pere->mere->nom,personne->pere->mere->prenom,personne->pere->mere->nom,personne->pere->mere->prenom);

fprintf(fichier, "<h2>Grand-Pere-Maternel : <a href =\"%s%s.html\"> %s %s</h2>\n</a><h2>Grand-Mere-Maternel : <a href =\"%s%s.html\"> %s %s</a></h2>\n", personne->mere->pere->nom,personne->mere->pere->prenom,personne->mere->pere->nom,personne->mere->pere->prenom,personne->mere->mere->nom,personne->mere->mere->prenom,personne->mere->mere->nom,personne->mere->mere->prenom);

*positionHTML = ftell(fichier);
fclose(fichier);
finHTML(positionHTML, fich);
free(fich);
}

void afficheFratrie (la_fratrie* premierFrere, long int* positionInHTML) {
  
  //char* buffer;
  la_fratrie* fare;
  char* text = "dossierHTML/index.html";
  
  enteteHtml(positionInHTML, text);
  
  FILE* fichier;
  fichier = fopen(text, "r+");
  fseek(fichier, *positionInHTML, SEEK_SET);
  
  char* textHTML = "\t\t<li>";
  fare=premierFrere;
  fprintf(fichier,"\t<ul>\n");
  long int position;
  while(fare != NULL) {
    fprintf(fichier,"%s<a href =\"%s%s.html\">%s %s</a></li>\n",textHTML,fare->personne->nom,fare->personne->prenom,fare->personne->nom, fare->personne->prenom);
    
    fichePath(fare->personne, &position);
    fare=fare->frereSuivant;
  }
  fprintf(fichier,"\t</ul>\n");
  *positionInHTML = ftell(fichier);
  finHTML(positionInHTML, text);
  
}

void creationCSS () {
    
    FILE* fichier;
    fichier = fopen("dossierHTML/style.css", "w+");

    if(fichier != NULL) {
      fprintf(fichier, "body {\n\ttext-align:center;\n\tbackground-color:blue;\n}\n\ntable {\n\tborder: 2px solid black;\n}");
    } else {
      printf("Mauvaise ouverture du fichier ! CSS");
    }
}