# so_long

Un projet de l'école **42** qui consiste à créer un jeu en 2D minimaliste en utilisant la **MiniLibX**.

## ✨ Objectif

L'objectif principal de ce projet est de se familiariser avec la gestion des **fenêtres**, des **images**, des **entrées clavier** et des **mouvements** dans un environnement graphique simple.

## 📝 Description

Le but du projet est de développer un jeu où le joueur doit collecter des objets, éviter des obstacles et atteindre la sortie pour gagner.

Votre mission est d'implémenter les mécaniques suivantes :

- Charger et afficher une carte en utilisant la **MiniLibX**.
- Gérer les entrées clavier pour déplacer le joueur.
- Collecter tous les objets avant d'atteindre la sortie.
- Gérer les collisions avec les murs et autres obstacles.

## ⚡ Fonctionnalités

- Affichage d'une carte personnalisée.
- Mouvement du joueur via les touches du clavier.
- Gestion des objets à collecter et de la condition de victoire.
- Système de comptage des mouvements du joueur.
- Fermeture correcte du programme en cas de victoire ou d'erreur.

## 🛠️ Compilation et Exécution

Cloner le dépôt :

```bash
git clone https://github.com/votre_nom/so_long.git
cd so_long
```

Compiler le projet :

```bash
make
```

Exécuter :

```bash
./so_long maps/exemple.ber
```

## 🔥 Exemples de Sortie

![Exemple de jeu](https://i.ibb.co/Vpx0bffx/so-long.png)

## 📊 Format de la Carte

Le fichier de la carte doit respecter les règles suivantes :

- La carte doit être rectangulaire.
- Elle doit contenir :
  - `1` : Murs
  - `0` : Sol
  - `P` : Position initiale du joueur
  - `C` : Objets à collecter
  - `E` : Sortie

Exemple :

```
11111
1P0C1
100E1
11111
```

## 💡 Stratégies d'Optimisation

- Validation du format de la carte avant l'exécution.
- Optimisation du rendu graphique en ne redessinant que les éléments nécessaires.
- Utilisation efficace des **hooks** de la **MiniLibX** pour gérer les entrées.
  
## 👤 Auteur

Projet réalisé par :

- [Noe-prt](https://github.com/Noe-prt)

