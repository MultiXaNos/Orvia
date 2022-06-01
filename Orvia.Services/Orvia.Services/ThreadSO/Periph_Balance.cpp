#include "Periph_Balance.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// PeriphBalance ///////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

		char buffer[STR_SIZE];

		snprintf(buffer,  STR_SIZE, "|CONSTRUCTION| Balance device : %s, baudrate : %i, nbDataBits : %i, parity : %i, nbStopBits : %i, SN : %s"
			, _device.c_str(), _baud, _nbDataBits, _parity, _nbStopBits, _SN.c_str());

		WriteInDebugFile(buffer, pathDebugFile);

	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// ~PeriphBalance //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

PeriphBalance::~PeriphBalance()
{

	if (debugMode == 1) {

		char buffer[STR_SIZE];

		snprintf(buffer, STR_SIZE, "|DESTRUCTION| SN : %s", SN.c_str());

		WriteInDebugFile(buffer, pathDebugFile);

	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////// getPoids ////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

		char buffer[STR_SIZE];

		snprintf(buffer,STR_SIZE, "Periph_Balance::getPoids poids = %s", trame.c_str());

		WriteInDebugFile(buffer, pathDebugFile);

	}

	return res;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////