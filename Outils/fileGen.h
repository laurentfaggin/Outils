#pragma once
#include <stdexcept>
#include <iostream>
#include "listeGen.h"



template <class TypeElement>
class File {
public:
	File() :
		m_nombreDElements(0)
	{};

	File(int p_capacite) :
		m_nombreDElements(0),
		m_liste(p_capacite)
	{
		;
	};

	~File() {

	};

	//Refaire la methode avec le deplacement d'index

	void enfiler(TypeElement p_element) {
		++this->m_nombreDElements;
		this->m_liste.ajouterDebut(p_element);
	};

	TypeElement defiler() {
		TypeElement valeur = this->m_liste.obtenir(this->m_nombreDElements - 1);
		this->m_liste.supprimerFin();
		--this->m_nombreDElements;
		return valeur;
	};

	TypeElement tete() {
		return this->m_liste.obtenir(this->m_nombreDElements);
	};

	bool estFileVide() {
		return this->m_nombreDElements == 0;
	};

	int taille() {
		return this->m_nombreDElements;
	};

	template <class TypeElement> friend File<TypeElement> operator+(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend File<TypeElement> operator+=(File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend bool operator==(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend bool operator!=(const File<TypeElement>& p_file1, const File<TypeElement>& p_file2);
	template <class TypeElement> friend File<TypeElement> operator~(const File<TypeElement>& p_file);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& stream, const File<TypeElement>& p_file);

private:
	Liste<TypeElement>m_liste;
	int m_nombreDElements;
};