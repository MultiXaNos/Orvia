#pragma once

#include "serialib.h"
#include "Functions.h"

#include <iostream>
#include <regex>

#define BUFFER_SIZE 1024
#define STR_SIZE    100

// **********************************************************************************************************
//  Class Periph
// **********************************************************************************************************

class Periph
{

protected :

    //_____________________________
    // ::: Protected attributes :::

	// Serial Number
	std::string SN;
	// Path Debug File
	std::string pathDebugFile;

	// Enable debug mode
	int         debugMode;      

	// Serial com object ptr
	serialib    *serial;

public    :

    // Constructor of the class
	Periph(		std::string			_SN                 ,
				int					_debug              ,
				std::string			_pathDebugFile      ,
				std::string         _device				, 
				const unsigned int  _baud				, 
				int					_nbDataBits = 8		,
				int					_parity     = 0		, 
				int					_nbStopBits = 1		    );

	// Destructor
	virtual ~Periph();

    //_____________________________________
    // ::: Read operation on characters :::

	// Read on serial port
	int getTrame(std::string * trame);

};

