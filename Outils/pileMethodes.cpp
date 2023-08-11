#include <stdexcept>
#include <iostream>
#include "pileMethodes.h"



bool caracteresCorrectementImbriques(std::string p_string) {
	Pile<char> pile;
	bool ok = true;
	for (char c : p_string) {
		if (c == '(' || c == '{' || c == '[') {
			pile.empiler(c);
		}
		else if ((c == ')' && pile.sommet() == '(') ||
			(c == '}' && pile.sommet() == '{') ||
			(c == ']' && pile.sommet() == '['))
		{
			pile.depiler();
		}
		else {
			ok = false;
		}
	}
	if (ok && pile.estPileVide()) {
		ok = true;
	}
	return ok;
}

Pile<char>infixeConvertiEnPostfixe(std::string p_stringInfixe) {
	Pile<char>pilePostfixe;
	Pile<char>pileStach;
	bool parenthese = false;
	std::cout << p_stringInfixe << std::endl;
	for (char c : p_stringInfixe) {
		int priorite = evaluationPriorite(c);
		switch (priorite) {
		case 0:
			if (c == '(') {
				pileStach.empiler(c);
			}
			else if (c != ')') {
				pilePostfixe.empiler(c);
			}
			else if (c == ')' && !pileStach.estPileVide()) {
				while (pileStach.sommet() != '(') {
					pilePostfixe.empiler(pileStach.sommet());
					pileStach.depiler();
				}
				pileStach.depiler();
			}
			break;

		case 1:
			if (evaluationPriorite(pileStach.sommet()) >= priorite) {
				pilePostfixe.empiler(pileStach.sommet());
				pileStach.depiler();
			}
			pileStach.empiler(c);

			break;

		case 2:
			if (evaluationPriorite(pileStach.sommet()) < priorite && !pileStach.estPileVide()) {
				pilePostfixe.empiler(pileStach.sommet());
				pileStach.depiler();
			}
			pileStach.empiler(c);
			break;

		default:
			break;
		}
	}
	while (!pileStach.estPileVide()) {

		pilePostfixe.empiler(pileStach.sommet());
		pileStach.depiler();
	}
	return pilePostfixe;
}

int evaluationPriorite(char p_char) {
	int priorite = 0;
	switch (p_char) {
	case '-':
	case '+':
		priorite = 1;
		break;
	case '/':
	case '*':
		priorite = 2;
		break;
	default:
		priorite = 0;
		break;
	}
	return priorite;
}



