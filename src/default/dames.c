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
}joueurs;

// On définit une couleur juste avant de printf quelque chose
void Couleur(int couleurDuTexte, int couleurDeFond) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDeFond * 16 + couleurDuTexte);
}

// On demande le nombre de joueurs et leur pseudo
int AskJoueur() {
    int rep;
    do {
        printf("\n\nNombre de joueurs = ");
        scanf("%i", &rep);
        switch (rep) {
            case 2:
            // Commence le jeu avec 2J
                system("cls");
                return 2;
            case 4:
            // Commence le jeu avec 4J
                system("cls");
                return 4;
            case 6:
            // Commence le jeu avec 6J
                system("cls");
                return 6;
            default:
                system("cls");
                printf("Il n'est pas possible de jouer avec %i joueurs...", rep);
                break;
        }
    } while (rep != 2 || rep != 4 || rep != 6);
    return 0; // Obligé de mettre un return ici car c'est une int, mais en théorie ça return forcément la valeur joueurs
}

// On demande le nom des joueurs n, pour plus de customisation
void NomJoueur(int NBekip[], joueurs j[]) {
    // Joueur 1
    printf("Nom du ");
    Couleur(2, 0);
    printf("Joueur 1");
    Couleur(7, 0);
    printf(" : ");
    fgets(j[1].nom, sizeof(j[1].nom), stdin);
    fgets(j[1].nom, sizeof(j[1].nom), stdin); // On doit remettre la même commande, sinon... elle ne s'exécute pas la première fois. Bug ?
    // Joueur 2
    printf("\nNom du ");
    Couleur(14, 0);
    printf("Joueur 2");
    Couleur(7, 0);
    printf(" : ");
    fgets(j[2].nom, sizeof(j[2].nom), stdin);
    if (NBekip[0] >= 4) {
        // Joueur 3
        printf("\nNom du ");
        Couleur(9, 0);
        printf("Joueur 3");
        Couleur(7, 0);
        printf(" : ");
        fgets(j[3].nom, sizeof(j[3].nom), stdin);
        // Joueur 4
        printf("\nNom du ");
        Couleur(12, 0);
        printf("Joueur 4");
        Couleur(7, 0);
        printf(" : ");
        fgets(j[4].nom, sizeof(j[4].nom), stdin);
    }
    if (NBekip[0] == 6) {
        // Joueur 5
        printf("\nNom du ");
        Couleur(6, 0);
        printf("Joueur 5");
        Couleur(7, 0);
        printf(" : ");
        fgets(j[5].nom, sizeof(j[5].nom), stdin);
        // Joueur 6
        printf("\nNom du ");
        Couleur(13, 0);
        printf("Joueur 6");
        Couleur(7, 0);
        printf(" : ");
        fgets(j[6].nom, sizeof(j[6].nom), stdin);
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

    TousLesPions[3].ekip = 1;
    TousLesPions[3].nom = '2';
    TousLesPions[3].ligne = 1;
    TousLesPions[3].colonne = 8;

    TousLesPions[4].ekip = 1;
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

    TousLesPions[13].ekip = 2;
    TousLesPions[13].nom = '2';
    TousLesPions[13].ligne = 15;
    TousLesPions[13].colonne = 8;

    TousLesPions[14].ekip = 2;
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

    TousLesPions[19].ekip = 2;
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

    TousLesPions[23].ekip = 3;
    TousLesPions[23].nom = '5';
    TousLesPions[23].ligne = 4;
    TousLesPions[23].colonne = 3;

    TousLesPions[24].ekip = 3;
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

    TousLesPions[33].ekip = 4;
    TousLesPions[33].nom = '2';
    TousLesPions[33].ligne = 12;
    TousLesPions[33].colonne = 12;

    TousLesPions[34].ekip = 4;
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
    TousLesPions[39].colonne = 11;

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

    TousLesPions[43].ekip = 5;
    TousLesPions[43].nom = '2';
    TousLesPions[43].ligne = 4;
    TousLesPions[43].colonne = 12;

    TousLesPions[44].ekip = 5;
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
    TousLesPions[49].colonne = 11;

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

// On place les pions dans le plateau pour chaque tour (pas un init, il doit être exécuté à chaque tour pour update les pions)
void tickPlateau(char plateau[][14], pions TousLesPions[], int NBekip[]) {
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
    for (int ligne = 0; ligne < 20; ligne++) {
        for (int colonne = 0; colonne < 20; colonne++) {
            for (int a = 0; a < 64; a++) {
                if (TousLesPions[a].ligne == ligne && TousLesPions[a].colonne == colonne && TousLesPions[a].ekip <= NBekip[0] && TousLesPions[a].ekip > 0) plateau[ligne][colonne] = TousLesPions[a].nom;
            }
        }
    }
}

// On affiche le plateau et, pendant l'affichage, on met de la couleur sur les pions des joueurs
void affichagePlateau(char plateau[][14], pions TousLesPions[]) {
    system("cls");
    for (int ligne = 0; ligne < 17; ligne++) {
        for (int colonne = 0; colonne < 14; colonne++) {
            if (ligne % 2 == 0) {
                // Assignation des couleurs des pions (lignes paires)
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
                // Assignation des couleurs des pions (lignes impaires)
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

// Façon miséreuse de bien assigner bledard, c rien c le bled (transformation des entiers en char)
char lavoiddubledard(char bledard, int pionchoisi) {
    if (pionchoisi == 0) bledard = '0';
    if (pionchoisi == 1) bledard = '1';
    if (pionchoisi == 2) bledard = '2';
    if (pionchoisi == 3) bledard = '3';
    if (pionchoisi == 4) bledard = '4';
    if (pionchoisi == 5) bledard = '5';
    if (pionchoisi == 6) bledard = '6';
    if (pionchoisi == 7) bledard = '7';
    if (pionchoisi == 8) bledard = '8';
    if (pionchoisi == 9) bledard = '9';
    if (pionchoisi == 10) bledard = 'n';
    return bledard;
}

// On vérifie les déplacements possibles autour du pion
void verifdeplacement(pions TousLesPions[], char plateau[][14], int pionchoisi, int pionsjouable[], int check[], char bledard, int ekip[]) {
    //check[0]-> NO | check[1]-> SO |check[2]-> O |check[3]-> E |check[4]-> NE |check[5]-> SE
    int dplON = 0;
    if (bledard == 'n') {
        for(int a = 0; a < 10; a++) {
            pionsjouable[a] = 0;
        }
    }
    for(int a = 1; a < 61; a++) {
        dplON = 0;
        if ((TousLesPions[a].ekip == ekip[0] && TousLesPions[a].nom == bledard) || (TousLesPions[a].ekip == ekip[0] && bledard == 'n')) {
            for (int c = 0; c < 6; c++) {
                check[c] = 0;
            }
            if (TousLesPions[a].ligne % 2 == 0) {
                if (plateau[TousLesPions[a].ligne - 1][TousLesPions[a].colonne] == '.') check[0] = 1; //NO
                if (plateau[TousLesPions[a].ligne + 1][TousLesPions[a].colonne] == '.') check[1] = 1; //SO
                if (plateau[TousLesPions[a].ligne][TousLesPions[a].colonne - 1] == '.') check[2] = 1; //O
                if (plateau[TousLesPions[a].ligne][TousLesPions[a].colonne + 1] == '.') check[3] = 1; //E
                if (plateau[TousLesPions[a].ligne - 1][TousLesPions[a].colonne + 1] == '.') check[4] = 1; //NE
                if (plateau[TousLesPions[a].ligne + 1][TousLesPions[a].colonne + 1] == '.') check[5] = 1; //SE
            }
            if (TousLesPions[a].ligne % 2 !=0) {
                if (plateau[TousLesPions[a].ligne - 1][TousLesPions[a].colonne - 1] == '.') check[0] = 1; //NO
                if (plateau[TousLesPions[a].ligne + 1][TousLesPions[a].colonne - 1] == '.') check[1] = 1;//SO
                if (plateau[TousLesPions[a].ligne][TousLesPions[a].colonne - 1] == '.') check[2] = 1; //O
                if (plateau[TousLesPions[a].ligne][TousLesPions[a].colonne + 1] == '.') check[3] = 1; //E
                if (plateau[TousLesPions[a].ligne - 1][TousLesPions[a].colonne] == '.') check[4] = 1; //NE
                if (plateau[TousLesPions[a].ligne + 1][TousLesPions[a].colonne] == '.') check[5] = 1; //SE
            }
            if (bledard == 'n') {
                for (int b = 0; b < 6; b++) {
                    if (check[b] != 1) dplON++;
                }
                if (dplON != 6 && TousLesPions[a].nom == '0') pionsjouable[0] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '1') pionsjouable[1] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '2') pionsjouable[2] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '3') pionsjouable[3] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '4') pionsjouable[4] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '5') pionsjouable[5] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '6') pionsjouable[6] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '7') pionsjouable[7] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '8') pionsjouable[8] = 1;
                if (dplON != 6 && TousLesPions[a].nom == '9') pionsjouable[9] = 1;
            }
        }
    }
}

