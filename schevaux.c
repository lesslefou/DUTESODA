#include "hchevaux.h"
image initStructImage(image i)
{
	i.licorne1 = lisBMPRGB("pionLicorne1.bmp");
	i.licorne2 = lisBMPRGB("pionLicorne2.bmp");
	i.licorne3 = lisBMPRGB("pionLicorne3.bmp");
	i.licorne4 = lisBMPRGB("pionLicorne4.bmp");	

	i.HP1 = lisBMPRGB("pionHP1.bmp");
	i.HP2 = lisBMPRGB("pionHP2.bmp");
	i.HP3 = lisBMPRGB("pionHP3.bmp");
	i.HP4 = lisBMPRGB("pionHP4.bmp");
	i.HP5 = lisBMPRGB("pionHP5.bmp");

	i.sirene1 = lisBMPRGB("pionSirene1.bmp");
	i.sirene2 = lisBMPRGB("pionSirene2.bmp");
	i.sirene3 = lisBMPRGB("pionSirene3.bmp");
	i.sirene4 = lisBMPRGB("pionSirene4.bmp");

	i.dragon1 = lisBMPRGB("pionDragon1.bmp");
	i.dragon2 = lisBMPRGB("pionDragon2.bmp");
	i.dragon3 = lisBMPRGB("pionDragon3.bmp");
	i.dragon4 = lisBMPRGB("pionDragon4.bmp");

	return i;
}

void initStructPion(pion rep[16])
{
	for (int i=0; i<16; i++)
	{
		rep[i].numero = i+1;
		if (i<4) rep[i].animal = 1;
		else if (i>=4 && i<8) rep[i].animal = 2;
		else if (i>=8 && i<12) rep[i].animal = 3;
		else rep[i].animal = 4;

		rep[i].etatJ = 0;
		rep[i].joueur = 0; 
		rep[i].possible = 0;
		rep[i].position = 1000;
	}
}

void initStructEnclosLicorne(cases enclosLicorne[4], pion rep[16])
{
	for (int i=0; i<4; i++)
	{
		enclosLicorne[i].number = i+1;
		enclosLicorne[i].etatC = 1;
		enclosLicorne[i].p = rep[i];
	}

	enclosLicorne[0].x = Coord[4].x + 5;
	enclosLicorne[1].x = Coord[1].x + 5;
	enclosLicorne[2].x = Coord[1].x + 5;
	enclosLicorne[3].x = Coord[4].x + 5;

	enclosLicorne[0].y = Coord[1].y + 5;
	enclosLicorne[1].y = Coord[1].y + 5;
	enclosLicorne[2].y = Coord[4].y + 5;
	enclosLicorne[3].y = Coord[4].y + 5;
}

void initStructEnclosSirene(cases enclosSirene[4], pion rep[16])
{
	for (int i=0; i<4; i++)
	{
		enclosSirene[i].number = i+1;
		enclosSirene[i].etatC = 1;
		enclosSirene[i].p = rep[i+3];
	}

	enclosSirene[0].x = Coord[13].x + 5;
	enclosSirene[1].x = Coord[13].x + 5;
	enclosSirene[2].x = Coord[10].x + 5;
	enclosSirene[3].x = Coord[10].x + 5;

	enclosSirene[0].y = Coord[4].y + 5;
	enclosSirene[1].y = Coord[1].y + 5;
	enclosSirene[2].y = Coord[1].y + 5;
	enclosSirene[3].y = Coord[4].y + 5;
}

void initStructEnclosDragon(cases enclosDragon[4], pion rep[16])
{
	for (int i=0; i<4; i++)
	{
		enclosDragon[i].number = i+1;
		enclosDragon[i].etatC = 1;
		enclosDragon[i].p = rep[i+7];
	}
	enclosDragon[0].x = Coord[10].x + 5;
	enclosDragon[1].x = Coord[13].x + 5;
	enclosDragon[2].x = Coord[13].x + 5;
	enclosDragon[3].x = Coord[10].x + 5;

	enclosDragon[0].y = Coord[13].y + 5;
	enclosDragon[1].y = Coord[13].y + 5;
	enclosDragon[2].y = Coord[10].y + 5;
	enclosDragon[3].y = Coord[10].y + 5;
}

void initStructEnclosHP(cases enclosHP[4], pion rep[16])
{
	for (int i=0; i<4; i++)
	{
		enclosHP[i].number = i+1;
		enclosHP[i].etatC = 1;
		enclosHP[i].p = rep[i+11];
	}
	enclosHP[0].x = Coord[1].x + 5;
	enclosHP[1].x = Coord[1].x + 5;
	enclosHP[2].x = Coord[4].x + 5;
	enclosHP[3].x = Coord[4].x + 5;

	enclosHP[0].y = Coord[10].y + 5;
	enclosHP[1].y = Coord[13].y + 5;
	enclosHP[2].y = Coord[13].y + 5;
	enclosHP[3].y = Coord[10].y + 5;
}

void initStructPlateau(cases plateau[52])
{
	for (int i=0; i<52; i++)
	{
		plateau[i].number = i;
		plateau[i].etatC = 0;
		plateau[i].couleur = 0;
	}

	for (int j=0; j<6; j++)
	{
		plateau[j].x = Coord[6].x + 5; // case 0 à 5
		plateau[j].y = Coord[j].y + 5; // case 0 à 5
		plateau[j+6].x = Coord[j].x + 5; // case 6 à 11
		plateau[j+6].y = Coord[6].y + 5; // case 6 à 11		
		plateau[j+13].x = Coord[j].x + 5; // case 13 à 18
		plateau[j+13].y = Coord[8].y + 5; // case 13 à 18
		plateau[j+19].x = Coord[6].x + 5; // case 19 à 24
		plateau[j+19].y = Coord[j+9].y + 5; // case 19 à 24
		plateau[j+26].x = Coord[8].x + 5; // case 26 à 31
		plateau[j+26].y = Coord[14-j].y + 5; // case 26 à 31
		plateau[j+32].x = Coord[j+9].x + 5; // case 32 à 37
		plateau[j+32].y = Coord[8].y + 5; // case 32 à 37
		plateau[j+39].x = Coord[14-j].x + 5; // case 39 à 44
		plateau[j+39].y = Coord[6].y + 5; // case 39 à 44
		plateau[j+45].x = Coord[8].x + 5; // case 45 à 50
		plateau[j+45].y = Coord[5-j].y + 5; // case 45 à 50
	} 

	plateau[12].x = Coord[0].x;
	plateau[12].y = Coord[7].y;
	plateau[25].x = Coord[7].x;
	plateau[25].y = Coord[14].y;
	plateau[38].x = Coord[14].x;
	plateau[38].y = Coord[7].y;
	plateau[51].x = Coord[7].x;
	plateau[51].y = Coord[0].y;

}





