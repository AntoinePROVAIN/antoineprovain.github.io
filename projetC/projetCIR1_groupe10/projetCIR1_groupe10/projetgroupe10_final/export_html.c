#include "export_html.h"
 
void enteteHtml(long int* positionInHTML, char* fich) {
  

  FILE* fichier;
  
//ouverture du fichier HTML ayant pour nom la chaine de caractere contenue dans fich
  fichier = fopen(fich, "w+");

//creation de son entete HTML
  if(fichier != NULL) {
    fprintf(fichier,"<!DOCTYPE html>\n<html lang=\"fr\">\n<head>\n\t<meta charset=\"utf-8\">\n\t<link rel=\"stylesheet\" href=\"style.css\">\n\t<title>EnteteHTML</title>\n</head>\n<body>\n\t<h1>Arbre Généalogique</h1>\n\n<div id=\"tablo\">\n");
  }
  else{
    printf("erreur de creation du fichier HTML");
  }
  *positionInHTML = ftell(fichier);
  fclose(fichier);
}

char* encapsulation(la_personne* personne,int colspan){

  //Creation d'une chaine de caractere
  char capsule[100] = "<td colspan=\"";

  char* leColspan;
  if (colspan == 4){
    leColspan = "4";
  } else if(colspan == 2) {
    leColspan = "2";
  } else if (colspan == 1) {
    leColspan = "1";
  }

  //Encapsulation du nom prenom de la personne dans des balises HTML <a> et <td>
  strcat(capsule, leColspan);
  strcat(capsule, "\"><a href =\"");
  strcat(capsule, personne->nom);
  strcat(capsule, personne->prenom);
  strcat(capsule, ".html\">");
  strcat(capsule, personne->nom);
  strcat(capsule, " ");
  strcat(capsule, personne->prenom);
  strcat(capsule, "</a></td>");

  //retour de la valeur de la capsule
  return capsule;
}

void afficheAncetre (la_personne* tabAncetre[]) {

  char* fich = "dossierHTML/index.html";
  long int positionInHTML;

  //appel de la fonction enteteHTML pour la creation de l'entete
  enteteHtml(&positionInHTML,fich);
  
  char* buffer;
  int nbpersonnegeneration;
  int id = 0;
  FILE* fichier;

  //ouverture du fichier fich en reprenant l'ecriture sans supprimer ce qui a été fait avant
  fichier = fopen(fich, "r+");
  
  fseek(fichier, positionInHTML, SEEK_SET);
  
  //Creation du tableau HTML avec pour chaque generation precedente 2 fois plus de case que celle qui la suit
  fprintf(fichier, "\t<table>\n");
  for(int i = 0; i<3;i++){
    fprintf(fichier, "\t\t<tr>\n");
    nbpersonnegeneration=pow(2,i);
    for(int j= 0; j< nbpersonnegeneration;j++){
      buffer = encapsulation(tabAncetre[id], 4/nbpersonnegeneration);
      fprintf(fichier, "\t\t\t%s\n", buffer);
      id++;
    }
    fprintf(fichier, "\t\t</tr>\n");
  }
  fprintf(fichier, "\t</table>\n");
  
  //actualisation de la variable positionInHTML
  positionInHTML = ftell(fichier);
  fclose(fichier);

  //Appel de la fonction finHTML pour créer la fin du fichier HTML
  finHTML(&positionInHTML, fich);
  
  //Creation de toutes les fiches HTML de chaque personne présent dans le fichier Ancetre
  for (int i=0;i<7;i++) {
    fichePath(tabAncetre[i], &positionInHTML);
  }
}

void finHTML(long int* positionInHTML, char* fich){
  FILE* fichier;

  //ouverture du fichier fich pour finition du code HTML
  fichier = fopen(fich, "r+");
  fseek(fichier, *positionInHTML, SEEK_SET);
  fprintf(fichier,"</div>\n</body>\n</html>");
}