void deplacement(pions TousLesPions[], char plateau[][14], char bledard, int direction, int ekip[]) {
    int temp = 0; // temp sert à empêcher que la boucle se répète 2 fois
    //printf("bledard:%c, direction:%i\n",bledard,direction);
    for (int a = 1; a < 61; a++) {
        if (TousLesPions[a].nom == bledard && TousLesPions[a].ekip == ekip[0]) {
            //printf("nom:%c ekip:%i direction:%i\n",TousLesPions[a].nom,TousLesPions[a].ekip,direction);
            // Lignes impaires
            if (TousLesPions[a].ligne % 2 != 0 && temp == 0) {
                // NO
                if (direction == 1) {
                    TousLesPions[a].ligne = TousLesPions[a].ligne - 1;
                    TousLesPions[a].colonne = TousLesPions[a].colonne - 1;
                }
                // SO
                if (direction == 5) {
                    TousLesPions[a].ligne = TousLesPions[a].ligne + 1;
                    TousLesPions[a].colonne = TousLesPions[a].colonne - 1;
                }
                // O
                if (direction == 3) TousLesPions[a].colonne = TousLesPions[a].colonne - 1;
                // E
                if (direction == 4) TousLesPions[a].colonne = TousLesPions[a].colonne + 1;
                // NE
                if (direction == 2) TousLesPions[a].ligne = TousLesPions[a].ligne - 1;
                // SE
                if (direction == 6) TousLesPions[a].ligne = TousLesPions[a].ligne + 1;
                temp = 1;
            }
            // Lignes paires
            if (TousLesPions[a].ligne % 2 == 0 && temp == 0) {
                // NO
                if (direction == 1) TousLesPions[a].ligne = TousLesPions[a].ligne - 1;
                // SO
                if (direction == 5) TousLesPions[a].ligne = TousLesPions[a].ligne + 1;
                // O
                if (direction == 3) TousLesPions[a].colonne = TousLesPions[a].colonne - 1;
                // E
                if (direction == 4) TousLesPions[a].colonne = TousLesPions[a].colonne + 1;
                // NE
                if (direction == 2) {
                    TousLesPions[a].ligne = TousLesPions[a].ligne - 1;
                    TousLesPions[a].colonne = TousLesPions[a].colonne + 1;
                }
                // SE
                if (direction == 6) {
                    TousLesPions[a].ligne = TousLesPions[a].ligne + 1;
                    TousLesPions[a].colonne = TousLesPions[a].colonne + 1;
                }
                temp = 1;
            }
        }
    }
}

