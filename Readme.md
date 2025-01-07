# Revenge's Island (Archive Lyon 1)

Licence Informatique Université Claude Bernard Lyon 1  
Dernière mise à jour : 10/02/2017  

Compile sur Windows via mingw32-make.

## Table des matières

1. [A propos](#1-a-propos)
2. [Compilation](#2-compilation)
3. [Exécution](#3-exécution)
4. [Documentation](#4-documentation)

## 1. A propos

Le programme est un projet issu de l'enseignement "Conception et développement d'application" dispensé à l'Université Lyon 1.  
Ce projet a pour but la création d'un jeu SDL2/SFML à l'aide de plusieurs fichiers `.cpp`/`.h`.  
Il comporte 3 répertoires de fichiers :  
- `src/core` : contenant le squelette du programme,  
- `src/winTxt` : version terminal ASCII.  
- `src/SDL2` : version graphique SDL2,  
- `src/sfml` : version graphique SFML,  

**Diagramme-des-modules.dia** : contient tous les modules qui ont été implémentés durant la création de l'application. (Afin de l'ouvrir, il faut installer Dia).  
**Diagramme-de-Gantt.pdf** : contient toutes les étapes que nous avons franchies durant le développement de notre projet.

---

## 2. Compilation

```bash
hg clone https://forge.univ-lyon1.fr/hg/p1408299-p1309837
```
Cette commande vous permettra de télécharger le répertoire en entier.  
Pour compiler ce programme sous Linux, il faut utiliser le Makefile grâce à la commande make dans le terminal.  
Pour compiler sur Windows, il faut installer mingw32 et executer via mingw32-make (mettre à jour le PATH si nécessaire).

### Étapes :  

1. ```Make```
2. ```./bin/Revenges_Island_txt.exe```
3. ```./bin/Revenges_Island_sdl.exe```
4. ```./bin/Revenges_Island_sfml.exe```

## 3. Exécution  

Une fois la compilation du programme effectuée sans erreur, trois exécutables seront créés dans le sous-répertoire ```bin``` :
- L'exécutable "Text" contient l'application en mode texte.  
- L'exécutable "SDL" crée l'application à l'aide de la SDL2.  
- L'exécutable "SFML" est une application légèrement plus avancée que celle de la SDL2.  

## 4. Documentation  

Dans le sous-répertoire doc, nous avons un fichier de génération de documentation (créé grâce à Doxygen).  
```index.html``` est la page d'entrée dans la documentation.
