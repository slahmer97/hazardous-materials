# Introduction

> Afin d'**aléger la charge mémoire et calcul** la version client du jeu nous avons décidé de transférer le stockage et le calcule de la majorité des informations sur le serveur.
> Cela permet aussi d'avoir une meilleure **gestion de la sécurité et véracité** des informations qui transitent entre le client et le serveur en cas de client truqué.
> Les architectures client et serveur sont des **MVC** plutôt classique.

# Partie client

> L'utilisateur agit sur la **vue** via le module/la classe de l'**interface homme machine**.
> Cette interface affichera le contenu du **modèle**, composé des quatres différentes grilles de jeux de la classe grille qui représente l'intégralité d'un **plateau de jeu**.
> Le **controlleur** se chargera lui d'**interpréter** les actions de l'utilisateur pour les transmettres au seveur, puis en **récupérer** une réponse afin de **mettre à jour** le modèle local des différentes grilles.

# Partie serveur

> Le serveur est un genre de modèle **MVC imbriqué**. 
> La **vue** peut y être représenté comme l'intégralité de **la partie client**.
> Un premier **controlleur** "**maître**" traîte les informations y arrivant, les salons de jeu qu'il **créer**, **modifie** et **détruit** sont autant de **couple modèles-controlleurs**.
> Ces **controlleurs** "**esclaves**" s'occupent chacun de leur propre modèle composé des 4 grilles d'une partie, de leurs cases de jeu, des engins qui les habitent ainsi que les compétences de ces derniers.
> La **base de donnée** des profiles des joueurs ainsi que de leurs statistiques représente l'autre partie du **modèle**.