void choixdeplacement(char plateau[][14], pions TousLesPions[], int ekip[0]) {
    int direction = 7, pionchoisi = 10, cbon1 = 0, cbon2 = 0, check[6], pionsjouable[10];
    char temp[6], bledard;
    bledard = lavoiddubledard(bledard, pionchoisi);
    verifdeplacement(TousLesPions, plateau, pionchoisi, pionsjouable, check, bledard, ekip);
    do {
        do {
            printf("\nQuel pion faut-il d%cplacer ? ", 130);
            for (int a = 0; a < 10; a++) {
                if (pionsjouable[a] == 1) printf("| %i ", a);
            }
            printf("|\n");
            scanf("%i", &pionchoisi);
            if (pionchoisi > 9 || pionchoisi < 0) printf("Erreur de saisie\n");
            if (pionsjouable[pionchoisi] == 0) printf("Ce pion ne peut pas bouger\n");
            if ((pionchoisi < 9 || pionchoisi > 0) && (pionsjouable[pionchoisi] == 1)) {
                printf("Voulez-vous vraiment d%cplacer ce pion ? (1 pour continuer, 0 pour annuler)\n", 130);
                scanf("%i", &cbon1);
            }
            else cbon1 = 1;
        } while (cbon1 == 0);
    } while (pionchoisi > 9 || pionchoisi < 0 || pionsjouable[pionchoisi] == 0);
    bledard = lavoiddubledard(bledard, pionchoisi);
    verifdeplacement(TousLesPions, plateau, pionchoisi, pionsjouable, check, bledard, ekip);
    printf("Dans quelle direction voulez-vous jouer ?\n");
    // Les checks servent à afficher les positions où le pion peut se déplacer
    if (check[0] == 1) temp[0] = '1';
    else temp[0] = ' ';
    if (check[1] == 1) temp[1] = '5';
    else temp[1] = ' ';
    if (check[2] == 1) temp[2] = '3';
    else temp[2] = ' ';
    if (check[3] == 1) temp[3] = '4';
    else temp[3] = ' ';
    if (check[4] == 1) temp[4] = '2';
    else temp[4] = ' ';
    if (check[5] == 1) temp[5] = '6';
    else temp[5] = ' ';
    do {
        printf("%c/ \\%c\n%c - %c\n%c\\ /%c\n=> ", temp[0], temp[4], temp[2], temp[3], temp[1], temp[5]);
        scanf("%i", &direction);
        if (direction < 1 || direction > 6) printf("Erreur de saisie\n");
        else {
            if (check[0] == 0 && direction == 1) printf("D%cplacement impossible\n", 130);
            if (check[1] == 0 && direction == 5) printf("D%cplacement impossible\n", 130);
            if (check[2] == 0 && direction == 3) printf("D%cplacement impossible\n", 130);
            if (check[3] == 0 && direction == 4) printf("D%cplacement impossible\n", 130);
            if (check[4] == 0 && direction == 2) printf("D%cplacement impossible\n", 130);
            if (check[5] == 0 && direction == 6) printf("D%cplacement impossible\n", 130);
            //
            if (check[0] == 1 && direction == 1) cbon2 = 1;
            if (check[1] == 1 && direction == 5) cbon2 = 1;
            if (check[2] == 1 && direction == 3) cbon2 = 1;
            if (check[3] == 1 && direction == 4) cbon2 = 1;
            if (check[4] == 1 && direction == 2) cbon2 = 1;
            if (check[5] == 1 && direction == 6) cbon2 = 1;
        }
    } while (cbon2 == 0);
    bledard = lavoiddubledard(bledard, pionchoisi);
    deplacement(TousLesPions, plateau, bledard, direction, ekip);
}