des initStructDes(des d)
{
	d.des1 = lisBMPRGB("dés1.bmp");
	d.des2 = lisBMPRGB("dés2.bmp");
	d.des3 = lisBMPRGB("dés3.bmp");
	d.des4 = lisBMPRGB("dés4.bmp");
	d.des5 = lisBMPRGB("dés5.bmp");
	d.des6 = lisBMPRGB("dés6.bmp");
	d.appuyer = 1;
	d.desA = 0;
	d.go = 0;
	d.rejoue = 0;

	return d;
}

//METTRE LE CHRONON POUR LAISSER UN PEU L'AFFICHAGE DU DES
des lancementDes(int abs,int ord,des d,int *player,int *play,int peut,pion rep[16],gere g,cases plateau[52],image i)
{
	int cpt=0;
	if (d.appuyer == 2)
	{
		d.desA = rand()%6;
		d.appuyer = 3;
		if (d.desA == 5) d.go = 1;
	}
	else if (d.appuyer == 3)
	{
		abs = Coord[15].x + 220;
		ord = Coord[5].y + 20;
		affichageDes(abs,ord,d);
		//printf("des = %d\n",d.desA );
		if (d.desA == 5) d.rejoue = 1;
		if (d.desA < 5)
		{
			identifieJoueur(play,player,rep); //Obtention du premier pion du joueur 
			for (int i=*play; i<(*play + 4); i++) //On regarde si des pions se trouvent en dehors de l'enclos (cad si etatJ != 0) mais n'ayant pas gagné
			{
				if (rep[i].etatJ > 0 && rep[i].etatJ != 4) cpt++;
			}

			/* Check si un pion se trouve en dehors de l'enclos
				- si non alors on passe au jour d'après
				- si dans le plateau alors testDeplacementPlateau
					- s'il peut se déplacer alors il peut jouer
					- si non on passe au joueur suivant
				- si dans la ligne final alors testDeplacementFinal
					- idem
				- si que dans ligne final alors on passe au joueur suivant 
			*/
			if (cpt != 0)
			{
				peut = testDeplacementPlateau(plateau,rep,d,player,play,peut); //On test si le joueur possède des pions pouvant se déplacer sur le plateau de jeu (oui => peut=1)
				//ON TEST LA LIGNE FINAL
				if (peut == 1) 
				{
					d = deplacementPion(d,rep,plateau,play);
					peut = 0;
				}
				if (peut == 0) d = tourJoueur(rep,player,g,d); //On passe au joueur suivant

			}
			else 
			{
				couleurCourante(37,253,233);
				rectangle((Coord[1].x-450),(Coord[6].y-70),(Coord[14].x+200),(Coord[9].y-70));
				couleurCourante(0,0,0);
				afficheChaine("Dommage... vous ne pouvez pas vous deplacer.... ",45,(Coord[1].x-390),(Coord[6].y-10));
				d = tourJoueur(rep,player,g,d);//On passe au joueur suivant
			}
		}
	}

	return d;
}



int testDeplacementPlateau(cases plateau[52],pion rep[16],des d,int *player,int *play,int peut)
{
	int pos=0,cpt=0,inco=0;
	for (int j=*play; j<(*play+4); j++)
	{
		if (rep[j].etatJ == 1 || rep[j].etatJ ==2) //pion se trouvant sur la 1ère case ou se déplacant sur le plateau
		{
			pos = rep[j].position;	
			if (d.desA == 0) cpt = d.desA;
			else if (d.desA == 1)
			{
				if (plateau[(pos+1)].etatC == 0)	cpt = d.desA;
			}
			else 
			{
				for (int i=0; i<(d.desA-1); i++)
				{
					if (plateau[pos+(i+1)].etatC == 0)
					{
						cpt++;
					}
				}
				if (cpt == d.desA - 1) //Si pas de pions sur les cases du chemin (except la dernière)
				{
					if (plateau[pos+d.desA].etatC == 0) //Personne sur la dernière case
					{
						cpt++;
						plateau[pos+d.desA].couleur = 2; //permet d'afficher un cercle bleu
					} 
					else //Si pion sur la dernière case
					{
						inco = plateau[pos+d.desA].p.joueur;
						if (inco != *player) //si c'est un adversaire
						{
							plateau[pos+d.desA].couleur = 1; //permet d'afficher un cercle rouge
							cpt++;
						}
					}
				}
			}
			if (cpt == d.desA)		
			{
				rep[*play].possible = 1; //Le pion se trouvant sur la case peut alors se déplacer 
				peut = 1;
			}
			cpt = 0;
		}
	}
	return peut;
}

void affichePionPlateau(image i,pion rep[16],cases plateau[52])
{
	for(int k=0; k<52; k++)
	{
		if (plateau[k].etatC == 1)
		{
			for (int l=0; l<16;l++)
			{
				if (rep[l].etatJ == 1 || rep[l].etatJ == 2)
				{
					if (l == 0) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.licorne1->donneesRGB);
					else if (l == 1) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.licorne2->donneesRGB);
					else if (l == 2) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.licorne3->donneesRGB);
					else if (l == 3) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.licorne4->donneesRGB);
					else if (l == 4) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.sirene1->donneesRGB);
					else if (l == 5) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.sirene2->donneesRGB);
					else if (l == 6) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.sirene3->donneesRGB);
					else if (l == 7) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.sirene4->donneesRGB);
					else if (l == 8) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.dragon1->donneesRGB);
					else if (l == 9) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.dragon2->donneesRGB);
					else if (l == 10) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.dragon3->donneesRGB);
					else if (l == 11) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.dragon4->donneesRGB);
					else if (l == 12) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.HP1->donneesRGB);
					else if (l == 13) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.HP2->donneesRGB);
					else if (l == 14) ecrisImage(plateau[k].x,plateau[k].y,40,40,i.HP3->donneesRGB);
					else 			  ecrisImage(plateau[k].x,plateau[k].y,40,40,i.HP4->donneesRGB);
				
				}
			}
		}
	}
}

