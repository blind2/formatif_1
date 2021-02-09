#ifndef MAGICIEN_DEF
#define MAGICIEN_DEF

#include <string>
#include"Baton.h"

class Magicien
{

private:
	int m_vie;
	int m_mana;
	int m_bouclier;
	Baton* m_baton;

public:
	Magicien();
	~Magicien();
	void gestionDesSorts(Magicien* magicien, char strategie);
	int faireDegat(Sort* sort, Magicien* magicien);
	int faireVraiDegat(Sort* sort, Magicien* magicien);
	int ReprendreVie(int hp);
	void changerDeBaton();
	void lancerUnSort(Magicien* magicien, char strategie);
	void creerUnBaton();
	int getVie();
	int getMana();
	int getBouclier();
	int setBouclier(int hp);
	bool hasMana();
	bool hasHp();
	Baton* getBaton();
	
};
#endif

