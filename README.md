# TP0 — Création et préparation des jeux de données pour le TP1 (Test de primalité)

## 1. Présentation du TP

Ce TP a pour objectif d'apprendre à préparer des jeux de données afin de tester expérimentalement la complexité des algorithmes de test de primalité.

Il permet également d'étudier l'impact du choix des données sur l'interprétation des résultats et sur les performances des algorithmes.

## 2. Objectifs

- Construire plusieurs jeux de données répondant aux critères demandés.
- Sélectionner des nombres premiers de manière aléatoire.
- Contrôler les intervalles et le nombre de chiffres des nombres sélectionnés.
- Préparer les données nécessaires aux expérimentations du TP1.
- Observer l'importance du choix des données dans l'évaluation des performances algorithmiques.

## 3. Description des jeux de données

Le TP demande la création de cinq jeux de données :

| Jeu de données | Description |
|---|---|
| `Random100` | 100 nombres premiers tirés aléatoirement à partir de collections de nombres premiers disponibles sur Internet. |
| `Random1000` | 1 000 nombres premiers tirés aléatoirement à partir des mêmes sources. |
| `Test-1` | 100 nombres premiers tirés aléatoirement dans l'intervalle [1 000, 1 000 000]. |
| `Test-2` | Un échantillon de nombres premiers sélectionnés aléatoirement en contrôlant leur nombre de chiffres : 3 chiffres, 4 chiffres, 5 chiffres, etc. |
| `Test-3` | Un échantillon structuré de nombres comportant 3, 6, 9 et 12 chiffres. |

## 4. Sources des données

Les collections de nombres premiers peuvent notamment provenir des sites suivants :

- [BigPrimes](https://bigprimes.net/)
- [Prime Numbers](https://www.prime-numbers.org/)

Ces sources sont mentionnées dans l'énoncé du TP pour la préparation des jeux de nombres premiers.

## 5. Langage de programmation

Le langage utilisé pour l'implémentation est **C**.

## 6. Résultat attendu

À la fin du TP, les jeux de données doivent être préparés conformément aux caractéristiques demandées. Ils serviront ensuite à tester les algorithmes de primalité et à analyser expérimentalement leurs performances.

## 7. Auteur

Projet universitaire réalisé dans le cadre du TP de complexité algorithmique.
