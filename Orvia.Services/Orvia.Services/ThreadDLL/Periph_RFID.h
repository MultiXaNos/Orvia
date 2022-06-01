#include "Periph.h"

#pragma once

#define STR_DECISION_RFID "\r\n"

// **********************************************************************************************************
//  Class PeriphRFID
// **********************************************************************************************************

class PeriphRFID : Periph
{

public  :

	// Constructor of the class
	PeriphRFID(		std::string			_SN					 ,
					int					_debug				 ,
					std::string			_pathDebugFile       ,
					std::string         _device				 ,
					const unsigned int  _baud				 ,
					int					_nbDataBits		= 8  ,
					int					_parity			= 0  ,
					int					_nbStopBits		= 1    );

	// Destructor
	~PeriphRFID();

    //_____________________________________
    // ::: Read operation on characters :::

	// Return by adress Serial Number and tags detected
	int getTags(std::string* SN, std::string* tagRFID);

};

