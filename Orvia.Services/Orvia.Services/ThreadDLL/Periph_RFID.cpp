#include "pch.h"

PeriphRFID::PeriphRFID(		std::string			_SN				  ,
							int					_debug			  ,
							std::string			_pathDebugFile    ,
							std::string         _device           ,
							const unsigned int  _baud             ,
							int					_nbDataBits       ,
							int					_parity		      ,
							int					_nbStopBits        )

	: Periph(_SN, _debug, _pathDebugFile, _device, _baud, _nbDataBits, _parity, _nbStopBits)
{
	 
	if (debugMode == 1) {

		char* logConstr = new char[STR_SIZE];

		snprintf(logConstr, STR_SIZE, "RFID port : %s, baudrate : %i, nbDataBits : %i, parity : %i, nbStopBits : %i, SN : %s"
			, _device.c_str(), _baud, _nbDataBits, _parity, _nbStopBits, _SN.c_str());

		WriteInDebugFile(logConstr, pathDebugFile);

		delete logConstr;

	}

}

PeriphRFID::~PeriphRFID()
{

	if (debugMode == 1) {

		char* logConstr = new char[STR_SIZE];

		snprintf(logConstr, STR_SIZE, "|DESTRUCTION| SN : %s", SN.c_str());

		WriteInDebugFile(logConstr, pathDebugFile);

		delete logConstr;

	}

}

int PeriphRFID::getTags(std::string* SN, std::string* tagRFID) {

	std::string trame; 

	int res = getTrame(&trame);

	if (trame.find(STR_DECISION_RFID) && res != -1) {  

		trame = std::regex_replace(trame, std::regex("\r\n"), "");

		*SN = trame.substr(0, trame.size() - 4);
		*tagRFID = trame.substr(trame.size() - 4);

	} else { if (res != -1) res = 0; }

	if (debugMode == 1) {

		char* logGet = new char[STR_SIZE];

		snprintf(logGet, STR_SIZE, "Periph_RFID::getTagRFID tagRFID = %s", trame.c_str());

		WriteInDebugFile(logGet, pathDebugFile);

		delete logGet;

	}

	return res;

}