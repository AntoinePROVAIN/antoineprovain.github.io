
# **Notice d'utilisation de notre arbre généalogique**

## Sommaire

1. Explication du menu
2. Liste des fichiers et installation
3. Procédure d'utilisation du programme
4. Différentes fonctionnalités
5. Ce qui ne fonctionne pas

### 1. Explication du menu

Notre menu est composé de 6 parties qui sont : 

- Notice
- Choix du fichier
- Ancêtres
- Fratrie
- Purge du dossierHTML
- Quitter

Si vous décidez d'aller dans **Notice**, vous pourrez trouvez toutes les annotations qui vont permettre le bon déroulement du site. Par exemple, il vous est précisé que les accents sont retirés car ils peuvent perturber le fonctionnement du programme.    

Dans un second temps, si votre choix se porte vers le **Choix du fichier**, le programme va alors vous demandez si vous voulez travailler dans une liste de 40 personnes ou alors de 200 personnes. Cela influera ensuite sur le reste du programme, quand au nombre de frère(s)/soeur(s) et des ancêtre(s).
   
Dans la troisième partie, la fonction principale consiste à chercher vos ancêtres parmi la liste précédement choisi dans **Choix du fichier**, et vous l'affiche dans un tableau sous format "index.html". C'est-à-dire qu'il faut ensuite mettre ce lien dans la barre de recherche de votre choix afin de pouvoir afficher vos ancêtres. 

Si vous décidez de choisir **Fratrie**, même fonctionnement que pour la partie précédente, cependant, dans la liste choisie, se seront les frères et soeurs qui seront recherchés. Même procédure pour la suite à une exception près : les frères et soeurs sont affichés sous forme de liste et non de tableau. 

Dans la partie **Purge du dossierHTML**, le but est de supprimer toutes les pages HTML qui ont été créés lors de l'appel à la fonction "Ancêtre" ou "Fratrie". 

Pour finir, si votre choix se tourne vers **Quitter**, vous sortirez automatiquement du programme.  

### 2. Liste des fichiers et installations

Dans un premier temps, voici la liste de tous les fichiers : 

- main.c
- 200.csv
- 40.csv
- advanced.c
- advanced.h
- biblio.h
- export_html.c
- export_html.h
- filemanager.c
- filemanager.h
- population.c
- population.h

Pour la procédure d'installation, sous un environnement ***UNIX***, il faut que vous téléchargiez tout le dossier zip et que vous extrayez tout le fichier. Ensuite, vous n'avez qu'à remettre tous ces fichiers dans votre environnement UNIX et accèder à votre dossier. Executer ensuite. (Plus d'explication dans sur l'execution dans la partie suivante).

Dans d'autre cas, téléchargez le dossier et extrayez tous les fichiers. Remettez les fichiers dans le logiciel afin de pouvoir lancer la compilation/ execution. 

### 3. Procédure d'utilisation du programme

La procédure d'utilisation de notre programme va dépendre de quel **environnement numérique** vous utilisez. Par exemple, les commandes d'execution ne seront pas les mêmes pour un environnement UNIX ou MAC. 

Dans le cas où vous disposer de la fonction RUN, si vous le pouvez, vous n'aurez qu'à appuyer sur le bouton ***RUN*** pour faire compiler/ executer le programme.

Dans le cas d'un environnement **UNIX**, la commande pour compiler le propramme est : 

- *gcc -pthread -o main advanced.c export_html.c filemanager.c main.c population.c -lm*

Ensuite, pour l'execution, il faut rentrer :

- *./main*

### 4. Différentes fonctionnnalités

Comparer aux fonctions demandées, nos fonctions ***Fratrie*** et ***Ancetres***, une fois compilées, trouvent et créées dans un même temps tout l'index.html qui va avec les informations voulues.

Nous avons tenter de rajouter une fonction qui permettrait d'effacer toutes les pages HTML une fois que celles ci ne nous servent plus. Cependant, comme expliquer dans la partie suivante, cette fonction n'est pas au point.

### 5. Ce qui ne fonctionne pas

Dans les fonctionnalités en plus, nous avons voulu créer un fichier qui allait contenir tous les pages HTML créées pour pouvoir les effacer une fois que nous n'en n'avions plus besoin. Pour cela, nous avons fait appel aux fonctions de ***mkdir*** et ***rmdir*** pour créer et supprimer ce dossier. Cependant, la fonction rmdir ne marche pas réellement, car il faudrait supprimer d'abord tous les fichiers contenues avant de pouvoir supprimer le dossier.