void NomJoueurTour(int ekip[], joueurs j[]) {
    // Affichage du nom du joueur qui joue le tour, juste avant la question de quel pion jouer
    if (ekip[0] == 1) {
        printf("\nA vous de jouer, ");
        Couleur(2, 0);
        printf("%s", j[1].nom);
        Couleur(7, 0);
    }
    if (ekip[0] == 2) {
        printf("\nA vous de jouer, ");
        Couleur(14, 0);
        printf("%s", j[2].nom);
        Couleur(7, 0);
    }
    if (ekip[0] == 3) {
        printf("\nA vous de jouer, ");
        Couleur(9, 0);
        printf("%s", j[3].nom);
        Couleur(7, 0);
    }
    if (ekip[0] == 4) {
        printf("\nA vous de jouer, ");
        Couleur(12, 0);
        printf("%s", j[4].nom);
        Couleur(7, 0);
    }
    if (ekip[0] == 5) {
        printf("\nA vous de jouer, ");
        Couleur(6, 0);
        printf("%s", j[5].nom);
        Couleur(7, 0);
    }
    if (ekip[0] == 6) {
        printf("\nA vous de jouer, ");
        Couleur(13, 0);
        printf("%s", j[6].nom);
        Couleur(7, 0);
    }
}

int affectationVictoire(pions TousLesPions[]) {
    int win, resultEkip1 = 0, resultEkip2 = 0;
    // À voir pour simplifier le code au max, parce que c'est pas joli joli...
    // Check si les pions de l'équipe 1 se trouvent dans la base de l'équipe 2
    for (int ekip1 = 1; ekip1 < 11; ekip1++) {
        if (TousLesPions[ekip1].ligne > 12 && TousLesPions[ekip1].ligne < 17 && TousLesPions[ekip1].colonne > 5 && TousLesPions[ekip1].colonne < 10) resultEkip1++;
    }
    if (resultEkip1 == 9) return 1; // 1 car Equipe 1
    // Check si les pions de l'équipe 2 se trouvent dans la base de l'équipe 1
    for (int ekip2 = 11; ekip2 < 21; ekip2++) {
        if (TousLesPions[ekip2].ligne > -1 && TousLesPions[ekip2].ligne < 4 && TousLesPions[ekip2].colonne > 5 && TousLesPions[ekip2].colonne < 10) resultEkip2++;
    }
    if (resultEkip2 == 9) return 2; // 2 car Equipe 2
    // Si toujours pas de victoire, on garde win = 0
    return 0; 
}