void choixDuPion(pion rep[16], cases plateau[52], int abs, int ord)
{
	int coordX=0, coordY=0, memX=abs, memY=ord;

	if (abs >= plateau[0].x && abs<=plateau[15].x && ord >= plateau[0].y && ord < plateau[15].y)
	{
		for (int i=0; i<52; i++)
		{
			for (int j=0; j<50; j++)
			{
				if (abs == plateau[i].x) coordX = i;
				else abs--;

				if (ord == plateau[i].y) coordY = i;
				else ord--;
			}
			abs = memX;
			ord = memY;
		}
	}

	for (int k=0; k<52; k++)
	{
		if (plateau[k].x == coordX && plateau[k].y == coordY) 
		{
			if (plateau[k].etatC == 1)
			{
				plateau[k].p.possible = 2;
			}
			break;
		}
	}
}


des deplacementPion(des d,pion rep[16],cases plateau[52],int *play)
{
	//FAIRE DEPLACER QUE LE PION SELECTIONNE
	for (int i=1; i<=d.desA; i++)
	{
		plateau[rep[*play].position].etatC = 0; // met la case du joueur à non occupé
		if (rep[*play].position > 1 && rep[*play].position < 100) rep[*play].etatJ = 2; //passe l'etat du joueur à dplcmt plateau

		if (rep[*play].position == 51) rep[*play].position = 0; //Permet d'augmenter de 1 la position du joueur
		else rep[*play].position ++;
		plateau[rep[*play].position].etatC = 1;
		/*
		//Condition stoppant le pion dans son avancé lorsqu'il atteint sa montée final
		if (rep[*play].animal == 1) //licorne
		{
			if (rep[*play].etatJ == 2 && rep[*play].position == 51) rep[*play].etatJ = 3; //Il ne peut plus se déplacer sur le plateau
		}
		else if (rep[*play].animal == 2) //Sirène
	 	{
			if (rep[*play].etatJ == 2 && rep[*play].position == 41) rep[*play].etatJ = 3;
	 	}
	 	else if (rep[*play].animal == 3) //Dragon
	 	{
			if (rep[*play].etatJ == 2 && rep[*play].position == 27) rep[*play].etatJ = 3;
	 	}
	 	else //HP
	 	{
			if (rep[*play].etatJ == 2 && rep[*play].position == 13) rep[*play].etatJ = 3;
	 	}

		//Condition faisant avancer le joueur sur la ligne final //\\NE GERE PAS L'AFFICHAGE//\\
	 	
	 	if (rep[*play].etatJ == 3 && rep[*play].position < 100 && d.desA == 0) rep[*play].position = 100;
	 	else if (rep[*play].etatJ == 3 && rep[*play].position == 100 && d.desA == 1) rep[*play].position = 200;
	 	else if (rep[*play].etatJ == 3 && rep[*play].position == 200 && d.desA == 2) rep[*play].position = 300;
	 	else if (rep[*play].etatJ == 3 && rep[*play].position == 300 && d.desA == 3) rep[*play].position = 400;
	 	else if (rep[*play].etatJ == 3 && rep[*play].position == 400 && d.desA == 4) rep[*play].position = 500;
	 	else if (rep[*play].etatJ == 3 && rep[*play].position == 500 && d.desA == 5) rep[*play].etatJ = 4;
	*/	
	}
	d.appuyer = 1;
	
	return d;
}




//Amélioration : faire défiler les dés
void affichageDes(int abs, int ord, des d)
{
	int affiche=0;
	affiche = d.desA;
	switch (affiche)
	{
		case 0:
			ecrisImage(abs,ord,d.des1->largeurImage,d.des1->hauteurImage,d.des1->donneesRGB);
			break;
		case 1:
			ecrisImage(abs,ord,d.des2->largeurImage,d.des2->hauteurImage,d.des2->donneesRGB);
			break;
		case 2:
			ecrisImage(abs,ord,d.des3->largeurImage,d.des3->hauteurImage,d.des3->donneesRGB);
			break;
		case 3:
			ecrisImage(abs,ord,d.des4->largeurImage,d.des4->hauteurImage,d.des4->donneesRGB);
			break;
		case 4:
			ecrisImage(abs,ord,d.des5->largeurImage,d.des5->hauteurImage,d.des5->donneesRGB);
			break;
		case 5:
			ecrisImage(abs,ord,d.des6->largeurImage,d.des6->hauteurImage,d.des6->donneesRGB);
			break;
	}
}

des gereClicDes(int abs, int ord,des d)
{
	if (abs >= (Coord[15].x+100) && abs <=(Coord[15].x+400) && ord>=Coord[8].y && ord<=Coord[10].y) 
	{
		d.appuyer = 2;
		if (d.rejoue == 1)	d.rejoue = 0;
	}
	return d;
}

