#include "Magicien.h"

Magicien::Magicien(){
	m_vie = 50;
	m_mana = 50;
	m_bouclier = 0;
	creerUnBaton();
	
}

Magicien::~Magicien()
{
	delete m_baton;
}

void Magicien::gestionDesSorts(Magicien* magicien, char strategie)
{
	std::string sortAttqueNom{ m_baton->getSortAttaque()->getNom() };
	std::string sortAttqueDefense{ m_baton->getSortDefense()->getNom()};
	int degatAttaque{};
	
	//Sort de Defense
	if (strategie=='d')
	{
		if (sortAttqueDefense == "Guerison")
		{
			ReprendreVie(m_baton->getSortDefense()->getDommage());
		}
		if (sortAttqueDefense == "Protection")
		{
			setBouclier(m_baton->getSortDefense()->getDommage());
		}
	}
	//Sort d'Attaque
	if (strategie == 'a')
	{
		if (sortAttqueNom == "Foudre")
		{
			faireVraiDegat(m_baton->getSortAttaque(), magicien);
		}
		if (sortAttqueNom == "Incineration")
		{
			faireDegat(m_baton->getSortDefense(),magicien);
		}
	}

}


int Magicien::faireDegat(Sort* sort, Magicien* magicien)
{
	//Prend le bouclier en considération
	int vieBouclier{ magicien->getVie()+magicien->getBouclier()}; 
	vieBouclier -= sort->getDommage();
	m_vie = vieBouclier;

	return m_vie;
}

int Magicien::faireVraiDegat(Sort* sort, Magicien* magicien)
{
	//Ne prend pas le bouclier en considération
	m_vie -= sort->getDommage();
	return 0;
}

int Magicien::ReprendreVie(int hp)
{
	m_vie += hp;
	if (m_vie > 100)
	{
		m_vie = 100;
	}
	return m_vie;
}

void Magicien::changerDeBaton()
{
	m_mana = 50;
	delete m_baton;
	creerUnBaton();	
}


void Magicien::lancerUnSort(Magicien* magicien, char strategie)
{
	m_mana -= 10;

	if (hasMana())
	{
		gestionDesSorts(magicien, strategie);
	}
	else
	{
		changerDeBaton();
	}
}

void Magicien::creerUnBaton()
{
	m_baton = new Baton{};
}

int Magicien::getVie()
{
	return m_vie;
}

int Magicien::getMana()
{
	return m_mana;
}

int Magicien::getBouclier()
{
	return m_bouclier;
}

int Magicien::setBouclier(int vie)
{
	m_bouclier += vie;
	if (m_bouclier > 50 )
	{
		m_bouclier = 50;
	}
	return m_bouclier;
}

bool Magicien::hasMana()
{
	if (m_mana>0)
	{
		return true;
	}
	return false;
}

bool Magicien::hasHp()
{
	if (m_vie>0)
	{
		return true;
	}
	return false;
}


Baton* Magicien::getBaton()
{
	return m_baton;
}
