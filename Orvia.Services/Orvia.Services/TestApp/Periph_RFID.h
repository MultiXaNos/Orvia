#pragma once

#include "Periph.h"

#define STR_DECISION "\r\n"

class PeriphRFID : Periph
{

public  :

	PeriphRFID(std::wstring _port, int _baud, int _nbDataBits, int _parity, int _nbStopBits, std::string _SN, int _debug, std::string _pathDebugFile)
		: Periph(_port, _baud, _nbDataBits, _parity, _nbStopBits, _SN, _debug, _pathDebugFile) 
	{ 
	
		if (debugMode == 1) {

			char* logConstr = (char*)malloc(sizeof(char) * STR_SIZE);

			snprintf(logConstr, STR_SIZE, "RFID port : %s, baudrate : %i, nbDataBits : %i, parity : %i, nbStopBits : %i, SN : %s"
				                        , _port.c_str(), _baud, _nbDataBits, _parity, _nbStopBits, _SN.c_str() );

			WriteInDebugFile(logConstr);

		}
	
	};

	~PeriphRFID() {

		if (debugMode == 1) {

			char* logConstr = NULL;

			snprintf(logConstr, STR_SIZE, "|DESTRUCTION| SN : %s", SN.c_str());

			WriteInDebugFile(logConstr);

		}

	}

	int getTags(std::string* SN, std::string* tagRFID);

};

