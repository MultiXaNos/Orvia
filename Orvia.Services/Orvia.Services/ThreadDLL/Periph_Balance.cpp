#include "pch.h"

PeriphBalance::PeriphBalance(	std::string			_SN				 ,
								int					_debug			 ,
								std::string			_pathDebugFile   ,
								std::string         _device			 ,
								const unsigned int  _baud			 ,
								int					_nbDataBits      ,
								int					_parity          ,
								int					_nbStopBits        )
	

	: Periph(_SN, _debug, _pathDebugFile, _device, _baud, _nbDataBits, _parity, _nbStopBits)
{

	if (debugMode == 1) {

		char* logConstr = new char[STR_SIZE];

		snprintf(logConstr, STR_SIZE, "|CONSTRUCTION| Balance port : %s, baudrate : %i, nbDataBits : %i, parity : %i, nbStopBits : %i, SN : %s \n"
			, _device.c_str(), _baud, _nbDataBits, _parity, _nbStopBits, _SN.c_str());

		WriteInDebugFile(logConstr, pathDebugFile);

		delete logConstr;

	}

}

PeriphBalance::~PeriphBalance()
{

	if (debugMode == 1) {

		char* logConstr = new char[STR_SIZE];

		snprintf(logConstr, STR_SIZE, "|DESTRUCTION| SN z: %s", SN.c_str() + '\n');

		WriteInDebugFile(logConstr, pathDebugFile);

		delete logConstr;

	}

}

int PeriphBalance::getPoids(double * poids) {

	std::string trame;

	char* ending;

	int res = getTrame(&trame);

	if (trame.find(STR_DECISION_BAL) && res != -1) {

		trame = std::regex_replace(trame, std::regex("\r\n")       , "");
		trame = std::regex_replace(trame, std::regex(STR_DECISION_BAL) , "");
		trame = std::regex_replace(trame, std::regex("\x0cG:")     , "");
		trame = std::regex_replace(trame, std::regex(" ")          , "");
		trame = std::regex_replace(trame, std::regex("\f")         , "");

		*poids = strtod(trame.c_str(), &ending);

	} else { if (res != -1) res = 0; }

	if (debugMode == 1) {

		char* logGet = new char[STR_SIZE];

		snprintf(logGet, STR_SIZE, "Periph_Balance::getPoids poids = %s", trame.c_str());

		WriteInDebugFile(logGet, pathDebugFile);

		delete logGet;

	}

	return res;

}