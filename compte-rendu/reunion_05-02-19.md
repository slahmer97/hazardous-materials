# Première partie

## Choix du jeu

> Après une synthèse des votes sur Discord accumulé pendant la semaine que voici :

| Jeu | Voix |
--|--
Clank (plateau) | 1
Zombicide (plateau) | 1
Munchkin (carte) | 2
Love Letter (carte) | 1
Gozu (carte) | 1
Uno (carte) | 2
Scrabble (plateau) | 1
Bataille Navale (plateau) | 1
Monopoly (plateau) | 2
Poker (carte) |	2
Black Jack (carte) | 1
Loup-Garou (carte) | 1

> Ainsi que de nouvelle proposition :
* Tarôt (carte)
* Bang ! (carte)
* 7 wonders (plateau)
* Shadow Hunter (plateau)

> Nous avons finalement choisi de baser notre projet sur une version de la [bataille navale](https://fr.wikipedia.org/wiki/Bataille_navale_(jeu)) qui nous serait propre avec du 2 contre 2 (voir plus), des compétences, un **gameplay asyncrone/asymétrique** (cf lexique) ainsi qu'une nouvelle dimension au plateau de jeu.

## Choix du langage

(Arrivé d'Arnaud)
> Synthèse des votes Discord :

Langage | Voix
--|--
C/C++ | 7
Java | 7
Lisaac | 2
Python | 2
C# | 1
Web | 4
Shell | 3

> Après une longue hésitation nous nous sommes finalement décidé et nous allons coder notre projet en C++.
> Pour l'interface graphique la ou les librairies ou API reste encore à décider, nous étudirons les technologies à notre disposition ultérieurement, l'interface n'étant pas prioritaire.

## Règles

> Après ces choix, nous avons un peu plus explicité les règles, les compétences, etc, que nous voulions inclure dans notre version de la bataille navale.
> Une fois mise au propre elle seront disponible dans un autre document "**regles.md**".


# Deuxième partie

## Stratégie et organisation

> Après une pause pour détendre nos cerveaux, il était tant de parler de nos stratégie d'approche de notre projet.
> Pour git nous avons décidé de nous diriger vers un **branching model** (cf lexique) de type "tronc stable, branche instable".
> Pour ce qui relève de l'implémentation, au vu de nos différences de connaissances/compétences dans les domaines qui toucheront ce projet nous avons décidé de faire des groupes de soutien/mise à niveau au sein des modules. Nous encouragerons aussi à programmer avec des membres de son module autant que possible, ce qui relève du "[pair programming](https://en.wikipedia.org/wiki/Pair_programming)".
> Nous avons donc enchainé avec nos points forts et centres d'intérêts pour nous "assigner" à des modules. L'assignation sera évidemment souple au possible afin d'aplanir les charges de travail et augmenter notre performance humaine.

## Spécification

(Départ de Liesse)
> Dans l'heure restante nous avons débatu de l'architechture orienté objet du jeu.
> Nous avons donc dessiné les premières esquisse de diagramme de classe UML.
> Une fois mis au propre et complété il sera disponible dans un autre document "**diagramme_de_classe**".

---

### Présences
- [x] KEPPEL Arnaud (arrivé 30min en retard)
- [x] KNAPP Liesse (parti 1h en avance)
- [x] KUSOGLU Garip
- [x] LAHMER Seyyid-Ahmed
- [ ] LOPEZ Stéphane (toujours inconnu au bataillon)
- [x] MANSSOUR Nabil
- [x] MASSART Jules
- [x] MEYER Alexandre
- [x] MICHEL Julien
- [ ] MICHELAT Maxime (a prévenu 5min avant la réunion de son absence)

### Lexique

* Gameplay asynchrone/asymétrique : dans le cadre d'un jeu multijoueur, un tel gameplay propose le même contenu ludique aux différents joueurs mais au travers de mécaniques de jeu différentes ou de points de vues différents afin que les joueurs disposent d'une expérience de jeu différentes.
Exemple : Super Mario Bros U, sur Wii U, qui proposait un gameplay différent au joueur disposant du Wii U gamepad à celui du joueur disposant d'une manette classique.
* Branching model : modèle de gestion du master et des branches lors de l'utilisation d'un git.