//FAIRE ATTENTION QU'IL N'Y AI PAS DEJA UN PION A NOUS OU ADVERSAIRE (LE MANGER)
void gereClicSortir(int abs, int ord,des d, pion rep[16],int *player,int *play,cases enclosLicorne[4],cases enclosSirene[4],cases enclosDragon[4],cases enclosHP[4],cases plateau[52])
{
	int ani=0,pio=0;
	if (d.go == 1)
	{;
		if (abs>=(Coord[15].x+100) && abs<=(Coord[15].x+400) && ord>=Coord[2].y && ord<=Coord[4].y)
		{
			//On check quel est le 1er pion du joueur (on en deduit les 3 autres)
			identifieJoueur(play,player,rep);

			// On regarde quel animal lui appartient
			ani = rep[*play].animal;
			if (ani == 1)
			{
				if (plateau[1].etatC == 0 )// && AJOUTER L'EFFET JE MANGE l'ADVERSAIRE S'IL EST SUR LA CASE INIT
				{
					pio = enclosLicorne[0].p.numero; //on recupere le numero du pion se trouvant sur la premiere case de l'enclos
					enclosLicorne[0].etatC = 0; //la premiere case de l'enclos se libere
					rep[*play].etatJ = 1; //Le pion est à la case ini
					plateau[1].etatC = 1; //la case passe occupée
					rep[*play].position = 1; //1ère case de ce pion
					//AJOUTER LE RETOUR ENCLOS DE L'ADVERSAIRE
				}
			}
			else if (ani == 2)
			{
				if (plateau[40].etatC == 0 )// && AJOUTER L'EFFET JE MANGE l'ADVERSAIRE S'IL EST SUR LA CASE INIT
				{
					pio = enclosSirene[0].p.numero; //on recupere le numero du pion se trouvant sur la premiere case de l'enclos
					enclosSirene[0].etatC = 0; //la premiere case de l'enclos se libere
					rep[*play].etatJ = 1; //Le pion est à la case ini
					plateau[40].etatC = 1; //la case passe occupée
					rep[*play].position = 40; //1ère case de ce pion
					//AJOUTER LE RETOUR ENCLOS DE L'ADVERSAIRE
				}
			}
			else if (ani == 3)
			{
				if (plateau[27].etatC == 0 )// && AJOUTER L'EFFET JE MANGE l'ADVERSAIRE S'IL EST SUR LA CASE INIT
				{
					pio = enclosDragon[0].p.numero; //on recupere le numero du pion se trouvant sur la premiere case de l'enclos
					enclosDragon[0].etatC = 0; //la premiere case de l'enclos se libere
					rep[*play].etatJ = 1; //Le pion est à la case ini
					plateau[27].etatC = 1; //la case passe occupée
					rep[*play].position = 27; //1ère case de ce pion
					//AJOUTER LE RETOUR ENCLOS DE L'ADVERSAIRE
				}
			}
			else 
			{
				if (plateau[14].etatC == 0 )// && AJOUTER L'EFFET JE MANGE l'ADVERSAIRE S'IL EST SUR LA CASE INIT
				{
					pio = enclosHP[0].p.numero; //on recupere le numero du pion se trouvant sur la premiere case de l'enclos
					enclosHP[0].etatC = 0; //la premiere case de l'enclos se libere
					rep[*play].etatJ = 1; //Le pion est à la case ini
					plateau[14].etatC = 1; //la case passe occupée
					rep[*play].position = 14; //1ère case de ce pion
					//AJOUTER LE RETOUR ENCLOS DE L'ADVERSAIRE
				}
			}
		}
		d.go = 0;
	}
}






