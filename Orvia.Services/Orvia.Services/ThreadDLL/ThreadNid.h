#pragma once

#include "Nid.h"
#include "Etat.h"

#include <stdlib.h>

#include <thread>
#include <chrono>
#include <functional>

// **********************************************************************************************************
//  Class ThreadNid
// **********************************************************************************************************

class ThreadNid
{

private :

    //___________________________
    // ::: Private attributes :::

	// Nid object ptr
	Nid*        nid;
	
	// state thread
	// -1 : Error
	// 0  : Sleep
	// 1  : ON
	enum Etat   statut;
	
	// msg error state = -1
	std::string sError;

	// Enable debug mode
	int debugMode;
	// Path Debug File
	std::string pathDebugFile;

    //____________________________
    // ::: Run thread function :::

	// Main function thread
	void Execute();

protected :

    //_____________________________
    // ::: Protected attributes :::

	// thread
	std::thread t;

	// thread finished
	bool threadTerminate = false;
	// thread stopped
	bool threadStop      = true;

public :

	// Constructor of the class
	ThreadNid(  std::string  _deviceBalance	,
				std::string  _deviceRFID    ,
		        int			 _baud			, 
				int			 _nbDataBits	, 
				int			 _parity	    , 
				int			 _nbStopBits    , 

			    std::string  _SNAntenne		,
				std::string  _SNBalance		,

				double       _minPoidsOeuf	,
				double       _maxPoidsOeuf	,
				double       _minPoidsPoule	,
				double       _maxPoidsPoule	,

			    int			_debug			, 
			    std::string _pathDebugFile		);

	// Destructor
	~ThreadNid();

	//_____________________________
    // ::: Interact with thread :::

	// Wake up thread and execute his task
	int          WakeUpThread();

	// Finish thread 
	void         Terminate();

	//________________
    // ::: Getters :::

	// Return state thread
	// -1 : Error
	// 0  : Sleep
	// 1  : ON
	int          getStatut();

	// Return msg thread (rfid down ...)
	const char*  getError();
	 
	// Return eggs number
	int          getNbOeuf();

	// Return eggs / RFID
	int          getPontes(char ***pontes);

};

