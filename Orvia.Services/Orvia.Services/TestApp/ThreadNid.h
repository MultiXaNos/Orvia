#pragma once

#include "Nid.h"
#include "Etat.h"

#include <stdlib.h>
#include <thread>
#include <chrono>
#include <functional>

class ThreadNid
{

private :

	Nid*        nid;

	enum Etat   statut;

	std::string sError;

	void Execute();

protected :

	std::thread t;

	bool threadTerminate = false;
	bool threadStop      = true;

public :

	ThreadNid(  std::wstring _portBalance	,
				std::wstring _portRFID		,
		        int			_baud			, 
				int			_nbDataBits	    , 
				int			_parity			, 
				int			_nbStopBits     , 

			    std::string _SNAntenne		,
				std::string _SNBalance		,

				double      _minPoidsOeuf	,
				double      _maxPoidsOeuf	,
				double      _minPoidsPoule	,
				double      _maxPoidsPoule	,

			    int			_debug			, 
			    std::string _pathDebugFile		);

	~ThreadNid();

	int          WakeUpThread();

	void         Terminate();

	int          getStatut();

	const char*  getError();
	 
	int          getNbOeuf();

	int          getPontes(char ***pontes);

};

