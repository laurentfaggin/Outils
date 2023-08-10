#pragma once

template <class TypeElement>
class Node {
public:
	Node() {
		m_donnee = 0;
		m_next = nullptr;
	};
	Node(TypeElement p_donnee) {
		m_donnee = p_donnee;
		m_next = nullptr;
	}
	Node(TypeElement p_donnee, Node* p_next) {
		m_donnee = p_donnee;
		m_next = p_next;
	}
	~Node() {
		if (this->m_next != p_null) {
			delete this->m_next;
			this->m_next = nullptr;
		}
	}
	TypeElement obtenirDonnees() const {
		return this->m_donnee;
	}
	void modifierDonnee(TypeElement p_donnee) {
		this->m_donnee = p_donnee;
	}
	void modifierSuivant(Node* p_next) {
		this->m_next = p_next;
	}
	Node* Next() {
		return this->m_next;
	}
private:
	TypeElement m_donnee;
	Node<TypeElement>* m_next;
};