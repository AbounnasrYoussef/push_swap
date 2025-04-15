# push_swap

## 🧠 Objectif du projet

Le but de ce projet est de trier une pile de nombres entiers en utilisant un ensemble limité d'instructions, tout en essayant d'utiliser **le moins de mouvements possible**.

Le programme est divisé en deux parties :
- **push_swap** : qui génère les instructions pour trier la pile.
- **checker** : qui vérifie si la suite d'instructions donnée trie correctement la pile.

Ce projet est un excellent exercice d'algorithmie et d'optimisation.

---

## 🧩 Les Règles

Deux piles sont utilisées :
- **pile A** : pile initiale contenant les nombres.
- **pile B** : pile vide.

Les instructions autorisées sont :
- `sa`, `sb`, `ss` : swap le haut de la pile.
- `pa`, `pb` : push d’une pile vers l’autre.
- `ra`, `rb`, `rr` : rotation (haut → bas).
- `rra`, `rrb`, `rrr` : reverse rotation (bas → haut).

---

## 📚 Étapes du projet

### 1. **Parsing et vérifications**
- Vérifier que les arguments sont bien des entiers valides.
- Vérifier les doublons.
- Gérer les erreurs (caractères non valides, overflow, etc).

### 2. **Mise en place des structures de données**
- Utiliser une liste chaînée ou tableau dynamique pour représenter les piles.
- Initialiser pile A avec les valeurs données.

### 3. **Checker (bonus séparé)**
- Lire des instructions depuis `stdin`.
- Les appliquer et vérifier si la pile A est triée et B vide.

### 4. **Génération des mouvements (push_swap)**
- Implémenter des algorithmes de tri adaptés :
  - Tri simple pour 2-5 éléments (tri à la main).
  - Tri par indexation et radix sort pour un grand nombre d’éléments.
- Optimiser le nombre de coups.

---

## 🚀 Utilisation

### Compilation
```bash
make
