#pragma once
#include <stdexcept>
#include "nodeGen.h"

template <class TypeElement>
class ListeChainee {
public:
	ListeChainee() :
		m_debut(nullptr),
		m_fin(nullptr),
		m_nombreMaillons(0)
	{
		;
	}

	ListeChainee(const ListeChainee<TypeElement>& p_listeACopier) :
		m_debut(p_listeACopier.m_debut),
		m_fin(p_listeACopier.m_fin),
		m_nombreMaillons(0)
	{
		Node<TypeElement>* noeudListeAcopier = p_listeACopier.m_debut;
		while (noeudListeAcopier != nullptr) {
			Node<TypeElement> noeudCopie = new Node<TypeElement>(noeudListeAcopier->obtenirDonnees());
			if (m_finn == nullptr) {
				m_debut = m_fin = noeudCopie;
			}
			else {
				m_fin->modifierSuivant = noeudCopie;
				m_fin = noeudCopie;
			}
			++nombreMaillons;
			noeudCopie = noeudCopie.Next();
		}
	}

	ListeChainee(ListeChainee<TypeElement>&& p_listeADeplacer) :
		m_debut(p_listeADeplacer.m_debut),
		m_fin(p_listeADeplacer.m_fin),
		m_nombreMaillons(p_listeADeplacer.m_nombreMaillons)
	{
		p_listeADeplacer.m_debut = nullptr;
		p_listeADeplacer.m_fin = nullptr;
		p_listeADeplacer.m_nombreMaillons = 0;
	}

	~ListeChainee()
	{
		Node<TypeElement>* noeudCourant = this->m_debut;
		while (noeudCourant != nullptr) {
			Node<TypeElement>* noeud = noeudcourant;
			noeudCourant = noeudCourant->m_next;
			delete noeud;
		}
		this->m_debut = nullptr;
		this->m_fin = nullptr;
		this->m_nombreMaillons = 0;
	}

	void ajouterDebut(const int& p_valeur) {
		Node<TypeElement>* noeudDebut = new Node<TypeElement>(p_valeur, this->m_debut);
		this->m_debut = noeudDebut;
		if (this->m_nombreMaillons == 0) {
			this->m_fin = noeudDebut;
		}
		++this->m_nombreMaillons;
	}

	Node<TypeElement>* nodePrecedent(const int& p_indice) {
		Node<TypeElement>* noeudPrecedent = this->m_debut;
		int compteur = 0;
		if (indice > 0) {
			compteur = p_indice - 1;
		}
		while (compteur) {
			if (this->m_nombreMaillons == 0) {
				std::invalid_argument("la liste est vide");
			}
			noeudPrecedent = noeudPrecedent->Next();
			--compteur;
		}
		return noeudPrecedent;
	}

	Node<TypeElement>* nodeCourant(const int& p_indice) {
		Node<TypeElement>* noeudCourant = this->m_debut;
		int compteur = p_indice;
		while (compteur != 0) {
			noeudCourant = noeudCourant->m_suivant;
			--compteur;
		}
		return noeudCourant;
	}

	void ajouterFin(const int& p_indice) {
		Node<TypeElement>* noeudFin = new Node(p_valeur);
		if (this->m_nombreMaillons == 0) {
			this->m_debut = noeudFin;
			this->m_fin = noeudFin;
		}
		else {
			Node<TypeElement>* futurPrecedent = this->nodePrecedent(this->m_nombreMaillons);
			noeudFin->modifierSuivant(futurPrecedent->m_suivant);
			futurPrecedent->modifierSuivant(noeudFin);
			this->m_fin = noeudFin;
		}
		++this->m_nombreMaillons;
	}

	void inserer(const int& p_valeur, const int& p_indice) {
		Node<TypeElement>* newNode = new Node(p_valeur);
		if (p_indice > this->m_nombreMaillons) {
			std::invalid_argument("valeur d'indice trop elevee");
		}
		else if (this->m_nombreMaillons != 0) {
			Node<TypeElement>* futurNoeudPrecedent = this->nodePrecedent(p_indice);
			newNode->modifierSuivant(futurNoeudPrecedent->m_suivant);
			futurNoeudPrecedent->modifierSuivant(newNode);
		}
		else {
			this->ajouterDebut(newNode->obtenirDonnee());
		}
	}

