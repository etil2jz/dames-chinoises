// Les biblios
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// On déclare les structures nécessaires au jeu
typedef struct pion {
    char nom; // de 0 à 9 pions joueur, le 10 c'est le vide, le 11 c'est indisponible
    int x, y, ekip; // coordonnées et équipe
}pion;

typedef struct joueur {
    //struct pion pions[9];
    char nom[256];
    int numero; // de 1 à 6
}joueur;

// On initialise les pions pour le début de partie
void initPions(pion TousLesPions[]) {
    TousLesPions[0].ekip = 0;
    TousLesPions[0].nom = ' ';

    TousLesPions[1].ekip = 9;
    TousLesPions[1].nom = '*';

    //       Toutlepion[2].ekip=1;
    //       Toutlepion[2].nom='B';
    //       Toutlepion[2].x=2;
    //       Toutlepion[2].y=4;
}

// On initialise le plateau pour le début de partie
// ~~(un bazar puisqu'on init case par case, quand bien même on emploie des boucles)~~
void initPlateau(char plateau[][14], pion TousLesPions[]) {
    int limiteplus = 7, limitemoins = 7;
    for (int ligne = 0; ligne < 17; ligne++) {
        // On remplit tout le plateau de vide
        for (int colonne = 0; colonne < 14; colonne++) {
            plateau[ligne][colonne] = TousLesPions[0].nom;
        }
        // Structure de base pyramide haute
        if (ligne < 13) {
            for (int colonne = 7; colonne <= limiteplus; colonne++) {
                plateau[ligne][colonne] = TousLesPions[1].nom;
            }
            for (int colonne = 7; colonne >= limitemoins; colonne--) {
                plateau[ligne][colonne] = TousLesPions[1].nom;
            }
            if (ligne % 2 != 0 && limitemoins >= 0) {
                limitemoins--;
            }
            if (ligne % 2 == 0) {
                limiteplus++;
            }
        }
    }
    limitemoins = 7;
    limiteplus = 7;
    for (int ligne = 16; ligne >= 0; ligne--) {
        // Structure de base pyramide basse
        if (ligne > 3) {
            for (int colonne = 7; colonne <= limiteplus; colonne++) {
                plateau[ligne][colonne] = TousLesPions[1].nom;
            }
            for (int colonne = 7; colonne >= limitemoins; colonne--) {
                plateau[ligne][colonne] = TousLesPions[1].nom;
            }
            if (ligne % 2 != 0 && limitemoins >= 0) {
                limitemoins--;
            }
            if (ligne % 2 == 0) {
                limiteplus++;
            }
        }
    }
}

void affichagePlateau(char plateau[][14]) {
    system("cls");
    for (int ligne = 0; ligne < 17; ligne++) {
        for (int colonne = 0; colonne < 14; colonne++) {
            if (ligne % 2 == 0) {
                printf(" %c", plateau[ligne][colonne]);
            }
            if (ligne % 2 != 0) {
                printf("%c ", plateau[ligne][colonne]);
            }
        }
        printf("\n");
    }
}

int main() {
    char plateau[17][14];
    pion TousLesPions[65];
    initPions(TousLesPions);
    initPlateau(plateau, TousLesPions);
    affichagePlateau(plateau);
}

/*************** POUBELLE DE CODE **************/
//void initPlateau(char plateau[][25]) {
//	for (int i = 0; i < 12; i++) {
//		plateau[0][i] = ' ';
//	}
//	plateau[0][12] = 'A';
//	for (int i = 13; i < 25; i++) {
//		plateau[0][i] = ' ';
//	}
//	// -> ____________A____________
//	for (int i = 0; i < 11; i++) {
//		plateau[1][i] = ' ';
//	}
//	plateau[1][11] = 'A';
//	plateau[1][12] = ' ';
//	plateau[1][13] = 'A';
//	for (int i = 14; i < 25; i++) {
//		plateau[1][i] = ' ';
//	}
//	// -> ____________A____________
//	// -> ___________A A___________
//	for (int i = 0; i < 10; i++) {
//		plateau[2][i] = ' ';
//	}
//	plateau[2][10] = 'A';
//	plateau[2][11] = ' ';
//	plateau[2][12] = 'A';
//	plateau[2][13] = ' ';
//	plateau[2][14] = 'A';
//	for (int i = 15; i < 25; i++) {
//		plateau[2][i] = ' ';
//	}
//	// -> ____________A____________
//	// -> ___________A A___________
//	// -> __________A A A _________
//	for (int i = 0; i < 9; i++) {
//		plateau[3][i] = ' ';
//	}
//	plateau[3][9] = 'A';
//	plateau[3][10] = ' ';
//	plateau[3][11] = 'A';
//	plateau[3][12] = ' ';
//	plateau[3][13] = 'A';
//	plateau[3][14] = ' ';
//	plateau[3][15] = 'A';
//	for (int i = 16; i < 25; i++) {
//		plateau[3][i] = ' ';
//	}
//	// -> ____________A____________
//	// -> ___________A A___________
//	// -> __________A A A _________
//	// -> _________A A A A_________
//}
