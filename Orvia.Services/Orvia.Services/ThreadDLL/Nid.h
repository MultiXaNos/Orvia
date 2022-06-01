#pragma once

#include "Periph_Balance.h"
#include "Periph_RFID.h"

#if defined (_WIN32) || defined( _WIN64)
	#include <Windows.h>
#endif 

#include <string>
#include <map>
#include <iterator>
#include <list>

// **********************************************************************************************************
//  Class Nid
// **********************************************************************************************************

class Nid
{

private :

    //___________________________
    // ::: Private attributes :::

	// periph balance object ptr
	PeriphBalance *periphBalance;
	// periph RFID object ptr
	PeriphRFID    *periphRFID;

	// min weight egg
	double minPoidsOeuf;
	// max weight egg
	double maxPoidsOeuf;

	// min weight chicken
	double minPoidsPoule;
	// max weight chicken
	double maxPoidsPoule;

	// struct rfid - eggs number
	std::map<std::string, int> pontes;
	// struct rfid - eggs number (not sure)
	std::map<std::string, int> pontesPotentielles;

	// eggs number
	int nbOeufs;
	
	// Enable debug mode
	int debugMode;
	// Path Debug File
	std::string pathDebugFile;

    //______________________________________
    // ::: Increment operation on struct :::

	// add into one struct RFID - egg++ or new RFID - 0 (egg nb)
	void addPonte(std::string *TagRFID, std::map<std::string, int> *pontes);

public :

	// Constructor of the class
	Nid(    std::string _deviceBalance  ,
			std::string _deviceRFID     ,
		    int          _baud           , 
		    int          _nbDataBits     , 
		    int          _parity         ,   
		    int          _nbStopBits     , 

		    std::string  _SNBalance      , 
		    std::string  _SNAntenne      , 
		 
		    double       _minPoidsOeuf   ,
		    double       _maxPoidsOeuf   ,
		    double       _minPoidsPoule  ,
		    double       _maxPoidsPoule  ,

		    int          _debug          , 
		    std::string  _pathDebugFile       );

	// Destructor
	~Nid();

    //__________________________
    // ::: Public operations :::

	// Chicken on balance ? (1 : yes 0 : no)
	int  PalmiOnBalance(std::string* sError);

	// Algoeithm new egg in the nest ?
	int  refresh(std::string* sError);

	// reset all attributes
	void reset();

    //__________________________
    // ::: Getters functions :::

	// Get struct RFID - total egg nbr - nbr egg (maybe)
	int  getPontes(std::list< std::list<std::string> > * allPontes);

	// Get egg nb into nest
	int  getNbOeuf();

};

