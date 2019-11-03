#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h> // Pour pouvoir utiliser sin() et cos()
#include "Librairie/GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "Librairie/BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "hchevaux.h"


// Largeur et hauteur par defaut d'une image correspondant a nos criteres
#define LargeurFenetre 1863
#define HauteurFenetre 895

/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement);

int main(int argc, char **argv)
{
	initialiseGfx(argc, argv);
	
	prepareFenetreGraphique("GfxLib", LargeurFenetre, HauteurFenetre);
	
	/* Lance la boucle qui aiguille les evenements sur la fonction gestionEvenement ci-apres,
		qui elle-meme utilise fonctionAffichage ci-dessous */

	lanceBoucleEvenements();
	 
	return 0;
}


/* La fonction de gestion des evenements, appelee automatiquement par le systeme
des qu'une evenement survient */
void gestionEvenement(EvenementGfx evenement)
{
	static bool pleinEcran = false; // Pour savoir si on est en mode plein ecran ou pas

	static pion p;
	static pion rep[16];

	static cases c;
	static cases enclosLicorne[4];
	static cases enclosSirene[4];
	static cases enclosDragon[4];
	static cases enclosHP[4];
	static cases plateau[52];

	static image i;

	static des d;

	static gere g;

	static portail po;

	static int abs=0;
	static int ord=0;	
	abs=abscisseSouris();
	ord=ordonneeSouris();
	static int stade=0;
	static int player=0;
	static int play=0;
	static int moment=0;
	static int peut=0;

	static int affiche;

	switch (evenement)
	{
		case Initialisation:
			srand(time(NULL));

			initStructPion(rep);
			initStructPlateau(plateau);
			i = initStructImage(i);
			initStructEnclosLicorne(enclosLicorne,rep);
			initStructEnclosSirene(enclosSirene,rep);
			initStructEnclosDragon(enclosDragon,rep);
			initStructEnclosHP(enclosHP,rep);
			
			po = initStructPortail(po);

			d = initStructDes(d);

			// Configure le systeme pour generer un message Temporisation
			// toutes les 20 millisecondes
			demandeTemporisation(20);
			break;
		
		case Temporisation:
		  
			rafraichisFenetre();
			break;
			
		case Affichage:
			
			

			// On part d'un fond d'ecran gris
			effaceFenetre (200, 200, 200);
			plateauDeJeu();
			po = animationPortail(po);//À FAIRE AVEC LE CHRONO
			//METTRE LA PAGE DE GARDE
			if (stade == 0) stade = 1;
			else if (stade == 1) option(g,i,rep);
			else if (stade == 2) 
			{
				
				placementEnclosLicorne(enclosLicorne,i,rep);
				placementEnclosSirene(enclosSirene,i,rep);
				placementEnclosDragon(enclosDragon,i,rep);
				placementEnclosHP(enclosHP,i,rep);
				boutons(&player);
				d = lancementDes(abs,ord,d,&player,&play,peut,rep,g,plateau,i);
				affichePionPlateau(i,rep,plateau);
			}

			


			


			break;
			
		case Clavier:
			printf("%c : ASCII %d\n", caractereClavier(), caractereClavier());

			switch (caractereClavier())
			{
				case 'Q': /* Pour sortir quelque peu proprement du programme */
				case 'q':
					
					termineBoucleEvenements();

					break;

				case 'F':
				case 'f':
					pleinEcran = !pleinEcran; // Changement de mode plein ecran
					if (pleinEcran)
						modePleinEcran();
					else
						redimensionneFenetre(LargeurFenetre, HauteurFenetre);
					break;

				case 'R':
				case 'r':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 20 millisecondes (rapide)
					demandeTemporisation(20);
					break;

				case 'L':
				case 'l':
					// Configure le systeme pour generer un message Temporisation
					// toutes les 100 millisecondes (lent)
					demandeTemporisation(100);
					break;

				case 'S':
				case 's':
					// Configure le systeme pour ne plus generer de message Temporisation
					demandeTemporisation(-1);
					break;
			}
			break;
			
		case ClavierSpecial:
			printf("ASCII %d\n", toucheClavier());
			break;

		case BoutonSouris:
			
			
			
			if (etatBoutonSouris() == GaucheAppuye)
			{
				//printf("Bouton gauche appuye en : (%d, %d)\n", abscisseSouris(), ordonneeSouris());

				if (stade == 2 && (d.appuyer == 1 || d.rejoue == 1)) d = gereClicDes(abs,ord,d);
				if (stade == 1) 
				{
					g = gereClicJoueur(abs,ord,g,&player);
					g = gereClicChoix(abs,ord,g);
					if (g.clicJ >=2 ) g = gereClicAnimal(abs,ord,g,rep,&stade);
				}

				if (stade == 2)
				{
					gereClicSortir(abs,ord,d,rep,&player,&play,enclosLicorne,enclosSirene,enclosDragon,enclosHP,plateau);
					choixDuPion(rep,plateau,abs,ord);

				}


			}
				
				break;
		
		case Souris: // Si la souris est deplacee
			break;
		
		case Inactivite: // Quand aucun message n'est disponible
			break;
		
		case Redimensionnement: // La taille de la fenetre a ete modifie ou on est passe en plein ecran
			// Donc le systeme nous en informe
			printf("Largeur : %d\n", largeurFenetre());
			printf("Hauteur : %d\n", hauteurFenetre());
			break;
	}
}

