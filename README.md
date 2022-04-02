# PLD compilateur: documentation développeur

## Introduction
Ce répertoire contient le code source d'un projet étudiant (4A INSA Lyon) visant à créer un compilateur pour un sous ensemble simple du langage C. L'exécutable peut être produit pour 2 architectures différentes: x86 (par défaut) et arm. Ce projet est réalisé en C++, suivant la méthodologie du Test Driven Development et utilise le framework antlr4. 

Ce projet a été créé par l'hexanome H4212 composé de:
- Bouvier Julien
- Boyer Maxime
- Cristoforoni Stella
- Deleglise Benoit
- Guigal Allan
- Marc Quentin
- Tournade Aurélien

## Prérequis
Pour pouvoir reprendre ce projet, assurez-vous:
- d'être en capacité de compiler du C++ (C++ 11 en l'occurence)
- d'avoir antlr4 d'installé sur votre machine
- d'avoir cmake installé sur votre machine

Normalement, l'installation et le lancement du projet ne diffère pas selon votre OS: la compatibilité mac / windows est gérée dans le code.

## Organisation du code
Le code du projet est organisé de la manière suivante:

`compiler/`: contient le code source du projet et notemment le Makefile

- `compiler/ast/`: code relatif à la création et au parcours de l'AST

- `compiler/error/`: code relatif à la gestion des erreurs du compilateur
  
- `compiler/intermediateRepresentation/`: code relatif à l'IR et au CFG
  
- `compiler/symbolTable/`: code relatif à la gestion de la table des symboles
  
`tests/`: contient tous les fichiers et les scripts relatifs aux tests du projet. 

## Utilisation
Dans un premier temps, allez dans le dossier `compiler/` puis entrez la commande `make` pour compiler le projet. Ensuite, entrez la commande `ifcc FICHIER` ou FICHIER est le nom du fichier .c que vous souhaitez compiler. Notre compilateur va lire votre fichier et générer l'exécutable correpondant, à moins qu'une erreur soit détectée, auxquel cas il affichera l'erreur décetctée et la ligne où se trouve le problème.

Pour lancer les tests, allez dans le dossier `compiler/` et entrez la commande `ifcc-test.py testfiles/`.

## Fonctionalités implémentées
Notre compilateur est capable de comprendre un programme C composé:
- d’un main et son retour
- d’initialisations de variables (pas forcément sur une seule ligne, les variables peuvent être initialisées n’importe où)
- d’affectations (tout type d'affectations)
- de conditions (if /else)
- de boucles
- de fonctions
- d’opérations arithmétiques 

## Gestion des erreurs
Notre compilateur est capable de détecter des erreurs sémantiques et syntaxiques. La détection des erreurs suivantes a été implémentées:
- déclaration d’une variable alors qui aurait déjà été déclarée
- assignation de la valeur d’une variable à une autre variable alors que la variable assignante n’a été  ni déclarée ni définie (ex: int a = b alors que b n’existe pas)

