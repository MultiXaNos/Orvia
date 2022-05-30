#pragma once

#include <iostream>
#include <regex>
#include <tchar.h>

#include "serialib.h"
#include "Functions.h"

#define BUFFER_SIZE 1024
#define STR_SIZE    100

class Periph
{

protected :

	std::string SN;
	std::string pathDebugFile;

	int         debugMode;      

	serialib    *serial;

public    :

	Periph(		std::string			_SN                 ,
				int					_debug              ,
				std::string			_pathDebugFile      ,
				std::string         _device				, 
				const unsigned int  _baud				, 
				int					_nbDataBits = 8		,
				int					_parity     = 0		, 
				int					_nbStopBits = 1		    );

	virtual ~Periph();

	int getTrame(std::string * trame);

};

