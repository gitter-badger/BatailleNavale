#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Struct.h"
#include "Outil.h"

t_case grille1[N][M];
t_case grille2[N][M];

t_plateau grille; //structure qui prend 2 grille

void Grille_init(){
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			Grille_ecrire_bateau(i,j, 1, Aucun_b);
			Grille_ecrire_toucher(i,j, 1,Non);
			Grille_ecrire_obstacle(i,j,1,Aucun_o);
			Grille_ecrire_bateau(i,j, 2, Aucun_b);
			Grille_ecrire_toucher(i,j, 2,Non);
			Grille_ecrire_obstacle(i,j,2,Aucun_o);
		}
	}
}

void Grille_lire_case(int i, int j, int num_grille,t_case ensemble[N][M]){
	Grille_lire_bateau(i,j, num_grille,ensemble[i][j].bateau);
	Grille_lire_toucher(i,j, num_grille,ensemble[i][j].toucher);
	Grille_lire_obstacle(i,j,num_grille,ensemble[i][j].obstacle);
}

void Grille_ecrire_case(int i, int j, int num_grille,t_case ensemble[N][M]){
	Grille_ecrire_bateau(i,j, num_grille, ensemble[i][j].bateau);
	Grille_ecrire_toucher(i,j, num_grille,ensemble[i][j].toucher);
	Grille_ecrire_obstacle(i,j,num_grille,ensemble[i][j].obstacle);

}

void Grille_lire_matrice(int num_grille,t_case Case[N][M]){
	int i,j;
	if(bCroit(1,num_grille,2)){

		if(num_grille==1){
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					Grille_lire_case(i,j,num_grille,Case);
				}
			}
		}else if(num_grille==2){
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					Grille_lire_case(i,j,num_grille,Case);
				}
			}
		}
	}
}

void Grille_ecrire_matrice(int num_grille,t_case Case[N][M]){
	int i,j;
	if(bCroit(1,num_grille,2)){
		if(num_grille==1){
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					Grille_ecrire_case(i,j,num_grille,Case);
				}
			}
		}else if(num_grille==2){
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					Grille_ecrire_case(i,j,num_grille,Case);
				}
			}
		}
	}
}

void Grille_lire_bateau(int i,int j, int num_grille,int resultat){
	if(i>0 && i<=N && j>0 && j<=M){
		if(bCroit(1,num_grille,2)){
				if(num_grille==1)resultat=grille.grille1[i][j].bateau;
				else if(num_grille==2)resultat=grille.grille2[i][j].bateau;
        }

    }
}


void Grille_lire_toucher(int i,int j, int num_grille,int resultat){
	if(i>0 && i<=N && j>0 && j<=M){
		if(bCroit(1,num_grille,2)){
				if(num_grille==1)resultat=grille.grille1[i][j].toucher;
				else if(num_grille==2)resultat=grille.grille2[i][j].toucher;
        }

    }
}


void Grille_lire_obstacle(int i,int j, int num_grille,int resultat){

	if(i>0 && i<=N && j>0 && j<=M){
		if(bCroit(1,num_grille,2)){
				if(num_grille==1)resultat=grille.grille1[i][j].obstacle;
				else if(num_grille==2)resultat=grille.grille2[i][j].obstacle;
		}
	}
}



void Grille_ecrire_bateau(int i,int j, int num_grille, t_bateau choix){
	if(i>0 && i<=N && j>0 && j<=M){
		if(bCroit(1,num_grille,2)){
			if(choix==Torpilleur){
				if(num_grille==1)grille.grille1[i][j].bateau=Torpilleur;
				else if(num_grille==2)grille.grille2[i][j].bateau=Torpilleur;
			}
			if(choix==Sous_Marin){
				if(num_grille==1)grille.grille1[i][j].bateau=Sous_Marin;
				else if(num_grille==2)grille.grille2[i][j].bateau=Sous_Marin;
			}
			if(choix==Destroyer){
				if(num_grille==1)grille.grille1[i][j].bateau=Destroyer;
				else if(num_grille==2)grille.grille2[i][j].bateau=Destroyer;
			}
			if(choix==Porte_Avion){
				if(num_grille==1)grille.grille1[i][j].bateau=Porte_Avion;
				else if(num_grille==2)grille.grille2[i][j].bateau=Porte_Avion;
			}
			else if(choix==Aucun_b){
				if(num_grille==1)grille.grille1[i][j].bateau=Aucun_b;
				else if(num_grille==2)grille.grille2[i][j].bateau=Aucun_b;
			}
		}
	}
}

void Grille_ecrire_toucher(int i,int j, int num_grille,t_toucher choix){
	if(i>0 && i<=N && j>0 && j<=M){
		if(bCroit(1,num_grille,2)){
			if(choix==Oui){
				if(num_grille==1)grille.grille1[i][j].toucher=Oui;
				else if(num_grille==2)grille.grille2[i][j].toucher=Oui;
			}
			else if(choix==Non){
				if(num_grille==1)grille.grille1[i][j].toucher=Non;
				else if(num_grille==2)grille.grille2[i][j].toucher=Non;
			}
		}
	}
}

void Grille_ecrire_obstacle(int i,int j, int num_grille,t_obstacle choix){
	//Assert1("Numero grille",num_grille==1);
	//Assert1("Numero grille",num_grille==2);
	if(i>0 && i<=N && j>0 && j<=M){
		if(bCroit(1,num_grille,2)){
			if(choix==Obstacle){
				if(num_grille==1)grille.grille1[i][j].obstacle=Obstacle;
				else if(num_grille==2)grille.grille2[i][j].obstacle=Obstacle;
			}
			else if(choix==Aucun_o){
				if(num_grille==1)grille.grille1[i][j].obstacle=Aucun_o;
				else if(num_grille==2)grille.grille2[i][j].obstacle=Aucun_o;
			}
		}
	}

}