void boucleJeu(char plateau[][14], pions TousLesPions[], int NBekip[], int ekip[], joueurs j[]) {
    int win = 0, retourmenu = 0, swich;
    do {
        ekip[0]++;
        if (ekip[0] > NBekip[0]) ekip[0] = 1;
        tickPlateau(plateau, TousLesPions, NBekip);
        affichagePlateau(plateau, TousLesPions);
        NomJoueurTour(ekip, j);
        /*printf("\nAfficher menu ? : oui=1 non=0\n");
        scanf("%i", &swich);
        switch (swich) {
            case 0:
                retourmenu = 0;
                break;
            case 1:
                retourmenu = 1;
                break;
            default:
                printf("Erreur de saisie\n");
                break;
        }
        // On joue le tour du n-ième joueur [si le joueur ne retourne pas au menu !!!]
        if (retourmenu == 0) */choixdeplacement(plateau, TousLesPions, ekip);
        win = affectationVictoire(TousLesPions);
    } while (win == 0 && retourmenu == 0);
    // Implémenter fin de partie (gg)
    if (win == 1) {
        printf("\nF%clicitations au loulou de l'%cquipe 1 pour sa victoire %ccrasante !\n", 130, 130, 130);
    }
    if (win == 2) {
        printf("\nF%clicitations au loulou de l'%cquipe 2 pour sa victoire %ccrasante !\n", 130, 130, 130);
    }
}

