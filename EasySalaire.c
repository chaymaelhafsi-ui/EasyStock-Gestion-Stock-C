#include <stdio.h>
#include <string.h>

// Déclaration des variables globales
char nom[50][30];
float h_normales[50];
float h_supp[50];
float salaire_brut[50];
float salaire_net[50];
int n = 0; // Au début, il y a 0 employé

// Taux horaire de base (Exemple : 10 DT / heure)
const float TAUX_HORAIRE = 10.0;
// Taux des retenues (Exemple : 15% pour la CNSS et les impôts)
const float TAUX_RETENUES = 0.15;

// Déclaration des fonctions
void ajouterEmploye();
float calculBrut(float h_norm, float h_sp);
float calculNet(float brut);
float calculPrime(float h_norm, float h_sp);
void afficherBulletin();

int main() {
    int choix;

    do {
        // Affichage du menu interactif
        printf("\n--- MENU EASYSALAIRE ---\n");
        printf("1. Ajouter un employe et calculer sa paie\n");
        printf("2. Afficher les bulletins de paie\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEmploye();
                break;
            case 2:
                afficherBulletin();
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix incorrect, veuillez recommencer.\n");
        }
    } while (choix != 3);

    return 0;
}

// 1. Fonction pour ajouter un employé
void ajouterEmploye() {
    if (n >= 50) {
        printf("Erreur : Le nombre maximum d'employes est atteint (50).\n");
    } else {
        printf("\n--- AJOUT D'UN EMPLOYE ---\n");
        printf("Entrez le nom de l'employe : ");
        scanf("%s", nom[n]);

        printf("Entrez les heures normales effectuees : ");
        scanf("%f", &h_normales[n]);

        printf("Entrez les heures supplementaires effectuees : ");
        scanf("%f", &h_supp[n]);

        // Calcul automatique du salaire pour cet employé à l'indice n
        float brut_de_base = calculBrut(h_normales[n], h_supp[n]);
        float prime = calculPrime(h_normales[n], h_supp[n]);

        // Le salaire brut final inclut la prime
        salaire_brut[n] = brut_de_base + prime;

        // Le salaire net est calculé à partir du brut final
        salaire_net[n] = calculNet(salaire_brut[n]);

        n++; // On passe à l'employé suivant
        printf("Employe ajoute et salaire calcule avec succes !\n");
    }
}

// 2. Fonction pour calculer le salaire brut
// Formule : (Hn × T) + (Hs × T × 1.5)
float calculBrut(float h_norm, float h_sp) {
    float brut;
    brut = (h_norm * TAUX_HORAIRE) + (h_sp * TAUX_HORAIRE * 1.5);
    return brut;
}

// 3. Fonction pour calculer le salaire net
// Formule : Salaire Brut - Retenues (ici on retire 15%)
float calculNet(float brut) {
    float net;
    float retenues = brut * TAUX_RETENUES;
    net = brut - retenues;
    return net;
}

// 4. Fonction pour calculer la prime
// On offre une prime fixe (ex: 200 DT) si le total des heures dépasse 160 heures
float calculPrime(float h_norm, float h_sp) {
    float total_heures = h_norm + h_sp;

    if (total_heures > 160.0) {
        return 200.0; // Accorde une prime de 200
    } else {
        return 0.0;   // Pas de prime
    }
}

// 5. Fonction pour afficher les bulletins de paie
void afficherBulletin() {
    if (n == 0) {
        printf("Aucun employe enregistre. Aucun bulletin a afficher.\n");
    } else {
        printf("\n=====================================\n");
        printf("        BULLETINS DE PAIE\n");
        printf("=====================================\n");

        for (int i = 0; i < n; i++) {
            // Recalcul de la prime juste pour l'affichage de la fiche
            float prime_affiche = calculPrime(h_normales[i], h_supp[i]);

            printf("Nom : %s\n", nom[i]);
            printf("Heures normales : %.1f h | Heures Supp : %.1f h\n", h_normales[i], h_supp[i]);
            printf("Prime accordee  : %.2f\n", prime_affiche);
            printf("Salaire Brut    : %.2f\n", salaire_brut[i]);
            printf("Salaire Net     : %.2f\n", salaire_net[i]);
            printf("-------------------------------------\n");
        }
    }
}
