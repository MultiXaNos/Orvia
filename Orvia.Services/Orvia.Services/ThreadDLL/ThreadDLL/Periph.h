#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <tchar.h>

#include "Serial.h"

#define BUFFER_SIZE 1024
#define STR_SIZE    100

class Periph
{

protected :

	std::string SN;
	std::string pathDebugFile;

	int         debugMode;      

	CSerial     comRS;

public    :

	Periph(std::string _port, int _baud, int _nbDataBits, int _parity, int _nbStopBits, std::string _SN, int _debug, std::string _pathDebugFile);
	virtual ~Periph();

	int getTrame(std::string * trame);

};

