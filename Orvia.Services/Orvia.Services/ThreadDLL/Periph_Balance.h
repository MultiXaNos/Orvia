#pragma once

#include "Periph.h"
#include "Functions.h"

#define STR_DECISION_BAL "kg"

class PeriphBalance : Periph
{

public :

	PeriphBalance(  std::string			_SN					,
					int					_debug				,
					std::string			_pathDebugFile		,
					std::string         _device				,
					const unsigned int  _baud				,
					int					_nbDataBits  = 8	,
					int					_parity		 = 0	,
					int					_nbStopBits  = 1 	   );

	~PeriphBalance();

	int getPoids(double* poids);

};

