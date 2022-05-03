#pragma once

#include "Periph.h"

#define STR_DECISION "kg"

class PeriphBalance : Periph
{

public :

	PeriphBalance(std::string _port, int _baud, int _nbDataBits, int _parity, int _nbStopBits, std::string _SN, int _debug, std::string _pathDebugFile)
		: Periph(_port, _baud, _nbDataBits, _parity, _nbStopBits, _SN, _debug, _pathDebugFile) 
	{

		if (debugMode == 1) {

			char * logConstr = NULL;

			snprintf(logConstr, STR_SIZE, "|CONSTRUCTION| Balance port : %s, baudrate : %i, nbDataBits : %i, parity : %i, nbStopBits : %i, SN : %s"
				                        , _port.c_str(), _baud, _nbDataBits, _parity, _nbStopBits, _SN.c_str());
				
			WriteInDebugFile(logConstr);

		}

	};

	~PeriphBalance() {

		if (debugMode == 1) {

			char* logConstr = NULL;

			snprintf( logConstr, STR_SIZE, "|DESTRUCTION| SN : %s", SN.c_str() );

			WriteInDebugFile(logConstr);

		}

	}

	int getPoids(double* poids);

};

