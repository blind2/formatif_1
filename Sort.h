#ifndef SORT_DEF
#define SORT_DEF

#include <string>

class Sort
{
private:
	std::string m_nom;
	int m_dommage;

public:
	Sort(std::string nom, int dommage);
	int getDommage();
	std::string getNom();
};
#endif

