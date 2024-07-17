
#include "population.h"
#include "biblio.h"
#include "filemanager.h"
#include "advanced.h"
#include "export_html.h"


//la fonction principale

int main() {
    //On declare une chaine de caractere qui va nous servir pour
    //preciser quels fichiers csv ouvrir, le fichier de base est le 40.csv.
    char* fichCSV= "40.csv";
    //On declare des tableaux de structure Personne initialiser a 0
    //et de taille 200, 40 et 10 000.
    la_personne* tab200[TAB_MAX200]= {0};
    la_personne* tab40[TAB_MAX40]= {0};
    la_personne* tab10000[TAB_MAX10000]= {0};
    //On declare ensuite un entier "tailleTab" qui servira pour des boucles for
    //pour le remplissage de tableau precedement cree, par defaut il est egale a TAB_MAX40.
    int tailleTab= TAB_MAX40;
    //On cree une variable pour pouvoir agir sur un des tableaux precedement cree
    //et qui pointe sur le tableau de 40 par defaut.
    la_personne** tab = tab40;
    //On initialise a 0 des entiers qui stockeront les choix prient par l'utilisateur
    int choix=0;
    int choixFichier=0;
    //On cree un dossier qui va stocker tous les fichier qui seront crees par le programme
    mkdir("dossierHTML", 0666);
    //Le reste du programme est dans une boucle qui ne se finira que quand les fichiers seront crees
    //ou que l'utilisateur decide de quitter (dans le menu)
    while(true){
        //aspect graphique
        printf("\n\n~~~~~~~~~~~MENU~~~~~~~~~~~\n");
        printf("\t1) Notice\n");
        printf("\t2) Choix du fichier\n");
        printf("\t3) Ancetre\n");
        printf("\t4) Fratrie\n");
        printf("\t5) Purge du dossierHTML (SOON)\n");
        printf("\t6) Quitter\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        //choix de l'utilisateur par rapport au menu.
        do {
            printf("\tVotre choix (numero) > ");
            scanf("%d",&choix);
            // avec ça, l'utilisateur ne peut que choisir parmi ce qui lui est propose
            if (choix > 6 || choix < 0){
                choix = 0;
            }
        } while(choix==0);

        //On initialise un entier qui va permettre de sauvegarder la position de lecture dans le csv
        long int positionInCSV = 0;
        //On remplit le tableau avec la fonction read_CSV ecrie dans le fichier filemanager
        for(int i = 0; i< tailleTab; i++) {
            tab[i] = read_CSV(tab[0], &positionInCSV, fichCSV);
        }

        linkPopulation(tab, tailleTab);


        switch (choix){
            case 1 :
                printf("\n\n~~~~~~~~~~~NOTICE~~~~~~~~~~~\n\n");
                printf("INFORMATION GENERALE\n\n");
                printf("\tPour eviter des problemme d'affichage, les accent ont ete retirer.\n");
                printf("\tSi vous avez des problemes avec le dossierHTML, il est recommander de le supprimer et de le recreer manuellement.\n\n");
                break;

            case 2 :
                do {
                    printf("\nQuel fichier choississez vous ?\n\n\t1) Fichier 40.csv\n\t2) Fichier 200.csv\n\t3) Fichier 10000.csv\n\n\tVotre choix de fichier > ");
                    scanf("%d", &choixFichier);
                    if (choixFichier > 3 || choixFichier < 0){
                        choixFichier = 0;
                    }
                } while(choixFichier==0);
                switch(choixFichier){
                    case 1 :
                        libereTab(tab, tailleTab);
                        fichCSV= "40.csv";
                        tab = tab40;
                        tailleTab = TAB_MAX40;
                        break;
                    case 2 :
                        libereTab(tab, tailleTab);
                        fichCSV= "200.csv";
                        tab = tab200;
                        tailleTab = TAB_MAX200;
                        break;
                    case 3 :
                        libereTab(tab, tailleTab);
                        fichCSV= "10000.csv";
                        tab = tab10000;
                        tailleTab = TAB_MAX10000;
                        break;
                }
                break;

            case 3 :
                printf("");
                la_personne* tabAncetre[7];
                ancetreTab(tab, tabAncetre, tailleTab);
                afficheAncetre(tabAncetre);

                libereTab(tab, tailleTab);

                creationCSS();
                printf("Fin du programme\n");
                return 0;

            case 4 :
                printf("");
                la_fratrie* premierFrere = fratrie(tab, tailleTab);
                long int positionInHTML=0;
                afficheFratrie(premierFrere, &positionInHTML);

                libereTab(tab, tailleTab);
                free(premierFrere);

                creationCSS();
                printf("Fin du programe\n");
                return 0;

            case 5 :
                printf("\nC'EST EN DEVELOPPEMENT DONC IL NE VA RIEN SE PASSER.\n");
                printf("Nous vous conseillons de purger vous meme le dossierHTML en supprimant son contenu ou en le supprimant directement, un nouveau dossierHTML sera cree au lancement du programme.\n");
                // rmdir("dossierHTML");
                // mkdir("dossierHTML",0666);

                break;

            case 6 :
                libereTab(tab, tailleTab);
                printf("Fin du programe\n");
                return 0;
        }
    }

    return 0;
}
