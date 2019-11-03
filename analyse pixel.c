
				Description dÃ©taillÃ©e du code suivant la condition.
				"premiÃ¨re boucle for"
				Analyse de l'image sÃ©lectionnÃ©e et enregistrement d'un tableau RGB
				Si validation =0 et pas de clique sur l'image alors la carte reste retournÃ©e
				"deuxiÃ¨me boucle for"
				Une fois les deux clics effectuÃ©s, la variable me->stop = 1.
				Ainsi on parcourt les deux tableaux RGB des deux images sÃ©lectionnÃ©es.
				Si identique alors les images ne peuvent plus se retourner.
**/
void placementDosDeCarte(memory *me)
{
	int i=0,c=0,j=0,n=0;
	DonneesImageRGB *image;

	for (j=0; j<12; j++)
	{
		if ((me->clic1 == j+1 || me->clic2 == j+1) && me->validation[j] == 0)	
		{
			if (me->clic1 == j+1) 
			{
				image = me->image1;
			}
			if (me->clic2 == j+1) 
			{
				image = me->image2;
			}
			if (me->clic1 == j+1 || me->clic2 == j+1)
			{
				lisImage( CoordCarte[j].x,  CoordCarte[j].y, CoordCarte[j].l,  CoordCarte[j].h,image->donneesRGB);
			}
		}
		else if (me->validation[j] == 0)	
		{
			ecrisImage( CoordCarte[j].x,  CoordCarte[j].y, me->carte->largeurImage, me->carte->hauteurImage, me->carte->donneesRGB);
		}
		else;
	}

	if (me->clic1 !=0 && me->clic2 != 0 && me->stop == 1)
	{
		for (i=0; i<(image->largeurImage)*(image->hauteurImage)*3; i++)
		{
			if (me->image1->donneesRGB[i] == me->image2->donneesRGB[i]) c++;
		}
		if (c == (image->largeurImage)*(image->hauteurImage)*3) 
		{
			for (n=0; n<12; n++)
			{
				if (me->clic1 == n+1 || me->clic2 == n+1)
				{
					me->validation[n] = 1;
					me->cpt++;
				}
			}
		}
		else me->erreur++;
		me->stop=0;
	}

}
