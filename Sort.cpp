#include "Sort.h"
#include"Utilitaires.h"
#include"Magicien.h"



Sort::Sort(std::string nom, int dommage) : m_nom{ nom }, m_dommage{ dommage }{}


int Sort::getDommage()
{
	return m_dommage;
}

std::string Sort::getNom()
{
	return m_nom;

}



