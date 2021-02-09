#include "Baton.h"
#include"Sort.h"
#include"Utilitaires.h"

Baton::Baton() 
{
    genererSort();
    m_nom = m_sortAttaque->getNom() + " de " + m_sortDefense->getNom();  
}


void Baton::genererSort()
{
    attaqueTab = new Sort[2]{ {"Incineration",10},{"Foudre", 10} } ;
    defenseTab = new Sort[2]{ {"Protection",10},{"Guerison", 10} } ;

    m_sortAttaque = &attaqueTab[genererNombreAleatiore(0, 1)];
    m_sortDefense = &defenseTab[genererNombreAleatiore(0, 1)];

    
}



std::string Baton::getNom()
{
    return m_nom;
}

Sort* Baton::getSortAttaque()
{
    return m_sortAttaque;
}

Sort* Baton::getSortDefense()
{
    return m_sortDefense;
}



