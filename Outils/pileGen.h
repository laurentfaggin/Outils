#pragma once
#include <stdexcept>
#include <iostream>
#include "listeGen.h"




template <class TypeElement>
class Pile {
public:
	Pile() :
		m_nombreDElements(0)
	{
	};

	Pile(int p_capacite) :
		m_nombreDElements(0),
		m_liste(p_capacite)
	{
		;
	};

	Pile(const Pile<TypeElement>& p_pileACopier) :
		m_liste(p_pileACopier.m_liste),
		m_nombreDElements(p_pileACopier.m_nombreDElements)
	{
	}

	~Pile() {

	};

	Pile<TypeElement>& operator=(const Pile<TypeElement>& p_pile2) {
		this->m_nombreDElements = p_pile2.m_nombreDElements;
		this->m_liste = p_pile2.m_liste;

		return *this;
	}

	void empiler(TypeElement p_element) {
		this->m_liste.ajouterFin(p_element);
		++this->m_nombreDElements;
	};

	TypeElement depiler() {
		if (this->m_liste.nombreDElement() > 0) {
			--this->m_nombreDElements;
			this->m_liste.supprimer(this->m_nombreDElements - 1);
		}
		else {
			throw std::invalid_argument("La liste est vide");
		}
	};

	TypeElement sommet() {
		return this->m_liste.obtenir(this->m_nombreDElements - 1);
	};

	bool estPileVide() {
		return m_nombreDElements == 0;
	};

	int taille() {
		return this->m_nombreDElements;
	};

	std::string pileToString() {
		std::stringstream string;
		for (int i = 0; i < this->taille(); ++i) {
			string << this->m_liste.obtenir(i);
		}
		return string.str();
	}

	template <class TypeElement> friend Pile<TypeElement> operator+ (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend Pile<TypeElement> operator+= (Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend bool operator== (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend bool operator!= (const Pile<TypeElement>& p_pile1, const Pile<TypeElement>& p_pile2);
	template <class TypeElement> friend Pile<TypeElement> operator~ (Pile<TypeElement>& p_pile);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& stream, const Pile<TypeElement>& p_pile);

private:
	Liste<TypeElement>m_liste;
	int m_nombreDElements;
};