void plateauDeJeu(void)
{
	//Base 
	epaisseurDeTrait(3);
	couleurCourante(255,255,255);
	rectangle(Coord[0].x,Coord[0].y,Coord[15].x,Coord[15].y);


	//Rectanle rouge
	couleurCourante(255,0,0);
	rectangle(Coord[0].x,Coord[0].y,Coord[6].x,Coord[6].y);

	//Rectangle vert
	couleurCourante(0,255,0);
	rectangle(Coord[9].x,Coord[0].y,Coord[15].x,Coord[6].y);

	//Rectangle bleu
	couleurCourante(44,117,255);
	rectangle(Coord[0].x,Coord[9].y,Coord[6].x,Coord[15].y);

	//Rectangle jaune
	couleurCourante(255,255,0);
	rectangle(Coord[9].x,Coord[9].y,Coord[15].x,Coord[15].y);

	//Intérieur des rectangles dans l'ordre
	couleurCourante(255,255,255);
	rectangle((Coord[0].x+3),(Coord[0].y+3),(Coord[6].x-6),(Coord[6].y-6));
	rectangle((Coord[9].x+6),(Coord[0].y+3),(Coord[15].x-3),(Coord[6].y-6));
	rectangle((Coord[0].x+3),(Coord[9].y+6),(Coord[6].x-6),(Coord[15].y-4));
	rectangle((Coord[9].x+6),(Coord[9].y+6),(Coord[15].x-3),(Coord[15].y-4));

	//enclos jaune
	couleurCourante(255,255,0);
	rectangle(Coord[7].x,Coord[8].y,Coord[8].x,Coord[14].y);
	rectangle(Coord[8].x,Coord[13].y,Coord[14].x,Coord[14].y);
	rectangle(Coord[10].x,Coord[10].y,Coord[11].x,Coord[12].y);
	rectangle(Coord[11].x,Coord[10].y,Coord[14].x,Coord[11].y);
	rectangle(Coord[13].x,Coord[10].y,Coord[14].x,Coord[13].y);
	couleurCourante(0,0,0);
	ligne(Coord[9].x,Coord[9].y,Coord[9].x,Coord[15].y);
	ligne(Coord[14].x,Coord[14].y,Coord[14].x,Coord[10].y);
	ligne(Coord[10].x,Coord[10].y,Coord[10].x,Coord[12].y);
	ligne(Coord[11].x,Coord[11].y,Coord[11].x,Coord[12].y);
	ligne(Coord[13].x,Coord[11].y,Coord[13].x,Coord[13].y);
	ligne(Coord[9].x,Coord[14].y,Coord[14].x,Coord[14].y);
	ligne(Coord[9].x,Coord[13].y,Coord[13].x,Coord[13].y);
	ligne(Coord[10].x,Coord[10].y,Coord[14].x,Coord[10].y);
	ligne(Coord[11].x,Coord[11].y,Coord[13].x,Coord[11].y);
	ligne(Coord[10].x,Coord[12].y,Coord[11].x,Coord[12].y);
	ligne(Coord[9].x,Coord[9].y,Coord[15].x,Coord[9].y);
	afficheChaine("6",15,(Coord[7].x+20),(Coord[8].y+17));
	afficheChaine("5",15,(Coord[7].x+20),(Coord[9].y+17));
	afficheChaine("4",15,(Coord[7].x+20),(Coord[10].y+17));
	afficheChaine("3",15,(Coord[7].x+20),(Coord[11].y+17));
	afficheChaine("2",15,(Coord[7].x+20),(Coord[12].y+17));
	afficheChaine("1",15,(Coord[7].x+20),(Coord[13].y+17));

	//enclos bleu
	couleurCourante(44,117,255);
	rectangle(Coord[1].x,Coord[7].y,Coord[7].x,Coord[8].y);
	rectangle(Coord[1].x,Coord[8].y,Coord[2].x,Coord[14].y);
	rectangle(Coord[2].x,Coord[13].y,Coord[5].x,Coord[14].y);
	rectangle(Coord[4].x,Coord[10].y,Coord[5].x,Coord[14].y);
	rectangle(Coord[3].x,Coord[10].y,Coord[4].x,Coord[11].y);
	couleurCourante(0,0,0);
	ligne(Coord[0].x,Coord[9].y,Coord[6].x,Coord[9].y);
	ligne(Coord[1].x,Coord[9].y,Coord[1].x,Coord[14].y);
	ligne(Coord[3].x,Coord[10].y,Coord[5].x,Coord[10].y);
	ligne(Coord[3].x,Coord[11].y,Coord[4].x,Coord[11].y);
	ligne(Coord[2].x,Coord[13].y,Coord[4].x,Coord[13].y);
	ligne(Coord[1].x,Coord[14].y,Coord[5].x,Coord[14].y);
	ligne(Coord[2].x,Coord[9].y,Coord[2].x,Coord[13].y);
	ligne(Coord[3].x,Coord[10].y,Coord[3].x,Coord[11].y);
	ligne(Coord[5].x,Coord[10].y,Coord[5].x,Coord[14].y);
	ligne(Coord[4].x,Coord[11].y,Coord[4].x,Coord[13].y);
	ligne(Coord[6].x,Coord[9].y,Coord[6].x,Coord[15].y);
	afficheChaine("1",15,(Coord[1].x+20),(Coord[7].y+17));
	afficheChaine("2",15,(Coord[2].x+20),(Coord[7].y+17));
	afficheChaine("3",15,(Coord[3].x+20),(Coord[7].y+17));
	afficheChaine("4",15,(Coord[4].x+20),(Coord[7].y+17));
	afficheChaine("5",15,(Coord[5].x+20),(Coord[7].y+17));
	afficheChaine("6",15,(Coord[6].x+20),(Coord[7].y+17));
	
	//enclos ROUGE
	couleurCourante(255,0,0);
	rectangle(Coord[7].x,Coord[1].y,Coord[8].x,Coord[7].y);
	rectangle(Coord[1].x,Coord[1].y,Coord[7].x,Coord[2].y);
	rectangle(Coord[1].x,Coord[2].y,Coord[2].x,Coord[5].y);
	rectangle(Coord[2].x,Coord[4].y,Coord[5].x,Coord[5].y);
	rectangle(Coord[4].x,Coord[3].y,Coord[5].x,Coord[4].y);
	couleurCourante(0,0,0);
	ligne(Coord[0].x,Coord[6].y,Coord[6].x,Coord[6].y);
	ligne(Coord[1].x,Coord[1].y,Coord[1].x,Coord[5].y);
	ligne(Coord[4].x,Coord[3].y,Coord[5].x,Coord[3].y);
	ligne(Coord[2].x,Coord[4].y,Coord[4].x,Coord[4].y);
	ligne(Coord[1].x,Coord[5].y,Coord[5].x,Coord[5].y);
	ligne(Coord[2].x,Coord[2].y,Coord[2].x,Coord[4].y);
	ligne(Coord[4].x,Coord[3].y,Coord[4].x,Coord[4].y);
	ligne(Coord[5].x,Coord[3].y,Coord[5].x,Coord[5].y);
	ligne(Coord[1].x,Coord[1].y,Coord[6].x,Coord[1].y);
	ligne(Coord[2].x,Coord[2].y,Coord[6].x,Coord[2].y);
	ligne(Coord[6].x,Coord[0].y,Coord[6].x,Coord[6].y);
	afficheChaine("1",15,(Coord[7].x+20),(Coord[1].y+17));
	afficheChaine("2",15,(Coord[7].x+20),(Coord[2].y+17));
	afficheChaine("3",15,(Coord[7].x+20),(Coord[3].y+17));
	afficheChaine("4",15,(Coord[7].x+20),(Coord[4].y+17));
	afficheChaine("5",15,(Coord[7].x+20),(Coord[5].y+17));
	afficheChaine("6",15,(Coord[7].x+20),(Coord[6].y+17));

	//enclos vert
	couleurCourante(0,255,0);
	rectangle(Coord[8].x,Coord[7].y,Coord[14].x,Coord[8].y);
	rectangle(Coord[13].x,Coord[1].y,Coord[14].x,Coord[7].y);
	rectangle(Coord[10].x,Coord[4].y,Coord[12].x,Coord[5].y);
	rectangle(Coord[11].x,Coord[1].y,Coord[13].x,Coord[2].y);
	rectangle(Coord[10].x,Coord[1].y,Coord[11].x,Coord[4].y);
	couleurCourante(0,0,0);
	ligne(Coord[9].x,Coord[0].y,Coord[9].x,Coord[6].y);
	ligne(Coord[14].x,Coord[1].y,Coord[14].x,Coord[6].y);
	ligne(Coord[10].x,Coord[1].y,Coord[10].x,Coord[5].y);
	ligne(Coord[11].x,Coord[2].y,Coord[11].x,Coord[4].y);
	ligne(Coord[13].x,Coord[2].y,Coord[13].x,Coord[6].y);
	ligne(Coord[12].x,Coord[4].y,Coord[12].x,Coord[5].y);
	ligne(Coord[10].x,Coord[1].y,Coord[14].x,Coord[1].y);
	ligne(Coord[11].x,Coord[2].y,Coord[13].x,Coord[2].y);
	ligne(Coord[10].x,Coord[5].y,Coord[12].x,Coord[5].y);
	ligne(Coord[11].x,Coord[4].y,Coord[12].x,Coord[4].y);
	ligne(Coord[9].x,Coord[6].y,Coord[15].x,Coord[6].y);
	afficheChaine("1",15,(Coord[13].x+20),(Coord[7].y+17));
	afficheChaine("2",15,(Coord[12].x+20),(Coord[7].y+17));
	afficheChaine("3",15,(Coord[11].x+20),(Coord[7].y+17));
	afficheChaine("4",15,(Coord[10].x+20),(Coord[7].y+17));
	afficheChaine("5",15,(Coord[9].x+20),(Coord[7].y+17));
	afficheChaine("6",15,(Coord[8].x+20),(Coord[7].y+17));


	couleurCourante(0,0,0);
	//trait vertical de la ligne
	int a;
	a=Coord[0].x;
	for (int i=0; i<15; i++)			
	{
		ligne(a,Coord[6].y,a,Coord[9].y);
		a+=cote;
	}
	//trait vertical de la colonne
	ligne(Coord[7].x,Coord[9].y,Coord[7].x,Coord[15].y);
	ligne(Coord[8].x,Coord[9].y,Coord[8].x,Coord[15].y);
	ligne(Coord[7].x,Coord[0].y,Coord[7].x,Coord[6].y);
	ligne(Coord[8].x,Coord[0].y,Coord[8].x,Coord[6].y);


	
	//ligne horizontale de la colonne
	int b; 
	b=Coord[0].y;
	for (int i=0; i<15; i++)			
	{
		ligne(Coord[6].x,b,Coord[9].x,b);
		b+=cote;
	}

	//ligne horizontale de la ligne
	ligne(Coord[0].x,Coord[7].y,Coord[6].x,Coord[7].y);
	ligne(Coord[0].x,Coord[8].y,Coord[6].x,Coord[8].y);
	ligne(Coord[9].x,Coord[7].y,Coord[15].x,Coord[7].y);
	ligne(Coord[9].x,Coord[8].y,Coord[15].x,Coord[8].y);

	//Base triangle
	couleurCourante(0,0,0);
	rectangle(Coord[7].x,Coord[7].y,Coord[8].x,Coord[8].y);
	couleurCourante(255,0,0);
	triangle((Coord[7].x+3),(Coord[7].y+3),(Coord[7].x+25),(Coord[7].y+25),(Coord[8].x-3),(Coord[7].y+3));
	couleurCourante(0,255,0);
	triangle((Coord[8].x-3),(Coord[7].y+3),(Coord[7].x+25),(Coord[7].y+25),(Coord[8].x-3),(Coord[8].y-3));
	couleurCourante(255,255,0);
	triangle((Coord[8].x-3),(Coord[8].y-3),(Coord[7].x+25),(Coord[7].y+25),(Coord[7].x+3),(Coord[8].y-3));
	couleurCourante(44,117,255);
	triangle((Coord[7].x+3),(Coord[8].y-3),(Coord[7].x+25),(Coord[7].y+25),(Coord[7].x+3),(Coord[7].y+3));
}


