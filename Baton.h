#ifndef BATON_DEF
#define BATON_DEF

#include<string>
#include"Sort.h"

class Baton
{

private:
	std::string m_nom;
	Sort* m_sortAttaque;
	Sort* m_sortDefense;
	Sort* attaqueTab;
	Sort* defenseTab;

public:
	Baton();
	void genererSort();
	std::string getNom();
	Sort* getSortAttaque();
	Sort* getSortDefense();

};
#endif

