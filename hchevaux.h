#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "time.h"
#include "string.h"

#define cote 50


typedef struct PION
{
	int numero; //4 pions par joueurs, soit 16 pions 
	int animal; //1=licorne, 2=Sirene, 3=Dragon, 4=HP
	int etatJ; // etat : 0=enclos, 1=vient de sortir (case intiale), 2=se balade sur le plateau, 3=dernière ligne droite, 4=gagné
	int joueur; //4 joueurs : 1 à 4
	int possible; //0=etat neutre, 1=click lancer les dés activés, 2=click sur un pion
	int position; // 1000=enclos, 0 à 51= plateau, 100/200/300/400/500=ligne finale
}pion;

typedef struct CASE
{
	int number; 
	int etatC; // 0=libre, 1=occupée
	int x; 
	int y;
	int couleur; //1=cercle rouge(miam), 2=cercle bleu (libre) //FAIRE UNE FONCTION QUI AFFICHE LES CERCLES DE COULEUR
	pion p;
}cases;

typedef struct IMAGE
{
	DonneesImageRGB *licorne1 ;
	DonneesImageRGB *licorne2 ;
	DonneesImageRGB *licorne3 ;
	DonneesImageRGB *licorne4 ;

	DonneesImageRGB *HP1 ;
	DonneesImageRGB *HP2 ;
	DonneesImageRGB *HP3 ;
	DonneesImageRGB *HP4 ;
	DonneesImageRGB *HP5 ;


	DonneesImageRGB *sirene1 ;
	DonneesImageRGB *sirene2 ;
	DonneesImageRGB *sirene3 ;
	DonneesImageRGB *sirene4 ;

	DonneesImageRGB *dragon1 ;
	DonneesImageRGB *dragon2 ;
	DonneesImageRGB *dragon3 ;
	DonneesImageRGB *dragon4 ;
}image;


static struct COORDONNEES
{
	int x,y;
}Coord[] = {
				{520,60},
				{570,110},
				{620,160},
				{670,210},
				{720,260},
				{770,310},
				{820,360},
				{870,410},
				{920,460},
				{970,510},
				{1020,560},
				{1070,610},
				{1120,660},
				{1170,710},
				{1220,760},
				{1270,810}
			};

typedef struct PORTAIL
{
	int r,b,j,v;
}portail;


typedef struct DES
{
	DonneesImageRGB *des1 ;
	DonneesImageRGB *des2 ;
	DonneesImageRGB *des3 ;
	DonneesImageRGB *des4 ;
	DonneesImageRGB *des5 ;
	DonneesImageRGB *des6 ;
	int appuyer; /* 0=chgmt de joueur s'effectue et passe alors à 1, 
					1=le joueur peut cliquer sur lancer les dés, 
					2=le joueur a lancé les dès 
					3=les dés s'affiche alors à l'écran -> le joueur peut ainsi cliquer sur un pion*/
	int desA;
	int go; //1=le joueur a la possibilité de sortir un cheval car il a fait 6
	int rejoue; //0=ne peut pas relancer le des, 1=peut relancer le des
}des;


typedef struct GERECLIC
{
	int nombreJ;
	int clicJ;
	/*
		g.clicJ = 1 : choix nb joueur
	g.clicJ = 2 : joueur 1
	g.clicJ = 3 : joueur 2
	g.clicJ = 4 : joueur 3
	g.clicJ = 5 : joueur 4
	*/
	int menu;
	int next;
}gere;



void initStructPion(pion rep[16]);
image initStructImage(image i);
void initStructEnclosLicorne(cases enclosLicorne[4], pion rep[16]);
void initStructEnclosSirene(cases enclosSirene[4], pion rep[16]);
void initStructEnclosDragon(cases enclosDragon[4], pion rep[16]);
void initStructEnclosHP(cases enclosHP[4], pion rep[16]);
void initStructPlateau(cases plateau[52]);


des initStructDes(des d);
des lancementDes(int abs,int ord,des d,int *player,int *play,int peut,pion rep[16],gere g,cases plateau[52],image i); //EN COURS
void affichageDes(int abs, int ord,des d);
des gereClicDes(int abs, int ord,des d);
void gereClicSortir(int abs, int ord, des d,pion rep[16], int *player,int *play,cases enclosLicorne[4],cases enclosSirene[4],cases enclosDragon[4],cases enclosHP[4],cases plateau[52]); 		///EN COURS



void plateauDeJeu(void);
void boutons(int *player);
gere initStructGERECLIC(gere g);
void option(gere g,image i,pion rep[16]);
gere gereClicChoix(int abs, int ord, gere g);
gere gereClicJoueur(int abs, int ord,gere g,int *player);   
gere gereClicAnimal(int abs, int ord, gere g, pion rep[16],int *stade);
void placementEnclosLicorne(cases enclosLicorne[4],image i, pion rep[16]); 
void placementEnclosSirene(cases enclosSirene[4],image i, pion rep[16]);
void placementEnclosDragon(cases enclosDragon[4],image i, pion rep[16]);
void placementEnclosHP(cases enclosHP[4],image i, pion rep[16]);

void choixDuPion(pion rep[16], cases plateau[52],int abs, int ord);
int testDeplacementPlateau(cases plateau[52],pion rep[16],des d,int *player,int *play,int peut); 	
des deplacementPion(des d,pion rep[16],cases plateau[52],int *play); 	//A FAIRE EN PREMIER
void affichePionPlateau(image i,pion rep[16],cases plateau[52]);  
des tourJoueur(pion rep[16],int *player,gere g,des d);
void identifieJoueur(int *play, int *player, pion rep[16]);


//COMPRENDRE PK IL Y A QUE UN PION QUI PEUT S'AFFICHER



portail animationPortail(portail p);
portail initStructPortail(portail p);

