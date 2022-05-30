#include "pch.h"

Periph::Periph(     std::string			_SN				 ,
					int					_debug			 ,
					std::string			_pathDebugFile   ,
					std::string         _device			 ,
					const unsigned int  _baud			 ,
					int					_nbDataBits      ,
					int					_parity	         ,
					int					_nbStopBits        )

{

	serial = new serialib();

	SerialDataBits Databits;
	SerialParity   Parity;
	SerialStopBits Stopbits;

	switch (_nbDataBits) {
		case 5  : Databits = SERIAL_DATABITS_5;  break;
		case 6  : Databits = SERIAL_DATABITS_6;  break;
		case 7  : Databits = SERIAL_DATABITS_7;  break;
		case 8  : Databits = SERIAL_DATABITS_8;  break;
		case 16 : Databits = SERIAL_DATABITS_16; break;
		default : Databits = SERIAL_DATABITS_8;
	}

	switch (_nbStopBits) {
		case 1  : Stopbits = SERIAL_STOPBITS_1; break;
		case 2  : Stopbits = SERIAL_STOPBITS_2; break;
		default : Stopbits = SERIAL_STOPBITS_1;
	}
	switch (_parity) {
		case 0 : Parity = SERIAL_PARITY_NONE; break;
		case 1 : Parity = SERIAL_PARITY_EVEN; break;
		default: Parity = SERIAL_PARITY_NONE;
	}

	serial->openDevice(_device.c_str(), _baud, Databits, Parity, Stopbits);

	SN            = _SN;
	debugMode     = _debug;
	pathDebugFile = _pathDebugFile;

	if (debugMode == 1) WriteInDebugFile("*********** CONSTRUCTION PERIPH ***********", pathDebugFile);

}

Periph::~Periph() {

	serial->closeDevice();

	delete serial;

	if (debugMode == 1) WriteInDebugFile("*********** DESTRUCTION PERIPH ***********", pathDebugFile);

}

int Periph::getTrame(std::string* trame) {

	int res;

	char  BufferTrame[BUFFER_SIZE];

	char  finalChar = '0';

	*trame = "";

	serial->readString(BufferTrame, finalChar, BUFFER_SIZE);

	trame->append(BufferTrame);

	if (trame->size() > 0)
		res = 1;
	else
		res = -1;

	if (debugMode == 1) {

		char* logGet = new char[STR_SIZE];

		snprintf(logGet, STR_SIZE, "Periph::getTrame trame = %s", trame->c_str());

		WriteInDebugFile(logGet, pathDebugFile);

		delete logGet;

	}

	return res;

}
