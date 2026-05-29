# EasyStock - Système de Gestion de Stock en Langage C

## 📝 Description
EasyStock est une application console développée en Langage C pour aider les petites entreprises ou commerces à automatiser le suivi de leur inventaire. L'application permet de gérer l'entrée de produits, la vérification des stocks disponibles, les réapprovisionnements et la mise à jour des quantités en temps réel lors des ventes.

## 🚀 Fonctionnalités principale
- **Ajout de produits :** Enregistrement du nom, du prix et de la quantité de chaque article (jusqu'à 50 produits).
- **Vérification du stock :** Recherche instantanée pour savoir si un produit est disponible ou en rupture.
- **Gestion des flux :** Prise en charge automatique des ventes (réduction du stock) et des nouvelles livraisons (réapprovisionnement).
- **Rapport d'inventaire :** Affichage propre et tabulaire de tout le stock directement dans la console.

## 🛠️ Concepts Informatiques Appliqués
- **Tableaux parallèles 1D :** Liaison des données (noms, prix, quantités) par correspondance d'index.
- **Pointeurs (`int *n`) :** Gestion sécurisée et dynamique du nombre d'éléments à travers les fonctions.
- **Modularité :** Découpage du code en fonctions indépendantes et réutilisables pour une meilleure clarté.

## 💻 Exemple d'affichage dans le terminal
```text
Nom du Produit        | Prix Unitaire (DT)   | Quantite en Stock
-----------------------------------------------------------------
clavier_RGB           | 120                  | 20
ecran_144Hz           | 550                  | 12
casque_HyperX         | 240                  | 18
tapis_XL              |45                    |50
souris_Viper          |190                   |22
