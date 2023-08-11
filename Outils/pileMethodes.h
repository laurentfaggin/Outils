#pragma once
#include <iostream>
#include <string>
#include "pileGen.h"
#include "listeGen.h"



bool caracteresCorrectementImbriques(std::string p_string);
int evaluationPriorite(char p_char);
Pile<char>infixeConvertiEnPostfixe(std::string p_stringInfixe);


