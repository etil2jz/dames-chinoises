// Suppression du message chiant du compilateur sur la dépréciation de certaines fonctions en C moderne
#define _CRT_SECURE_NO_WARNINGS 
// Les biblios
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// On déclare les structures nécessaires au jeu
typedef struct pions {
	char nom; // de 0 à 9 pions joueur
    int ligne, colonne, ekip; // coordonnées et équipe
}pions;

typedef struct joueurs {
	char nom[256]; // j'espère qu'ils auront pas un nom trop long...
	int ekip; // de 1 à 6
}joueurs;

// On définit une couleur juste avant de printf quelque chose
void Couleur(int couleurDuTexte, int couleurDeFond) {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

// On demande le nombre de joueurs et leur pseudo
int AskJoueur() {
    int rep;
    do {
        printf("Nombre de joueurs = ");
        scanf("%i", &rep);
        switch (rep) {
            case 2:
            // Commence le jeu avec 2J
                system("cls");
                return 2;
                break;
            case 4:
            // Commence le jeu avec 4J
                system("cls");
                return 4;
                break;
            case 6:
            // Commence le jeu avec 6J
                system("cls");
                return 6;
                break;
            default:
                system("cls");
                printf("Il n'est pas possible de jouer avec %i joueurs...", rep);
                break;
        }
    } while (rep % 2 != 0 || rep < 2 || rep > 6);
    return 0;
}

void NomJoueur(int NBekip, joueurs j1, joueurs j2, joueurs j3, joueurs j4, joueurs j5, joueurs j6) {
    if (NBekip == 2) {
        // Joueur 1
        printf("Nom du ");
        Couleur(2, 0);
        printf("Joueur 1");
        Couleur(7, 0);
        printf(" : ");
        fgets(j1.nom, sizeof(j1.nom), stdin);
        fgets(j1.nom, sizeof(j1.nom), stdin);
        printf("%s", j1.nom);
        // Joueur 2
        printf("\nNom du ");
        Couleur(14, 0);
        printf("Joueur 2");
        Couleur(7, 0);
        printf(" : ");
        fgets(j2.nom, sizeof(j2.nom), stdin);
        printf("%s", j2.nom);
    }
    if (NBekip == 4) {
        // Joueur 1
        printf("Nom du ");
        Couleur(2, 0);
        printf("Joueur 1");
        Couleur(7, 0);
        printf(" : ");
        fgets(j1.nom, sizeof(j1.nom), stdin);
        fgets(j1.nom, sizeof(j1.nom), stdin);
        printf("%s", j1.nom);
        // Joueur 2
        printf("\nNom du ");
        Couleur(14, 0);
        printf("Joueur 2");
        Couleur(7, 0);
        printf(" : ");
        fgets(j2.nom, sizeof(j2.nom), stdin);
        printf("%s", j2.nom);
        // Joueur 3
        printf("\nNom du ");
        Couleur(9, 0);
        printf("Joueur 3");
        Couleur(7, 0);
        printf(" : ");
        fgets(j3.nom, sizeof(j3.nom), stdin);
        printf("%s", j3.nom);
        // Joueur 4
        printf("\nNom du ");
        Couleur(12, 0);
        printf("Joueur 4");
        Couleur(7, 0);
        printf(" : ");
        fgets(j4.nom, sizeof(j4.nom), stdin);
        printf("%s", j4.nom);
    }
    if (NBekip == 6) {
        // Joueur 1
        printf("Nom du ");
        Couleur(2, 0);
        printf("Joueur 1");
        Couleur(7, 0);
        printf(" : ");
        fgets(j1.nom, sizeof(j1.nom), stdin);
        fgets(j1.nom, sizeof(j1.nom), stdin);
        printf("%s", j1.nom);
        // Joueur 2
        printf("\nNom du ");
        Couleur(14, 0);
        printf("Joueur 2");
        Couleur(7, 0);
        printf(" : ");
        fgets(j2.nom, sizeof(j2.nom), stdin);
        printf("%s", j2.nom);
        // Joueur 3
        printf("\nNom du ");
        Couleur(9, 0);
        printf("Joueur 3");
        Couleur(7, 0);
        printf(" : ");
        fgets(j3.nom, sizeof(j3.nom), stdin);
        printf("%s", j3.nom);
        // Joueur 4
        printf("\nNom du ");
        Couleur(12, 0);
        printf("Joueur 4");
        Couleur(7, 0);
        printf(" : ");
        fgets(j4.nom, sizeof(j4.nom), stdin);
        printf("%s", j4.nom);
        // Joueur 5
        printf("\nNom du ");
        Couleur(6, 0);
        printf("Joueur 5");
        Couleur(7, 0);
        printf(" : ");
        fgets(j5.nom, sizeof(j5.nom), stdin);
        printf("%s", j5.nom);
        // Joueur 6
        printf("\nNom du ");
        Couleur(13, 0);
        printf("Joueur 6");
        Couleur(7, 0);
        printf(" : ");
        fgets(j6.nom, sizeof(j6.nom), stdin);
        printf("%s", j6.nom);
    }
}

// On initialise les pions pour le début de partie
void initPions(pions TousLesPions[]) {
    TousLesPions[0].ekip = 0;
    TousLesPions[0].nom = ' ';

    TousLesPions[64].ekip = 9;
    TousLesPions[64].nom = '.';

    TousLesPions[1].ekip = 1;
    TousLesPions[1].nom = '0';
    TousLesPions[1].ligne = 0;
    TousLesPions[1].colonne = 7;

    TousLesPions[2].ekip = 1;
    TousLesPions[2].nom = '1';
    TousLesPions[2].ligne = 1;
    TousLesPions[2].colonne = 7;

    TousLesPions[3].ekip =1;
    TousLesPions[3].nom = '2';
    TousLesPions[3].ligne = 1;
    TousLesPions[3].colonne = 8;

    TousLesPions[4].ekip =1;
    TousLesPions[4].nom = '3';
    TousLesPions[4].ligne = 2;
    TousLesPions[4].colonne = 6;

    TousLesPions[5].ekip = 1;
    TousLesPions[5].nom = '4';
    TousLesPions[5].ligne = 2;
    TousLesPions[5].colonne = 7;

    TousLesPions[6].ekip = 1;
    TousLesPions[6].nom = '5';
    TousLesPions[6].ligne = 2;
    TousLesPions[6].colonne = 8;

    TousLesPions[7].ekip = 1;
    TousLesPions[7].nom = '6';
    TousLesPions[7].ligne = 3;
    TousLesPions[7].colonne = 6;

    TousLesPions[8].ekip = 1;
    TousLesPions[8].nom = '7';
    TousLesPions[8].ligne = 3;
    TousLesPions[8].colonne = 7;

    TousLesPions[9].ekip = 1;
    TousLesPions[9].nom = '8';
    TousLesPions[9].ligne = 3;
    TousLesPions[9].colonne = 8;

    TousLesPions[10].ekip = 1;
    TousLesPions[10].nom = '9';
    TousLesPions[10].ligne = 3;
    TousLesPions[10].colonne = 9;

    TousLesPions[11].ekip = 2;
    TousLesPions[11].nom = '0';
    TousLesPions[11].ligne = 16;
    TousLesPions[11].colonne = 7;

    TousLesPions[12].ekip = 2;
    TousLesPions[12].nom = '1';
    TousLesPions[12].ligne = 15;
    TousLesPions[12].colonne = 7;

    TousLesPions[13].ekip =2;
    TousLesPions[13].nom = '2';
    TousLesPions[13].ligne = 15;
    TousLesPions[13].colonne = 8;

    TousLesPions[14].ekip =2;
    TousLesPions[14].nom = '3';
    TousLesPions[14].ligne = 14;
    TousLesPions[14].colonne = 6;

    TousLesPions[15].ekip = 2;
    TousLesPions[15].nom = '4';
    TousLesPions[15].ligne = 14;
    TousLesPions[15].colonne = 7;

    TousLesPions[16].ekip = 2;
    TousLesPions[16].nom = '5';
    TousLesPions[16].ligne = 14;
    TousLesPions[16].colonne = 8;

    TousLesPions[17].ekip = 2;
    TousLesPions[17].nom = '6';
    TousLesPions[17].ligne = 13;
    TousLesPions[17].colonne = 6;

    TousLesPions[18].ekip = 2;
    TousLesPions[18].nom = '7';
    TousLesPions[18].ligne = 13;
    TousLesPions[18].colonne = 7;

    TousLesPions[19].ekip =2;
    TousLesPions[19].nom = '8';
    TousLesPions[19].ligne = 13;
    TousLesPions[19].colonne = 8;

    TousLesPions[20].ekip = 2;
    TousLesPions[20].nom = '9';
    TousLesPions[20].ligne = 13;
    TousLesPions[20].colonne = 9;

    TousLesPions[21].ekip = 3;
    TousLesPions[21].nom = '0';
    TousLesPions[21].ligne = 4;
    TousLesPions[21].colonne = 1;

    TousLesPions[22].ekip = 3;
    TousLesPions[22].nom = '2';
    TousLesPions[22].ligne = 4;
    TousLesPions[22].colonne = 2;

    TousLesPions[23].ekip =3;
    TousLesPions[23].nom = '5';
    TousLesPions[23].ligne = 4;
    TousLesPions[23].colonne = 3;

    TousLesPions[24].ekip =3;
    TousLesPions[24].nom = '9';
    TousLesPions[24].ligne = 4;
    TousLesPions[24].colonne = 4;

    TousLesPions[25].ekip = 3;
    TousLesPions[25].nom = '1';
    TousLesPions[25].ligne = 5;
    TousLesPions[25].colonne = 2;

    TousLesPions[26].ekip = 3;
    TousLesPions[26].nom = '4';
    TousLesPions[26].ligne = 5;
    TousLesPions[26].colonne = 3;

    TousLesPions[27].ekip = 3;
    TousLesPions[27].nom = '8';
    TousLesPions[27].ligne = 5;
    TousLesPions[27].colonne = 4;

    TousLesPions[28].ekip = 3;
    TousLesPions[28].nom = '3';
    TousLesPions[28].ligne = 6;
    TousLesPions[28].colonne = 2;

    TousLesPions[29].ekip = 3;
    TousLesPions[29].nom = '7';
    TousLesPions[29].ligne = 6;
    TousLesPions[29].colonne = 3;

    TousLesPions[30].ekip = 3;
    TousLesPions[30].nom = '6';
    TousLesPions[30].ligne = 7;
    TousLesPions[30].colonne = 3;

    TousLesPions[31].ekip = 4;
    TousLesPions[31].nom = '0';
    TousLesPions[31].ligne = 12;
    TousLesPions[31].colonne = 13;

    TousLesPions[32].ekip = 4;
    TousLesPions[32].nom = '1';
    TousLesPions[32].ligne = 11;
    TousLesPions[32].colonne = 13;

    TousLesPions[33].ekip =4;
    TousLesPions[33].nom = '2';
    TousLesPions[33].ligne = 12;
    TousLesPions[33].colonne = 12;

    TousLesPions[34].ekip =4;
    TousLesPions[34].nom = '3';
    TousLesPions[34].ligne = 10;
    TousLesPions[34].colonne = 12;

    TousLesPions[35].ekip = 4;
    TousLesPions[35].nom = '4';
    TousLesPions[35].ligne = 11;
    TousLesPions[35].colonne = 12;

    TousLesPions[36].ekip = 4;
    TousLesPions[36].nom = '5';
    TousLesPions[36].ligne = 12;
    TousLesPions[36].colonne = 11;

    TousLesPions[37].ekip = 4;
    TousLesPions[37].nom = '6';
    TousLesPions[37].ligne = 9;
    TousLesPions[37].colonne = 12;

    TousLesPions[38].ekip = 4;
    TousLesPions[38].nom = '7';
    TousLesPions[38].ligne = 10;
    TousLesPions[38].colonne = 11;

    TousLesPions[39].ekip = 4;
    TousLesPions[39].nom = '8';
    TousLesPions[39].ligne = 11;
    TousLesPions[39].colonne =11;

    TousLesPions[40].ekip = 4;
    TousLesPions[40].nom = '9';
    TousLesPions[40].ligne = 12;
    TousLesPions[40].colonne = 10;

    TousLesPions[41].ekip = 5;
    TousLesPions[41].nom = '0';
    TousLesPions[41].ligne = 4;
    TousLesPions[41].colonne = 13;

    TousLesPions[42].ekip = 5;
    TousLesPions[42].nom = '1';
    TousLesPions[42].ligne = 5;
    TousLesPions[42].colonne = 13;

    TousLesPions[43].ekip =5;
    TousLesPions[43].nom = '2';
    TousLesPions[43].ligne = 4;
    TousLesPions[43].colonne = 12;

    TousLesPions[44].ekip =5;
    TousLesPions[44].nom = '3';
    TousLesPions[44].ligne = 6;
    TousLesPions[44].colonne = 12;

    TousLesPions[45].ekip = 5;
    TousLesPions[45].nom = '4';
    TousLesPions[45].ligne = 5;
    TousLesPions[45].colonne = 12;

    TousLesPions[46].ekip = 5;
    TousLesPions[46].nom = '5';
    TousLesPions[46].ligne = 4;
    TousLesPions[46].colonne = 11;

    TousLesPions[47].ekip = 5;
    TousLesPions[47].nom = '6';
    TousLesPions[47].ligne = 7;
    TousLesPions[47].colonne = 12;

    TousLesPions[48].ekip = 5;
    TousLesPions[48].nom = '7';
    TousLesPions[48].ligne = 6;
    TousLesPions[48].colonne = 11;

    TousLesPions[49].ekip = 5;
    TousLesPions[49].nom = '8';
    TousLesPions[49].ligne = 5;
    TousLesPions[49].colonne =11;

    TousLesPions[50].ekip = 5;
    TousLesPions[50].nom = '9';
    TousLesPions[50].ligne = 4;
    TousLesPions[50].colonne = 10;

    TousLesPions[51].ekip = 6;
    TousLesPions[51].nom = '0';
    TousLesPions[51].ligne = 12;
    TousLesPions[51].colonne = 1;

    TousLesPions[52].ekip = 6;
    TousLesPions[52].nom = '2';
    TousLesPions[52].ligne = 12;
    TousLesPions[52].colonne = 2;

    TousLesPions[53].ekip = 6;
    TousLesPions[53].nom = '5';
    TousLesPions[53].ligne = 12;
    TousLesPions[53].colonne = 3;

    TousLesPions[54].ekip = 6;
    TousLesPions[54].nom = '9';
    TousLesPions[54].ligne = 12;
    TousLesPions[54].colonne = 4;

    TousLesPions[55].ekip = 6;
    TousLesPions[55].nom = '1';
    TousLesPions[55].ligne = 11;
    TousLesPions[55].colonne = 2;

    TousLesPions[56].ekip = 6;
    TousLesPions[56].nom = '4';
    TousLesPions[56].ligne = 11;
    TousLesPions[56].colonne = 3;

    TousLesPions[57].ekip = 6;
    TousLesPions[57].nom = '8';
    TousLesPions[57].ligne = 11;
    TousLesPions[57].colonne = 4;

    TousLesPions[58].ekip = 6;
    TousLesPions[58].nom = '3';
    TousLesPions[58].ligne = 10;
    TousLesPions[58].colonne = 2;

    TousLesPions[59].ekip = 6;
    TousLesPions[59].nom = '7';
    TousLesPions[59].ligne = 10;
    TousLesPions[59].colonne = 3;

    TousLesPions[60].ekip = 6;
    TousLesPions[60].nom = '6';
    TousLesPions[60].ligne = 9;
    TousLesPions[60].colonne = 3;
}

// On place les pions dans le plateau pour chaque tour (pas un init, il doit être exécuté à chaque tour pour placer l'update des pions dans le plateau)
void tickPlateau(char plateau[][14], pions TousLesPions[], int NBekip) {
    int limiteplus = 7, limitemoins = 7;
    for (int ligne = 0; ligne < 17; ligne++) {
        // On remplit tout le plateau de vide
        for (int colonne = 0; colonne < 14; colonne++) {
            plateau[ligne][colonne] = TousLesPions[0].nom;
        }
        // Structure de base pyramide haute
        if (ligne < 13) {
            for (int colonne = 7; colonne <= limiteplus; colonne++) {
                plateau[ligne][colonne] = TousLesPions[64].nom;
            }
            for (int colonne = 7; colonne >= limitemoins; colonne--) {
                plateau[ligne][colonne] = TousLesPions[64].nom;
            }
            if (ligne % 2 != 0 && limitemoins >= 0) limitemoins--;
            if (ligne % 2 == 0) limiteplus++;
        }
    }
    limitemoins = 7;
    limiteplus = 7;
    for (int ligne = 16; ligne >= 0; ligne--) {
        // Structure de base pyramide basse
        if (ligne > 3) {
            for (int colonne = 7; colonne <= limiteplus; colonne++) {
                plateau[ligne][colonne] = TousLesPions[64].nom;
            }
            for (int colonne = 7; colonne >= limitemoins; colonne--) {
                plateau[ligne][colonne] = TousLesPions[64].nom;
            }
            if (ligne % 2 != 0 && limitemoins >= 0) limitemoins--;
            if (ligne % 2 == 0) limiteplus++;
        }
    }

    // Affectation des pions joueur

    // Il faut qu'on intègre le nombre d'équipe ICI

    for (int ligne = 0; ligne < 20; ligne++) {
        for (int colonne = 0; colonne < 20; colonne++) {
            for (int a = 0; a < 64; a++) {
                if (TousLesPions[a].ligne == ligne && TousLesPions[a].colonne == colonne && TousLesPions[a].ekip <= NBekip && TousLesPions[a].ekip > 0) plateau[ligne][colonne] = TousLesPions[a].nom;
            }
        }
    }
}

void affichagePlateau(char plateau[][14], pions TousLesPions[]) {
    system("cls");
    for (int ligne = 0; ligne < 17; ligne++) {
        for (int colonne = 0; colonne < 14; colonne++) {
            if (ligne % 2 == 0) {
                for (int i = 0; i < 62; i++) {
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 1) Couleur(2, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 2) Couleur(14, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 3) Couleur(9, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 4) Couleur(12, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 5) Couleur(6, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 6) Couleur(13, 0);
                }
                printf(" %c", plateau[ligne][colonne]);
                Couleur(7, 0);
            }
            if (ligne % 2 != 0) {
                for (int i = 0; i < 62; i++) {
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 1) Couleur(2, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 2) Couleur(14, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 3) Couleur(9, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 4) Couleur(12, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 5) Couleur(6, 0);
                    if (TousLesPions[i].ligne == ligne && TousLesPions[i].colonne == colonne && TousLesPions[i].ekip == 6) Couleur(13, 0);
                }
                printf("%c ", plateau[ligne][colonne]);
                Couleur(7, 0);
            }
        }
        printf("\n");
    }
}

