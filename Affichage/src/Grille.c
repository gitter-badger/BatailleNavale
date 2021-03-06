#include <stdio.h>
#include <stdlib.h>
#include "Grille.h"
#include "Struct.h"
#include "Outil.h"

t_plateau grille; //structure qui prend 2 grille

void Grille_init(){
    int i, j;
    for(i = 0; i <= N; i++){
        for(j = 0; j <= M; j++){
            Grille_ecrire_bateau(i,j, 1, Aucun_b);
            Grille_ecrire_toucher(i,j, 1,Non);
            Grille_ecrire_obstacle(i,j,1,Aucun_o);
	    Grille_ecrire_torpilleur(i,j,1,Aucun_t);
            Grille_ecrire_bateau(i,j, 2, Aucun_b);
            Grille_ecrire_toucher(i,j, 2,Non);
            Grille_ecrire_obstacle(i,j,2,Aucun_o);
	    Grille_ecrire_torpilleur(i,j,2,Aucun_t);
        }
    }
}

void Grille_lire_case(int i, int j, int num_grille,t_case *pEnsemble){
    int ab=(pEnsemble)->bateau;
    int cd=(pEnsemble)->toucher;
    int bg=(pEnsemble)->obstacle;
    int ap=(pEnsemble)->torpilleur;
    Grille_lire_bateau(i,j, num_grille,&ab);
    Grille_lire_toucher(i,j, num_grille,&cd);
    Grille_lire_obstacle(i,j,num_grille,&bg);
    Grille_lire_torpilleur(i,j,num_grille,&ap);
}

void Grille_ecrire_case(int i, int j, int num_grille,t_case ensemble[N][M]){
    Grille_ecrire_bateau(i,j, num_grille, ensemble[i][j].bateau);
    Grille_ecrire_toucher(i,j, num_grille,ensemble[i][j].toucher);
    Grille_ecrire_obstacle(i,j,num_grille,ensemble[i][j].obstacle);
    Grille_ecrire_torpilleur(i,j,num_grille,ensemble[i][j].torpilleur);

}

void Grille_lire_bateau(int i,int j, int num_grille,int *peResultat){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].bateau;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].bateau;
        }

    }

}


void Grille_lire_toucher(int i,int j, int num_grille,int *peResultat){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].toucher;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].toucher;
        }

    }
}


void Grille_lire_obstacle(int i,int j, int num_grille,int *peResultat){

    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].obstacle;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].obstacle;
        }
    }
}

void Grille_lire_torpilleur(int i,int j, int num_grille,int *peResultat){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(num_grille==1)*peResultat=grille.grille1[i][j].torpilleur;
            else if(num_grille==2)*peResultat=grille.grille2[i][j].torpilleur;
        }

    }
}


void Grille_ecrire_bateau(int i,int j, int num_grille, t_bateau choix){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
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
    if(i>=0 && i<=N && j>=0 && j<=M){
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
    if(i>=0 && i<=N && j>=0 && j<=M){
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


void Grille_ecrire_torpilleur(int i,int j, int num_grille,t_torpilleur choix){
    if(i>=0 && i<=N && j>=0 && j<=M){
        if(bCroit(1,num_grille,2)){
            if(choix==Aucun_t){
                if(num_grille==1)grille.grille1[i][j].torpilleur=Aucun_t;
                else if(num_grille==2)grille.grille2[i][j].torpilleur=Aucun_t;
            }
            else if(choix==Present){
                if(num_grille==1)grille.grille1[i][j].torpilleur=Present;
                else if(num_grille==2)grille.grille2[i][j].torpilleur=Present;
            }
        }
    }
}
