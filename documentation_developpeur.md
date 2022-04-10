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
Pour pouvoir reprendre ce projet, assurez-vous :
- d'être en capacité de compiler du C++ (C++ 11 en l'occurence)
- d'avoir antlr4 d'installé sur votre machine
- d'avoir cmake installé sur votre machine

Normalement, l'installation et le lancement du projet ne diffère pas selon votre OS: la compatibilité mac / windows est gérée dans le code.

## Organisation du code
Le code du projet est organisé de la manière suivante :

`compiler/`: contient le code source du projet et notemment le Makefile

- `compiler/ast/` : code relatif à la création et au parcours de l'AST

- `compiler/error/` : code relatif à la gestion des erreurs du compilateur
  
- `compiler/intermediateRepresentation/` : code relatif à l'IR et au CFG
  
- `compiler/symbolTable/` : code relatif à la gestion de la table des symboles
  
`tests/` : contient tous les fichiers et les scripts relatifs aux tests du projet. 


Dans ces dossiers, vous trouverez quelques fichiers clefs pour le projet. En voici une description sommaire:

- `AstVisitor.cpp` : Visite du code source parsé sous forme d'arbre (il parcourt chacun des noeuds). En fonction du contexte, il décide l'action à réaliser.

- `compiler/ast.cpp` : linéarise les objets créés par l'AstVisitor. Appelle IrInstr pour écrire les instructions de l'executable.

- `compiler/intermediateRepresentation/IR_instr.cpp` : Repertorie toutes les instructions assembleur à écrire en fonction de chaque cas. Les instructions peuvent être en x86 ou arm.

- `compiler/intermediateRepresentation/CFG.cpp` : lien entre l'AST et la symbole Table

- `compiler/intermediateRepresentation/BasicBlock.cpp` : Retourne les pointeurs d'accès au CFG en fonction de chaque cas.

## Utilisation
Dans un premier temps, allez dans le dossier `compiler/` puis entrez la commande `make` pour compiler le projet. Ensuite, entrez la commande `ifcc FICHIER` ou FICHIER est le nom du fichier .c que vous souhaitez compiler. Notre compilateur va lire votre fichier et générer l'exécutable correspondant, à moins qu'une erreur soit détectée, auxquel cas il affichera l'erreur décetctée et la ligne où se trouve le problème.

Pour pouvoir utiliser le projet sur les machines du département (distribution fedora), lancer le fichier `compiler/runmake_fedora.sh`. Ce script définit les bons paths pour les variables antlr liés à cette distribution. 

Pour lancer les tests, allez dans le dossier `compiler/` et entrez la commande `ifcc-test.py testfiles/`.

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

Voici un schéma qui montre le fonctionnement de notre compilateur:

![compilo-Page-1 drawio](https://user-images.githubusercontent.com/60465886/162623633-36393358-172a-4270-8224-b79ad6b61ec3.png)

Dans un premier temps, le fichier .c est parsé et l'AST est construit à partir du parsing. Si une erreur est détectée à ce stade, la compilation échoue et l'utilisateur est averti. Chaque symbole est stocké dans la table des symboles, et cette table est utilisée par toutes les briques de base du programme. Enfin, le Backend construit l'exécutable demandé (x86 ou arm).

## Gestion des erreurs
Notre compilateur est capable de détecter différentes erreurs. La détection des erreurs suivantes a été implémentée :
- détection des erreurs lexicales
- détection des erreurs syntaxiques
- détection des erreurs sémantiques simples

## Gestion des tests
Ce projet a été développé selon la méthodologie du Test Driven Development (TDD). Les tests ont donc été créés en amont. 

Les tests, placés dans le répertoire `tests/`, fonctionnent de la manière suivante. Notre compilateur essaye de compiler différents fichiers .c créés spécifiquement pour les tests. Les mêmes fichiers sont compilés en parallèle avec gcc, le compilateur officiel du langage c, et les résultats obtenus sont alors comparés. Cette gestion des tests nous permet de contrôler le fait que tout nouveau développement n'entraîne pas de changements néfastes au niveau des exécutables produits par notre compilateur.

Selon la distribution sur laquelle les tests sont lancés, il se peut qu'ils se lancent mal. Il est possible de repérer lorsque la batterie de tests se lance mal si la plupart des tests de comparaison (`TEST-CASE: ifcc-test-output/testfiles-comparatives-...`) ne passent pas. A ce moment là il y a plusieurs possibilités, et voici trois recommandations :
1 - Vérifiez les droits en lecture / écriture sur le fichier `ifcc-wrapper.sh`. Eventuellement, corrigez-les (`chmod -x ifcc-wrapper.sh`).
2 - Changez la première ligne du idcc-wrapper.sh de "`#!/bin/sh`" en "`#!/bin/bash`", et vérifiez que ce fichier soit bien en séquence de fin de ligne "LF" et non pas en "CRLF". Faites de même pour le fichier ifcc-test.py.

Il est aussi possible de lancer les tests pour une architecture arm. Pour cela il suffit de se placer dans le dossier ARM et lancer les tests de cette manière : `./ifcc-test-arm.py ../testfiles/`. Il est possible de changer le chemin passé en argument pour effectuer le test sur n'importe quel fichier .c ou dossier comprenant uniquement des fichiers c.
Dans le cas où les tests sont lancés sur une architecture autre que ARM, il est possible de d'installer un émulateur, voici la manipulation pour une distribution ubuntu (résumé de la manipulation décrite sur `https://gist.github.com/luk6xff/9f8d2520530a823944355e59343eadc1`:
1 - `sudo apt-get install gcc-arm-linux-gnueabihf libc6-dev-armhf-cross qemu-user-static` 
2 - `sudo apt-get install qemu`


## Limites du compilateur
Notre compilateur est un projet universitaire. A ce titre, il ne réalise qu'une petite partie des fonctionnalités d'un vrai compilateur. Ainsi vous ne pouvez pas:
- compiler un programme contenant plusieurs sources
- utiliser les directives pré-processeur
- utiliser les pointeurs
- utiliser de la POO
- utiliser des fonctions de plus de 6 arguments
- utiliser des types de variables autres que int et char

Si vous ne respectez pas les consignes ci-dessus, vous vous exposez à un comportement ératique du compilateur. Une erreur ne sera pas forcément levée car ces fonctionnalités n'ont pas été prises en considération dans la conception du projet.