void deplacement(char plateau[][14]) {
    /*
    int pionchoisi, direction;
    Couleur(7, 0);
    //printf("Joueur '%s'", );
    printf("\nQuel pion voulez-vous jouer ? ( 0 a 9 ) => ");
    scanf("%i", &pionchoisi);
    printf("Dans quelle direction voulez-vous jouer ? (0 pour annuler)\n   1%c /2\n   3 - 4\n   5%c /6\n=> ", 92, 92);
    scanf("%i", &direction);
    printf("%i et %i", pionchoisi, direction);
    */
}

int main() {
	char plateau[17][14];
    pions TousLesPions[65];
    int NBekip, rep;
    joueurs j1, j2, j3, j4, j5, j6;
    // Menu
    do {
        Couleur(14, 0);
        printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n\xBA");
        Couleur(12, 0);
        printf("          BIENVENUE SUR          ");
        Couleur(14, 0);
        printf("\xBA\n\xBA");
        Couleur(12, 0);
        printf("       LES DAMES CHINOISES       ");
        Couleur(14, 0);
        printf("\xBA\n\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
        Couleur(7, 0);
        printf("1. Nouvelle partie\n2. Charger une partie existante\n3. Quitter le jeu\n\n=> ");
        scanf("%i", &rep);
        switch (rep) {
            case 1:
            // Lancement du jeu
                system("cls");
                NBekip = AskJoueur();
                break;
            case 2:
            // Charger une ancienne partie (à implémenter, code de Matthieu)
                system("cls");
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Veuillez r%cessayer\n", 130);
        }
    } while (rep < 1 || rep > 3);
    // Reste des fonctions
    NomJoueur(NBekip, j1, j2, j3, j4, j5, j6);
    initPions(TousLesPions);
    tickPlateau(plateau, TousLesPions, NBekip);
    affichagePlateau(plateau, TousLesPions);
    deplacement(plateau);
}
