#ifndef GRILLE
#define GRILLE
#define N 10
#define M 10
#include "Struct.h"
void Grille_init();
void Grille_lire_case(int i, int j, int num_grille,t_case *pEnsemble);
void Grille_ecrire_case(int i, int j, int num_grille,t_case ensemble[N][M]);
void Grille_lire_bateau(int i,int j, int num_grille,int *peResultat);
void Grille_lire_toucher(int i,int j, int num_grille,int *peResultat);
void Grille_lire_obstacle(int i,int j, int num_grille,int *peResultat);
void Grille_lire_torpilleur(int i,int j, int num_grille,int *peResultat);
void Grille_ecrire_bateau(int i,int j, int num_grille, t_bateau choix);
void Grille_ecrire_toucher(int i,int j, int num_grille,t_toucher choix);
void Grille_ecrire_obstacle(int i,int j, int num_grille,t_obstacle choix);
void Grille_ecrire_torpilleur(int i,int j, int num_grille,t_torpilleur choix);

#endif