void fichePath(la_personne* personne, long int* positionHTML) {

//allocation dyanmique de memoire pour utilisation de la fonction strcat
  char *fich = (char*)malloc(sizeof(char)*TAILLE_MAX*2);

  //Creation du nom du fichier HTML personnel par rapport au nom/ prenom de la personne
  strcpy(fich,"dossierHTML/");
  strcat(fich, personne->nom);
  strcat(fich, personne->prenom);
  strcat(fich, ".html");

//Creation de l'entete du fichier
  enteteHtml(positionHTML, fich);

  FILE* fichier;

  //ouverture du fichier fich et positionnement à la fin de l'ecriture de l'entete
  fichier = fopen(fich, "r+");
  fseek(fichier, *positionHTML, SEEK_SET);

//Remplissage du fichier HTML pour la personne
  fprintf(fichier, "<h1>Nom : %s</h1>\n<h1>Prenom : %s</h1>\n<h2>Date de naissance : %s</h2>\n<h2>Lieu de naissance : %s</h2>\n", personne->nom, personne->prenom, personne->date, personne->region_naissance);

//Remplissage du fichier pour les parents de la personne
  fprintf(fichier, "<h2>Pere : <a href =\"%s%s.html\"> %s %s</h2>\n</a><h2>Mere : <a href =\"%s%s.html\"> %s %s</a></h2>\n", personne->pere->nom,personne->pere->prenom,personne->pere->nom,personne->pere->prenom,personne->mere->nom,personne->mere->prenom,personne->mere->nom,personne->mere->prenom);

//Remplissage du fichier pour les Grands parents paternels de la personne
  fprintf(fichier, "<h2>Grand-Pere-Paternel : <a href =\"%s%s.html\"> %s %s</h2>\n</a><h2>Grand-Mere-Paternel : <a href =\"%s%s.html\"> %s %s</a></h2>\n", personne->pere->pere->nom,personne->pere->pere->prenom,personne->pere->pere->nom,personne->pere->pere->prenom,personne->pere->mere->nom,personne->pere->mere->prenom,personne->pere->mere->nom,personne->pere->mere->prenom);

//REmplissage du fichier pour les Grands Parents Maternels de la personne
  fprintf(fichier, "<h2>Grand-Pere-Maternel : <a href =\"%s%s.html\"> %s %s</h2>\n</a><h2>Grand-Mere-Maternel : <a href =\"%s%s.html\"> %s %s</a></h2>\n", personne->mere->pere->nom,personne->mere->pere->prenom,personne->mere->pere->nom,personne->mere->pere->prenom,personne->mere->mere->nom,personne->mere->mere->prenom,personne->mere->mere->nom,personne->mere->mere->prenom);

//Actualisation de positionHTML
  *positionHTML = ftell(fichier);
  fclose(fichier);

//finition du code HTML
  finHTML(positionHTML, fich);

  //Liberation memoire de fich
  free(fich);
}

void afficheFratrie (la_fratrie* premierFrere, long int* positionInHTML) {
  
  //char* buffer;
  la_fratrie* fare;
  char* text = "dossierHTML/index.html";

  //Creation de l'entete HTML
  enteteHtml(positionInHTML, text);
  
  FILE* fichier;

  //ouverture du fichier fich et positionnement à la fin de l'ecriture de l'entete
  fichier = fopen(text, "r+");
  fseek(fichier, *positionInHTML, SEEK_SET);
  
  char* textHTML = "\t\t<li>";

  //fare initialiser a premierFrere
  fare=premierFrere;
  fprintf(fichier,"\t<ul id=\"a\">\n");
  long int position;

  //Tant que le pointeur fare n'est pas arrivé au bout de la chaine de caractere
  while(fare != NULL) {

    //affichage de la fratrie dans des balises <a> et <li>
    fprintf(fichier,"%s<a href =\"%s%s.html\">%s %s</a></li>\n",textHTML,fare->personne->nom,fare->personne->prenom,fare->personne->nom, fare->personne->prenom);
    
    //Creation des fiches personnelles HTML des memebres de la fratrie
    fichePath(fare->personne, &position);

    //fare initialiser a la valeur de frereSuivant
    fare=fare->frereSuivant;
  }
  fprintf(fichier,"\t</ul>\n");
  *positionInHTML = ftell(fichier);

  //Fin du HTML
  finHTML(positionInHTML, text);
  
}

void creationCSS () {
    
    FILE* fichier;

    //Creation d'un nouveau fichier pour le style en css
    fichier = fopen("dossierHTML/style.css", "w+");

//si le fichier a pu se creer
    if(fichier != NULL) {

      //Creation du style en css du body
      fprintf(fichier, "body {\n\ttext-align : center;\n\tborder : 0;\n\tbackground-color:#F5F5DC;\n\tmargin : 0;\n\twidth : 100%c;\n}\n\n",'%');

      //Creation du style en css du tablo et table
      fprintf(fichier, "\n\n#tablo {\n\tmargin-top : 10%c;\n\tmargin-right : 5%c;\n\tmargin-left : 5%c;\n}\n\ntable {\n\tfont-weight : bold;\n\tfont-family : arial, sans-serif;\n\tborder-collapse : collapse;\n\twidth : 100%c;\n\tcolor : brown;\n\tborder: 2px solid black;\n\n}", '%', '%', '%', '%');

      //Creation du style en css du td, h1
      fprintf(fichier, "\n\ntd {\n\tborder : 2px solid rgb(22, 13, 13);\n\tpadding : 12px;\n}\n\nh1 {\n\tfont-size : 4em;\n\ttext-decoration: underline;\n\tcolor : #315e6b;\n\twidth : 100%c;\n}\n", '%');

      //Creation du style en css du a (id de ul) et li
      fprintf(fichier, "\n#a {\n\tfont-size : 2em;\n\ttext-align : left;\n\tmargin-left : 20%c;\n}\n\nli {\n\tmargin-top: 3%c;\n\tcolor : brown;\n}\n\n", '%', '%');
    } else {
      printf("Mauvaise ouverture du fichier ! CSS");
    }
}