void boutons(int *player)
{
	char numeroJoueur[] = "0";
	sprintf(numeroJoueur,"%d",*player);
	couleurCourante (220,220,220);
	rectangle((Coord[15].x+100),Coord[8].y,(Coord[15].x+400),Coord[10].y);
	rectangle((Coord[15].x+175),Coord[5].y,(Coord[15].x+325),Coord[7].y);
	rectangle((Coord[15].x+100),Coord[2].y,(Coord[15].x+400),Coord[4].y);
	couleurCourante(0,0,0);
	afficheChaine("Lancer les des",25,(Coord[15].x+150),(Coord[9].y-10));
	afficheChaine("Sortir son animal",25,(Coord[15].x+130),(Coord[3].y-10));

	couleurCourante(255,0,0);
	afficheChaine("C'est au tour du : ",35,(Coord[15].x+130),(Coord[13].y+50));
	couleurCourante(0,0,0);
	afficheChaine("joueur ",40,(Coord[15].x+200),(Coord[11].y+50));
	afficheChaine(numeroJoueur,40,(Coord[15].x+350),(Coord[11].y+50));

}

//A MOFIFIER
gere initStructGERECLIC(gere g)
{
	g.nombreJ = 0;
	g.clicJ = 0;
	g.next = 0;
	//Mettre à 0 quand il y aura une page de garde
	g.menu = 1;

	return g;
}


// Affiche les options de jeu 
void option(gere g,image i,pion rep[16])
{
	couleurCourante (220,220,220);
	rectangle((Coord[15].x+100),Coord[13].y,(Coord[15].x+400),Coord[14].y);

	//Affiche le nombre de joueur exact pour leur demander de choisir leur animal
	if (g.nombreJ >= 2) rectangle((Coord[15].x+100),Coord[11].y,(Coord[15].x+300),Coord[12].y);
	if (g.nombreJ >= 2) rectangle((Coord[15].x+100),Coord[9].y,(Coord[15].x+300),Coord[10].y);
	if (g.nombreJ >= 3) rectangle((Coord[15].x+100),Coord[7].y,(Coord[15].x+300),Coord[8].y);
	if (g.nombreJ >= 4) rectangle((Coord[15].x+100),Coord[5].y,(Coord[15].x+300),Coord[6].y);

	//Demande le nombre de joueur pour la partie
	couleurCourante (229,229,229);
	if (g.clicJ == 1)
	{
		rectangle((Coord[15].x+405),(Coord[13].y+10),(Coord[15].x+500),Coord[14].y);
		rectangle((Coord[15].x+405),(Coord[12].y+10),(Coord[15].x+500),Coord[13].y);
		rectangle((Coord[15].x+405),(Coord[11].y+10),(Coord[15].x+500),Coord[12].y);

		couleurCourante(0,0,0);
		afficheChaine("2",25,(Coord[15].x+445),(Coord[12].y+70));
		afficheChaine("3",25,(Coord[15].x+445),(Coord[11].y+70));
		afficheChaine("4",25,(Coord[15].x+445),(Coord[10].y+70));
	}

	//Propose les animaux possible à jouer 
	if (g.clicJ == 2) rectangle((Coord[15].x+300),Coord[11].y,(Coord[15].x+500),Coord[12].y);
	if (g.clicJ == 3) rectangle((Coord[15].x+300),Coord[9].y,(Coord[15].x+500),Coord[10].y);
	if (g.clicJ == 4) rectangle((Coord[15].x+300),Coord[7].y,(Coord[15].x+500),Coord[8].y);
	if (g.clicJ == 5) rectangle((Coord[15].x+300),Coord[5].y,(Coord[15].x+500),Coord[6].y);


	couleurCourante(0,0,0);
	afficheChaine("Nombre de joueur",25,(Coord[15].x+120),(Coord[12].y+65));
	if (g.nombreJ >= 2) afficheChaine("joueur 1",25,(Coord[15].x+150),(Coord[10].y+65));
	if (g.nombreJ >= 2) afficheChaine("joueur 2",25,(Coord[15].x+150),(Coord[8].y+65));
	if (g.nombreJ >= 3) afficheChaine("joueur 3",25,(Coord[15].x+150),(Coord[6].y+65));
	if (g.nombreJ == 4) afficheChaine("joueur 4",25,(Coord[15].x+150),(Coord[4].y+65));

	//Affiche des différents animals possible CHANGER LES 3 DERNIERES IMAGES
	if (g.clicJ >= 2) 
	{
		int h=0;
		if (g.clicJ == 2) h = (Coord[11].y+5);
		else if (g.clicJ == 3) h = (Coord[9].y+5);
		else if (g.clicJ == 4) h = (Coord[7].y+5);
		else if (g.clicJ == 5) h = (Coord[5].y+5);
	
		for (int j=0; j<4; j++)
		{
			if (rep[j].joueur == 0) ecrisImage((Coord[15].x+303),h,i.licorne1->largeurImage,i.licorne1->hauteurImage,i.licorne1->donneesRGB);
			if (rep[j+4].joueur == 0) ecrisImage((Coord[15].x+354),h,i.sirene4->largeurImage,i.sirene4->hauteurImage,i.sirene4->donneesRGB);
			if (rep[j+8].joueur == 0) ecrisImage((Coord[15].x+405),h,i.dragon2->largeurImage,i.dragon2->hauteurImage,i.dragon2->donneesRGB);
			if (rep[j+12].joueur == 0) ecrisImage((Coord[15].x+456),h,i.HP5->largeurImage,i.HP5->hauteurImage,i.HP5->donneesRGB);
		}
	}
}