void Creationsauvegarde(pions TousLesPions[], int NBekip[], joueurs j[], int ekip[]) {
    FILE * sauvegarde; // sauvegarde est un pointeur de fichier
    sauvegarde = fopen("sauvegarde.esiee", "w");
    for (int a = 1; a < 61; a++) fprintf(sauvegarde, "%c %i %i %i\n", TousLesPions[a].nom, TousLesPions[a].ekip, TousLesPions[a].ligne, TousLesPions[a].colonne);
    fprintf(sauvegarde, "NBekip=%i tour=%i j1=%s j2=%s j3=%s j4=%s j5=%s j6=%s\n", NBekip[0], ekip[0], j[1].nom, j[2].nom, j[3].nom, j[4].nom, j[5].nom, j[6].nom);
    fclose(sauvegarde);
}

void Liresauvegarde(pions TousLesPions[], int NBekip[], joueurs j[], int ekip[]) {
    FILE * sauvegarde = NULL;
    sauvegarde = fopen("sauvegarde.esiee", "r");
    for (int a = 1; a < 61; a++) fscanf(sauvegarde, "%c %i %i %i\n", &TousLesPions[a].nom, &TousLesPions[a].ekip, &TousLesPions[a].ligne, &TousLesPions[a].colonne);
    fscanf(sauvegarde, "NBekip=%i tour=%i j1=%s j2=%s j3=%s j4=%s j5=%s j6=%s\n", &NBekip[0], &ekip[0], &j[1].nom, &j[2].nom, &j[3].nom, &j[4].nom, &j[5].nom, &j[6].nom);
    fclose(sauvegarde);
}

void menu(int NBekip[], pions TousLesPions[], char plateau[][14], int ekip[], int win, int EnCours[], int fin[], joueurs j[]) {
    int rep;
    do {
        printf("1. Nouvelle partie\n2. Charger une partie existante\n3. Quitter le jeu\n");
        if (EnCours[0] == 1) printf("4. Sauvegarder la partie\n5. Continuer la partie\n");
        printf("\n=> ");
        scanf("%i", &rep);
        switch (rep) {
            case 1:
                // Lancement du jeu
                system("cls");
                NBekip[0] = AskJoueur();
                NomJoueur(NBekip, j);
                boucleJeu(plateau, TousLesPions, NBekip, ekip, j);
                EnCours[0] = 1;
                break;
            case 2:
                // Charger une ancienne partie
                Liresauvegarde(TousLesPions, NBekip, j, ekip);
                boucleJeu(plateau, TousLesPions, NBekip, ekip, j);
                EnCours[0] = 1;
                //system("cls");
                break;
            case 3:
                // Fermer le jeu
                fin[0] = 1;
                break;
            case 4:
                // Sauvegarder la partie en cours
                Creationsauvegarde(TousLesPions, NBekip, j, ekip);
                break;
            case 5:
                // Continuer la partie
                boucleJeu(plateau, TousLesPions, NBekip, ekip, j);
                break;
            default:
                system("cls");
                printf("Erreur de saisie\n");
                break;
            }
        } while (rep < 1 || rep > 5 );
}

int main() {
	char plateau[17][14];
    pions TousLesPions[65];
    int NBekip[1], ekip[1], win = 0, fin[1], EnCours[1];
    joueurs j[7]; // 7 au lieu de 6 car flemme de dire que j[0] vaut le joueur 1
    ekip[0] = 0;
    // Menu
    system("cls");
    initPions(TousLesPions);
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
    do {
        if (EnCours[0] == 1) {
            system("cls");
            affichagePlateau(plateau, TousLesPions);
        }
        menu(NBekip, TousLesPions, plateau, ekip, win, EnCours, fin, j);
    } while (win != 1 && fin[0] != 1);
    // Reste des fonctions
    NomJoueur(NBekip, j);
    boucleJeu(plateau, TousLesPions, NBekip, ekip, j);
}