	void supprimerDebut() {
		if (this->m_nombreMaillons == 0) {
			std::invalid_argument("la liste est vide");
		}
		else if (this->m_nombreMaillons == 1) {
			this->m_debut = nullptr;
			this->m_fin = nullptr;
			this->m_nombreMaillons = 0;
		}
		else {
			Node<TypeElement>* noeudAEffacer = this->m_debut;
			this->m_debut = this->m_debut->m_suivant;
			noeudAEffacer->m_suivant = nullptr;
			delete noeudAEffacer;
			--this->m_nombreMaillons;
		}
	}

	void supprimerFin() {
		int compteur = this->m_nombreMaillons;
		if (this->m_nombreMaillons == 0) {
			std::invalid_argument("la liste est vide");
		}
		else if (this->m_nombreMaillons == 1) {
			Node<TypeElement>* noeudAEffacer = this->m_debut;
			this->m_debut = this->m_fin = nullptr;
			delete this->m_fin;
			delete noeudAEffacer;
		}
		else {
			Node<TypeElement>* futurDernier = this->nodePrecedent(this->m_nombreMaillons);
			delete futurDernier->m_suivant;
			futurDernier->m_suivant = nullptr;
			this->m_fin = futurDernier;
			--m_nombreMaillons;
		}
	}

	void supprimerA(const int& p_indice) {
		if (p_indice >= 0 && p_indice < this->m_nombreMaillons) {
			if (p_indice == 0) {
				this->supprimerDebut();
			}
			else {
				Node<TypeElement>* noeudPrecedent = this->nodePrecedent(p_indice);
				Node<TypeElement>* noeudAEffacer = this->nodeCourant(p_indice);
				noeudPrecedent->modifierSuivant(noeudAEffacer->m_suivant);
				noeudAEffacer->m_suivant = nullptr;
			}
			--m_nombreMaillons;
		}
		else {
			std::invalid_argument("l'indice n'est pas correct ou  la liste est vide");
		}
	}

	void vider() {
		if (this->m_nombreMaillons > 0) {
			while (this->m_nombreMaillons != 0) {
				this->supprimerDebut();
			}
		}
		else {
			return 0;
		}
	}

	TypeElement obtenir(const int& p_indice) {
		if (this->m_nombreMaillons == 0 || p_indice >= this->m_nombreMaillons) {
			std::invalid_argument("aucun element a la position donnee");
		}
		else {
			Node<TypeElement>* elementCherche = this->nodeCourant(p_indice);
			return elementCherche->obtenirDonnees();
		}
	}

	int nombreMaillons() {
		return this->m_nombreMaillons;
	}

	ListeChainee& operator = (ListeChainee&& p_listeADeplacer) {
		if (this != &p_listeADeplacer) {
			this->vider();
			this->m_debut = p_listeADeplacer.m_debut;
			this->m_fin = p_listeADeplacer.m_fin;
			this->m_nombreMaillons = p_listeADeplacer.m_nombreMaillons;

			this->m_debut = nullptr;
			this->m_fin = nullptr;
			this->m_nombreMaillons = 0;
		}
		return *this;
	}

	void parcourir(void(*p_fonction)(const int&)) {
		if (this->m_nombreMaillons == 0) {
			std::invalid_argument("la liste est vide");
		}
		else {
			Node<TypeElement>* noeudCourant = this->m_debut;
			while (noeudCourant != nullptr) {
				p_fonction(noeudCourant->obtenirDonnees());
				noeudCourant = noeudCourant->m_suivant;
			}
		}
	}

	void trier(bool(*p_fonctionTri)(const TypeElement&, const TypeElement&)) {
		if (this->m_nombreMaillons == 0) {
			std::invalid_argument("la liste est vide");
		}
		else {
			Node<TypeElement>* noeudCourant = this->m_debut;
			while (noeudCourant != nullptr) {
				Node<TypeElement>* noeudSuivant = noeudCourant->m_suivant;
				while (noeudSuivant != nullptr) {
					if (!p_fonctionTri(noeudCourant->obtenirDonnees(), noeudSuivant->obtenirDonnee())) {
						int temp = noeudCourant->obtenirDonnee();
						noeudCourant->modifierDonnees(noeudSuivant->obtenirDonnees());
						noeudSuivant->modifierDonnees(temp);
					}
					noeudSuivant = noeudSuivant->m_suivant;
				}
				noeudCourant = noeudCourant->m_suivant;
			}
		}
	}

private:
	int m_nombreMaillons;
	Node<TypeElement>* m_debut;
	Node<TypeElement>* m_fin;
};