/*
Permet de gérer le paramètre d'affichage des animaux possibles pour le joueur sélectionné
*/
gere gereClicChoix(int abs, int ord, gere g)
{
	if (abs >= (Coord[15].x+100) && abs <=(Coord[15].x+400) && ord>=Coord[13].y && ord<=Coord[14].y) g.clicJ = 1;
	
	if (g.nombreJ >= 2) 
	{
		if (abs >= (Coord[15].x+100) && abs <=(Coord[15].x+300) && ord>=Coord[11].y && ord<=Coord[12].y) g.clicJ = 2;
 		if (abs >= (Coord[15].x+100) && abs <=(Coord[15].x+300) && ord>=Coord[9].y && ord<=Coord[10].y) g.clicJ = 3;
	}
	if (g.nombreJ >= 3) 
	{
		if (abs >= (Coord[15].x+100) && abs <=(Coord[15].x+300) && ord>=Coord[7].y && ord<=Coord[8].y) g.clicJ = 4;
	}
	if (g.nombreJ == 4)  
	{
		if (abs >= (Coord[15].x+100) && abs <=(Coord[15].x+300) && ord>=Coord[5].y && ord<=Coord[6].y) g.clicJ = 5;
	}
	return g;
}

//Initialise le nombre de joueur pour la partie
gere gereClicJoueur(int abs, int ord, gere g,int *player)
{
	if (g.clicJ == 1)
	{

		if (abs >= (Coord[15].x+405) && abs <=(Coord[15].x+500) && ord>=(Coord[13].y+10) && ord<=Coord[14].y) 
		{
			g.nombreJ = 2;
			g.clicJ = 0;
			*player = rand()%2;
		}
		else if (abs >= (Coord[15].x+405) && abs <=(Coord[15].x+500) && ord>=(Coord[12].y+10) && ord<=Coord[13].y) 
		{
			g.nombreJ = 3;
			g.clicJ = 0;
			*player = rand()%3;
		}
		else if (abs >= (Coord[15].x+405) && abs <=(Coord[15].x+500) && ord>=(Coord[11].y+10) && ord<=Coord[12].y) 
		{
			g.nombreJ = 4;
			g.clicJ = 0;
			*player = rand()%4;
		}
		if (*player == 0) *player = 1;
	}
	return g;
}

/*
Attribue un animal à un joueur dans le tableau playeurs (1ère colonne = numéro du joueur de 1 à 4)(2ème colonne = son animal)
	Rappel : 1 = licorne
			 2 = Sirene
			 3 = Dragon
			 4 = HP
*/
gere gereClicAnimal(int abs, int ord, gere g, pion rep[16],int *stade)
{
	int a=0,b=0,c=0,cpt=0;

	if (g.clicJ == 2)
	{
		a = (Coord[11].y+5);
		b = (Coord[12].y-5);
	}
	else if (g.clicJ == 3)
	{
		a = (Coord[9].y+5);
		b = (Coord[10].y-5);
	}
	else if (g.clicJ == 4)
	{
		a = (Coord[7].y+5);
		b = (Coord[8].y-5);
	}
	else if (g.clicJ == 5)
	{
		a = (Coord[5].y+5);
		b = (Coord[6].y-5);
	}

	c = g.clicJ-1;

	//Licorne
	if (abs >= (Coord[15].x+303) && abs <=(Coord[15].x+343) && ord>=a && ord<=b) 
	{
		for (int i=0; i<4; i++)
		{		
			for (int j=0; j<16; j++)
			{
				if (rep[j].joueur == c ) rep[j].joueur = 0;
			}
			for (int i=0; i<4; i++)
			{
				if (rep[i].joueur == 0 ) rep[i].joueur = c;
			}
		}
		g.clicJ = 0;
	}
	//Sirene
	else if (abs >= (Coord[15].x+354) && abs <=(Coord[15].x+394) && ord>=a && ord<=b) 
	{
		for (int i=0; i<4; i++)
		{
			for (int j=0; j<16; j++)
			{
				if (rep[j].joueur == c ) rep[j].joueur = 0;
			}
			for (int i=0; i<4; i++)
			{
				if (rep[i+4].joueur == 0) rep[i+4].joueur = c;
			}
		}
		g.clicJ = 0;
	}
	//Dragon
	else if (abs >= (Coord[15].x+405) && abs <=(Coord[15].x+445) && ord>=a && ord<=b) 
	{
		for (int j=0; j<16; j++)
			{
				if (rep[j].joueur == c ) rep[j].joueur = 0;
			}
			for (int i=0; i<4; i++)
			{
				if (rep[i+8].joueur == 0) rep[i+8].joueur = c;
			}
		g.clicJ = 0;
	}
	//HP
	else if (abs >= (Coord[15].x+456) && abs <=(Coord[15].x+496) && ord>=a && ord<=b) 
	{
		for (int j=0; j<16; j++)
			{
				if (rep[j].joueur == c ) rep[j].joueur = 0;
			}
			for (int i=0; i<4; i++)
			{
				if (rep[i+12].joueur == 0) rep[i+12].joueur = c;
			}
		g.clicJ = 0;
	}

	for (int m=0; m<16; m++)
	{
		if (rep[m].joueur != 0) cpt++;
	}
	if (g.nombreJ == 4 && cpt == 16) *stade = 2;
	else if (g.nombreJ == 3 && cpt == 12) *stade = 2;
	else if (g.nombreJ == 2 && cpt == 8) *stade = 2;


	return g;
}

