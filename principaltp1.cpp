
#include <iostream>
#include"Magicien.h"
#include"Sort.h"
#include"Utilitaires.h"


void afficherJoueurStats(Magicien* joueur) 
{

	std::cout << "**********JOUEUR***********" << "\n";
	std::cout << "VIE: " << joueur->getVie() << "\n";
	std::cout << "MANA: " << joueur->getMana() << "\n";
	std::cout << "BOUCLIER: " << joueur->getBouclier() << "\n";
	std::cout << "BATON: " << joueur->getBaton()->getNom() << "\n";
	std::cout << "\n" << "\n" << "\n";
}


void afficherOrdinateurStats(Magicien* ordinateur)
{
	std::cout << "**********ORDINATEUR***********" << "\n";
	std::cout << "VIE: " << ordinateur->getVie() << "\n";
	std::cout << "MANA: " << ordinateur->getMana() << "\n";
	std::cout << "BOUCLIER: " << ordinateur->getBouclier() << "\n";
	std::cout << "BATON: " << ordinateur->getBaton()->getNom();
	std::cout << "\n" << "\n" << "\n";

}


bool changerTour() {
	int tourRNG{ genererNombreAleatiore(1,2) };
	int tour{ tourRNG};

	if (tourRNG == 1)
	{
		return true; //joueur
	}
	else if(tourRNG==2)
	{
		return false; //ordinateur
	}
}



int main()
{
	Magicien* joueur{ new Magicien{} };
	Magicien* ordinateur{ new Magicien{} };
	char action{};
	int tour{1};
	 

	while (joueur->hasHp() && ordinateur->hasHp())
	{
		
		if (changerTour())
		{
			std::cout << "Choisissez une action:  \n";
			std::cout << "'a' pour lancer un sort d'ATTAQUE \n";
			std::cout << "'d' pour lancer un sort de DEFENSE \n";
			std::cout << "'c' pour changer de baton \n";
			std::cin >> action;

			switch (action)
			{
			case'c':
				joueur->changerDeBaton();
				break;
			case'a':
				joueur->lancerUnSort(ordinateur, action);
				break;
			case'd':
				joueur->lancerUnSort(ordinateur, action);
				break;
			}

			afficherJoueurStats(joueur);
			changerTour();
			
		}
		if (!changerTour())
		{
			int ordinateurRNG{ genererNombreAleatiore(1,3) };

			switch (ordinateurRNG)
			{
			case 1:
				ordinateur->changerDeBaton();
				break;
			case 2:
				ordinateur->lancerUnSort(joueur, 'a');
				break;
			case 3:
				ordinateur->lancerUnSort(joueur, 'd');
				break;
			}

			afficherOrdinateurStats(ordinateur);
			changerTour();
		}
	}
	
	//Message de fin de partie
	if (joueur->hasHp())
	{
		std::cout << "Le joueur a gagner\n";		
	}
	else
	{
		std::cout << "L'ordinateur a gagner \n";
	}

	joueur->~Magicien();
	ordinateur->~Magicien();
	
}

