#pragma once

#include "Periph_Balance.h"
#include "Periph_RFID.h"

#include <Windows.h>
#include <string>
#include <map>
#include <iterator>
#include <list>

class Nid
{

private :

	PeriphBalance *periphBalance;
	PeriphRFID    *periphRFID;

	double minPoidsOeuf;
	double maxPoidsOeuf;

	double minPoidsPoule;
	double maxPoidsPoule;

	std::map<std::string, int> pontes;
	std::map<std::string, int> pontesPotentielles;

	int nbOeufs;

	void addPonte(std::string *TagRFID, std::map<std::string, int> *pontes);

public :

	Nid(    std::string _port           ,
		    int         _baud           , 
		    int         _nbDataBits     , 
		    int         _parity         ,   
		    int         _nbStopBits     , 

		    std::string _SNBalance      , 
		    std::string _SNAntenne      , 

		    double      _minPoidsOeuf   ,
		    double      _maxPoidsOeuf   ,
		    double      _minPoidsPoule  ,
		    double      _maxPoidsPoule  ,

		    int         _debug          , 
		    std::string _pathDebugFile       );

	~Nid();

	int  PalmiOnBalance(std::string* sError);

	int  refresh(std::string* sError);

	void reset();

	int  getPontes(std::list< std::list<std::string> > * allPontes);

	int  getNbOeuf();

};

