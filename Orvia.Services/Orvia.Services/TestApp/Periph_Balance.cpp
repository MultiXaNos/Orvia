#include "pch.h"
#include "Periph_Balance.h"

int PeriphBalance::getPoids(double * poids) {

	std::string trame;

	char* ending;

	int res = getTrame(&trame);

	if (trame.find(STR_DECISION) && res != -1) {

		trame = std::regex_replace(trame, std::regex("\r\n")       , "");
		trame = std::regex_replace(trame, std::regex(STR_DECISION) , "");
		trame = std::regex_replace(trame, std::regex("\x0cG:")     , "");
		trame = std::regex_replace(trame, std::regex(" ")          , "");
		trame = std::regex_replace(trame, std::regex("\f")         , "");

		*poids = strtod(trame.c_str(), &ending);

	} else { if (res != -1) res = 0; }

	if (debugMode == 1) {

		char* logGet = (char*) malloc(sizeof(char) * STR_SIZE);

		snprintf(logGet, STR_SIZE, "Periph_Balance::getPoids poids = %s", trame.c_str());

		WriteInDebugFile(logGet);

	}

	return res;

}