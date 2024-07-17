
#include "population.h"
#include "biblio.h"
#include "filemanager.h"
#include "advanced.h"
#include "export_html.h"

int main() {
  // MENU


  int tailleTab= TAB_MAX40;
  char* fichCSV= "40.csv";
  la_personne* tab200[TAB_MAX200]= {0};
  la_personne* tab40[TAB_MAX40]= {0};
  la_personne* tabAncetre[7];             //2^3-1
  la_personne** tab = tab40;
  int choix=0;
  int choixFichier=0;
  mkdir("dossierHTML",0666);

  while(true){
    printf("\n\n~~~~~~~~~~~MENU~~~~~~~~~~~\n");
    printf("\t1) Notice\n");
    printf("\t2) Choix du fichier\n");
    printf("\t3) Ancetre\n");
    printf("\t4) Fratrie\n");
    printf("\t5) Purge du dossierHTML (SOON)\n");
    printf("\t6) Quitter\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    
    do {
      printf("\tVotre choix > ");
      scanf("%d",&choix);

      if (choix > 6 || choix < 0){
        choix = 0;
      }
    } while(choix==0);


    long int positionInCSV = 0;
    for(int i = 0; i< tailleTab; i++) {  
      tab[i] = read_CSV(tab[0], &positionInCSV, fichCSV);
    }   
    linkPopulation(tab, tailleTab);


    switch (choix){
      case 1 :
            // printf("Quel est le meilleur code ??");
            // char* reponce=(char*)malloc(sizeof(char)*50) ;
            // scanf("%s",reponce);
            // if (strcmp(reponce,"^[[A^[[A^[[B^[[B^[[D^[[C^[[D^[[Cba")== 0 ||strcmp(reponce,"^[[A^[[A^[[B^[[B^[[D^[[C^[[D^[[CBA")== 0){
            //   printf("\nUn classique, non??\n");
            // }printf("\nNON!!\n");
            break;
      case 2 :
            printf("\nQuel fichier choississez vous ?\n\n\t1) Fichier 40.csv\n\t2) Fichier 200.csv\n\n\tVotre choix de fichier > ");
            scanf("%d", &choixFichier);
            choixFichier=choixFichier%2;
            if(choixFichier == 1) {
              fichCSV= "40.csv";
              tab = tab40;
              tailleTab = TAB_MAX40;
            } else {
              fichCSV= "200.csv";
              tab = tab200;
              tailleTab = TAB_MAX200;
            }
            
            break;
            
      case 3 :
            printf("");
                           // sert à pouvoir initialiser la personne dans le case 3
            long int position;               
            
            ancetre(tab, tabAncetre, tailleTab);

            char* fich = "dossierHTML/index.html";
            long int positionInHTML;
            enteteHtml(&positionInHTML,fich);
            titreHTMLPerson(tabAncetre, &positionInHTML);
            finHTML(&positionInHTML, fich);
            
            for (int i=0;i<7;i++) {
              fichePath(tabAncetre[i], &position);
            }
            //creationCSS();    
            libereTab(tab, tailleTab);
            printf("Fin du programe");
            return 0;
      case 4 :
            printf("");
            
            int compteur = 0;
            la_fratrie* premierFrere = fratrie(tab, tailleTab, &compteur);
            afficheFratrie(premierFrere, &positionInHTML);

            
            libereTab(tab, tailleTab);
            free(premierFrere);
            creationCSS();
            
            printf("Fin du programe");
            return 0;

      case 5 : 
            printf("\nC'EST EN DEVELOPPEMENT DONC IL NE VA RIEN SE PASSER.\n");
            printf("Nous vous conseillons de purger vous meme le dossierHTML en supprimant son contenu ou en le supprimant directement, un nouveau dossierHTML sera cree au lancement du programme.\n");
            // rmdir("dossierHTML");
            // mkdir("dossierHTML",0666);
            
            break;

      case 6 :
            libereTab(tab, tailleTab);
            printf("Fin du programe"); 
            return 0;
    }
  }
  
  return 0;
}
