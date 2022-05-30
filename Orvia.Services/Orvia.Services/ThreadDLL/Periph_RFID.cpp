#include "pch.h"
#include "Periph_RFID.h"

int PeriphRFID::getTags(std::string* SN, std::string* tagRFID) {

	std::string trame;

	int res = getTrame(&trame);

	if (trame.find(STR_DECISION) && res != -1) {  

		trame = std::regex_replace(trame, std::regex("\r\n"), "");

		*SN = trame.substr(0, trame.size() - 4);
		*tagRFID = trame.substr(trame.size() - 4);

	} else { if (res != -1) res = 0; }

	if (debugMode == 1) {

		char* logGet = (char*) malloc(sizeof(char) * STR_SIZE);

		snprintf(logGet, STR_SIZE, "Periph_RFID::getTagRFID tagRFID = %s", trame.c_str());

		WriteInDebugFile(logGet);

	}

	return res;

}