void placementEnclosLicorne(cases enclosLicorne[4],image i, pion rep[16])
{
	int l=0;

	for (int k=0; k<4; k++)
	{
		if (rep[k].joueur != 0 && rep[k].etatJ == 0)
		{
			if (enclosLicorne[k].etatC == 1) 
			{
				if (k == 0) ecrisImage(enclosLicorne[l].x,enclosLicorne[l].y,40,40,i.licorne1->donneesRGB);
				else if (k == 1) ecrisImage(enclosLicorne[l].x,enclosLicorne[l].y,40,40,i.licorne2->donneesRGB);
				else if (k == 2) ecrisImage(enclosLicorne[l].x,enclosLicorne[l].y,40,40,i.licorne3->donneesRGB);
				else ecrisImage(enclosLicorne[l].x,enclosLicorne[l].y,40,40,i.licorne4->donneesRGB);
				l++;
			}
		}
	}
}

void placementEnclosSirene(cases enclosSirene[4],image i, pion rep[16])
{
	int l=0,m=0;
	for (int k=4; k<8; k++)
	{
		m=k-4;
		if (rep[k].joueur != 0 && rep[k].etatJ == 0)
		{
			if (enclosSirene[m].etatC == 1) 
			{
				if (m == 0) ecrisImage(enclosSirene[l].x,enclosSirene[l].y,40,40,i.sirene1->donneesRGB);
				else if (m == 1) ecrisImage(enclosSirene[l].x,enclosSirene[l].y,40,40,i.sirene2->donneesRGB);
				else if (m == 2) ecrisImage(enclosSirene[l].x,enclosSirene[l].y,40,40,i.sirene3->donneesRGB);
				else ecrisImage(enclosSirene[l].x,enclosSirene[l].y,40,40,i.sirene4->donneesRGB);
				l++;
			}
		}
	}
}

void placementEnclosDragon(cases enclosDragon[4],image i, pion rep[16])
{
	int l=0,m=0;
	for (int k=8; k<12; k++)
	{
		m=k-8;
		if (rep[k].joueur != 0 && rep[k].etatJ == 0)
		{
			if (enclosDragon[m].etatC == 1) 
			{
				if (m == 0) ecrisImage(enclosDragon[l].x,enclosDragon[l].y,40,40,i.dragon1->donneesRGB);
				else if (m == 1) ecrisImage(enclosDragon[l].x,enclosDragon[l].y,40,40,i.dragon2->donneesRGB);
				else if (m == 2) ecrisImage(enclosDragon[l].x,enclosDragon[l].y,40,40,i.dragon3->donneesRGB);
				else ecrisImage(enclosDragon[l].x,enclosDragon[l].y,40,40,i.dragon4->donneesRGB);
				l++;
			}
		}
	}
}

void placementEnclosHP(cases enclosHP[4],image i, pion rep[16])
{
	int l=0,m=0;
	for (int k=12; k<16; k++)
	{
		m=k-12;
		if (rep[k].joueur != 0 && rep[k].etatJ == 0)
		{
			if (enclosHP[m].etatC == 1) 
			{
				if (m == 0) ecrisImage(enclosHP[l].x,enclosHP[l].y,40,40,i.HP1->donneesRGB);
				else if (m == 1) ecrisImage(enclosHP[l].x,enclosHP[l].y,40,40,i.HP2->donneesRGB);
				else if (m == 2) ecrisImage(enclosHP[l].x,enclosHP[l].y,40,40,i.HP3->donneesRGB);
				else ecrisImage(enclosHP[l].x,enclosHP[l].y,40,40,i.HP4->donneesRGB);
				l++;

			}
		}
	}
}



des tourJoueur(pion rep[16],int *player, gere g,des d)
{
	(*player) ++;
	switch (g.nombreJ)
	{
		case 2:
			if (*player == 3) *player = 1;
			break;
		case 3:
			if (*player == 4) *player = 1;
			break;
		case 4:
			if (*player == 5) *player = 1;
			break;

	}
	d.appuyer = 1;
	d.go = 0;
	d.rejoue = 0;

	return d;
	
}

void identifieJoueur(int *play, int *player, pion rep[16])
{
	for (int i=0; i<16; i++) 
	{
		if (rep[i].joueur == *player) 
		{
			*play = i;
			break;
		}
	}
}




portail initStructPortail(portail po)
{
	po.b = 0;
	po.j = 0;
	po.v = 0;
	po.r = 0;

	return po;
}

//MISE EN PLACE CHRONO POUR L'OUVRIR EN MOUVEMENT
portail animationPortail(portail po)
{
	couleurCourante(157,62,12);
	if (po.b == 0)	rectangle(Coord[1].x,Coord[9].y,Coord[2].x,(Coord[9].y+6));
	if (po.j == 0) 	rectangle(Coord[9].x,Coord[13].y,(Coord[9].x+6),Coord[14].y);
	if (po.v == 0)	rectangle(Coord[13].x,(Coord[6].y-6),Coord[14].x,Coord[6].y);
	if (po.r == 0)	rectangle((Coord[6].x-7),Coord[1].y,Coord[6].x,Coord[2].y);

	return po;
}