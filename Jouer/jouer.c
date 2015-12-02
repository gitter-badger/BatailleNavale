#include "include/Grille.h"
#include "TorpilleurDeplacer.h"
#include "TorpilleurChoisir.h"
#include "TorpilleurAttaquer.h"
#include <stdio.h>
#include <stdlib.h>


void Jouer_init_temporaire(int *eJoueur){
	*eJoueur = 1;
	Grille_init();
	Grille_ecrire_torpilleur(5,5, *eJoueur, Present);
	Grille_ecrire_torpilleur(7,7, *eJoueur, Present);
	Grille_ecrire_obstacle(7,6, *eJoueur, Oui);
	Grille_ecrire_obstacle(5,5, 2, Oui);
}

void Jouer_Choisir(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur){
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur);
	Jouer_Afficher_Torpilleur(pcTorpilleur);
	Jouer_Selectionner_Torpilleur(peNumero_Torpilleur);
	Jouer_Afficher_Torpilleur_Selectionne(*peNumero_Torpilleur);
}

void Jouer_Deplacer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur){
	t_direction dDirection;
	int bValide = 0;
	while(!bValide){
		Jouer_Choisir_Direction(&dDirection);
		bValide = Jouer_Deplacement_Valide(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur);
		//printf("\n bValide =%i", bValide);
		if(!bValide){
			printf("\nDirection invalide (Presence d'un torpilleur ou d'un obstacle)");
		}
	}
	Jouer_Deplacer_Torpilleur(eJoueur,dDirection,*peNumero_Torpilleur, pcTorpilleur);
	Jouer_Trouver_Torpilleur(eJoueur, pcTorpilleur);
	Jouer_Afficher_Torpilleur(pcTorpilleur);
}

void Jouer_Attaquer(int eJoueur,t_coordonnee *pcTorpilleur,int *peNumero_Torpilleur){
	t_portee gPortee[N][M];
	t_coordonnee cCurseur;
	int bAttaque_Possible;
	int bValiderCurseur;
	int eJoueurAdverse;
	if(eJoueur == 1){
		eJoueurAdverse = 2;
	}
	else {
		eJoueurAdverse = 1;
	}
	
	Jouer_Calculer_Portee(eJoueur, pcTorpilleur, *peNumero_Torpilleur, gPortee); // /!\Limites !!!!
	Jouer_Afficher_Portee(gPortee);
	bAttaque_Possible = Jouer_Attaque_Possible(gPortee);
	if(bAttaque_Possible){
		Jouer_Init_Curseur(gPortee, &cCurseur);
		printf("\nbAttaque_Possible, cCurseur : x = %i y = %i", cCurseur.x+1, cCurseur.y+1);
		while(!bValiderCurseur){
			Jouer_Deplacer_Curseur(gPortee, &cCurseur);
			printf("\nbAttaque_Possible, cCurseur : x = %i y = %i", cCurseur.x+1, cCurseur.y+1);
			printf("\nValider curseur :");
			scanf("%i", &bValiderCurseur);
		}
		Grille_ecrire_toucher(cCurseur.x,cCurseur.y, eJoueurAdverse, Oui);
		
	}
	else{
		printf("\nAttaque impossible va te faire foutre HAHAHAHAHAH");
	}
}

int main(){
	int eJoueur;	//Temporaire
	Jouer_init_temporaire(&eJoueur);

	t_coordonnee cTorpilleur[N_Torpilleur];
	int eNumero_Torpilleur;


	Jouer_Choisir(eJoueur, cTorpilleur, &eNumero_Torpilleur);
	Jouer_Deplacer(eJoueur, cTorpilleur, &eNumero_Torpilleur);
	Jouer_Attaquer(eJoueur, cTorpilleur, &eNumero_Torpilleur);
	printf("\n");
	
	return 1;
}
