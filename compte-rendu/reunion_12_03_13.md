### Présences
- [x] HUYNH Jimmy
- [x] KEPPEL Arnaud
- [] KNAPP Liesse (prévenu)
- [x] KUSOGLU Garip
- [x] LAHMER Seyyid-Ahmed
- [x] MANSSOUR Nabil
- [x] MASSART Jules
- [x] MEYER Alexandre
- [x] MICHEL Julien
- [x] MICHELAT Maxime


####

Décision du contenu des fichiers json, et structure des messages échangés.

####

Annonce aux joueurs adverses, le mouvement d'un de leur adversaire :
- "A joué" : si le joueur a déplacé un bateau, ou a raté avec un tir normal, ou a utilisé un radar.
- "Compétence" : la compétence utilisée (sauf radar).
- "A touché" : si le joueur a touché une unité avec un tir (normal ou de compétence), l'endroit touché de ton bateau.
+ "A coulé" : si le bateau est coulé, le bateau coulé.

Option de passer son tour ?

#### Avancement

Noyau : manque une partie des tests unitaires.
Interface : premier mock up terminé, dessin à la main de sprites.
Réseau : découverte de la librairie.