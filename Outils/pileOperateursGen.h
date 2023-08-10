#pragma once
#include <string>
#include "pileGen.h"


template<class TypeElement>
Pile<TypeElement> operator+(const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2)
{
	Pile<TypeElement>nouvellePile;
	nouvellePile.m_liste = p_pile1.m_liste + p_pile2.m_liste;
	return nouvellePile;
}

template<class TypeElement>
Pile<TypeElement> operator+=(Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	p_pile1.m_liste += p_pile2.m_liste;
	return p_pile1;
}


template<class TypeElement>
bool operator== (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	return p_pile1.m_liste == p_pile2.m_liste;
}

template<class TypeElement>
bool operator!= (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2) {
	return p_pile1.m_liste != p_pile2.m_liste;
}

template<class  TypeElement>
Pile<TypeElement> operator~ (const Pile<TypeElement>& p_pile) {
	Pile<TypeElement> nouvellePile(p_pile.taille());
	for (size_t i = 0; i < p_pile.taille(); ++i) {
		TypeElement valeurDebut = p_pile.m_liste.obtenir(i);
		TypeElement valeurFin = p_pile.m_liste.obtenir(p_pile.taille() - 1 - i);
		nouvellePile.definir(i, valeurFin);
		nouvellePile.definir(p_pile.taille() - 1 - i, valeurDebut);
	}
	return nouvellePile;
}

template<class TypeElement>
std::ostream& operator<<(std::ostream& stream, const Pile<TypeElement>& p_pile) {
	stream << p_pile.m_liste;
	return stream;
}

