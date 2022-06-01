#pragma once

#include "Periph.h"
#include "Functions.h"

#define STR_DECISION_BAL "kg"

// **********************************************************************************************************
//  Class PeriphBalance
// **********************************************************************************************************

class PeriphBalance : Periph
{

public :

	// Constructor of the class
	PeriphBalance(  std::string			_SN					,
					int					_debug				,
					std::string			_pathDebugFile		,
					std::string         _device				,
					const unsigned int  _baud				,
					int					_nbDataBits  = 8	,
					int					_parity		 = 0	,
					int					_nbStopBits  = 1 	   );

	// Destructor
	~PeriphBalance();

    //_____________________________________
    // ::: Read operation on characters :::

	// Return by adress weight
	int getPoids(double* poids);

};

