# PLD compilateur: documentation développeur

## Introduction
Ce répertoire contient le code source d'un projet étudiant (4A INSA Lyon) visant à créer un compilateur pour un sous-ensemble simple du langage C. L'exécutable peut être produit pour 2 architectures différentes : x86 (par défaut) et arm. Ce projet est réalisé en C++, suivant la méthodologie du Test Driven Development et utilise le framework antlr4. 

Ce projet a été créé par l'hexanome H4212 composé de :
- Bouvier Julien
- Boyer Maxime
- Cristoforoni Stella
- Deleglise Benoit
- Guigal Allan
- Marc Quentin
- Tournade Aurélien

## Prérequis
Pour pouvoir utiliser ce projet, assurez-vous :
- d'être en capacité de compiler du C++ (C++ 11 en l'occurence)
- d'avoir antlr4 d'installé sur votre machine
- d'avoir cmake installé sur votre machine

Normalement, l'installation et le lancement du projet ne diffère pas selon votre OS: la compatibilité mac / windows est gérée dans le code.

## Utilisation
Dans un premier temps, allez dans le dossier `compiler/` puis entrez la commande `make` pour compiler le projet. Ensuite, entrez la commande `ifcc FICHIER` ou FICHIER est le nom du fichier .c que vous souhaitez compiler. Notre compilateur va lire votre fichier et générer l'exécutable correspondant, à moins qu'une erreur soit détectée, auxquel cas il affichera l'erreur décetctée et la ligne où se trouve le problème.

Pour pouvoir utiliser le projet sur les machines du département (distribution fedora), lancer le fichier `compiler/runmake_fedora.sh`. Ce script définit les bons paths pour les variables antlr liés à cette distribution. 

## Fonctionnalités implémentées
Notre compilateur est capable de comprendre un programme C composé :
- d'un seul fichier source (les directives pré-processing sont ignorées)
- d’un main et son retour
- d’initialisations de variables (pas forcément sur une seule ligne, les variables peuvent être initialisées n’importe où)
- d’affectations (tout type d'affectations)
- de conditions (if/else)
- de boucles
- de fonctions
- d’opérations arithmétiques 

## Gestion des erreurs
Notre compilateur est capable de détecter différentes erreurs. La détection des erreurs suivantes a été implémentée :
- détection des erreurs lexicales
- détection des erreurs syntaxiques
- détection des erreurs sémantiques simples

## Limites de notre compilateur
Notre compilateur est un projet universitaire. A ce titre, il ne réalise qu'une petite partie des fonctionnalités d'un vrai compilateur. Ainsi vous ne pouvez pas:
- compiler un programme contenant plusieurs sources
- utiliser les directives pré-processeur
- utiliser les pointeurs
- utiliser de la COO
- utiliser des fonctions de plus de 6 arguments
- utiliser des types de variables autres que int et char

Si vous ne respectez pas les consignes ci-dessus, vous vous exposez à un comportement ératique du compilateur. Une erreur ne sera pas forcément levée car ces fonctionnalités n'ont pas été prises en considération dans la conception du projet.
