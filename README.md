# PLD compilateur: documentation développeur

## Introduction
Ce répertoire contient le code source d'un projet étudiant (4A INSA Lyon) visant à créer un compilateur pour un sous ensemble simple du langage C. Ce projet est réalisé en C++, suivant la méthodologie TDD et utilise le framework antlr4.

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
`compiler/`: contient le code source du projet et notemment le Makefile

- `compiler/ast/`: code relatif à la création et au parcours de l'AST

- `compiler/error/`: code relatif à la gestion des erreurs du compilateur
  
- `compiler/intermediateRepresentation/`: code relatif à l'IR et au CFG
  
- `compiler/symbolTable/`: code relatif à la gestion de la table des symboles
  
`tests/`: contient tous les fichiers et les scripts relatifs aux tests du projet. 





The source code is in the compiler folder. <br>
The tests are in the test folder. <br>
The intermediate document is in the docs folder. <br>
