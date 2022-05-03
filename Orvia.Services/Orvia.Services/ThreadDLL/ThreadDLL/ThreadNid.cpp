#include "pch.h"
#include "ThreadNid.h"

ThreadNid::ThreadNid(	std::string _port,
						int			_baud,
					    int			_nbDataBits,
						int			_parity,
						int			_nbStopBits,

						std::string _SNAntenne,
						std::string _SNBalance,

						double      _minPoidsOeuf,
						double      _maxPoidsOeuf,
						double      _minPoidsPoule,
						double      _maxPoidsPoule,

						int			_debug,
						std::string _pathDebugFile			)
{

	nid    = new Nid(_port, _baud, _nbDataBits, _parity, _nbStopBits, _SNAntenne, _SNBalance, _minPoidsOeuf, _maxPoidsOeuf, _minPoidsPoule, _maxPoidsPoule, _debug, _pathDebugFile); 

	statut = Etat::SOMMEIL;

	t      = std::thread(&ThreadNid::Execute, this);

}

ThreadNid::~ThreadNid()
{

	t.join();

	delete nid;

}

void ThreadNid::Execute()
{

	int ret = 0;

	while (threadTerminate == true)
	{

		while (threadStop == false)
		{

			ret = nid->refresh(&sError);

			switch (ret) {

				case -1 : statut = Etat::ERREUR  ; threadStop = true  ; break;
				case 0  : statut = Etat::SOMMEIL ; threadStop = true  ; break;
				case 1  : statut = Etat::MARCHE					      ; break;

			}

			std::this_thread::sleep_for(std::chrono::milliseconds(100));

		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}

}

int ThreadNid::WakeUpThread()
{

	int ret = nid->PalmiOnBalance(&sError);

	switch (ret) {

		case -1 : statut = Etat::ERREUR  ; break;
		case 0  : statut = Etat::SOMMEIL ; break;
		case 1  : statut = Etat::MARCHE  ; break;

	}

	if (statut == Etat::MARCHE)
		threadStop = false;

	return ret;

}

void ThreadNid::Terminate()
{

	threadStop      = false;
	threadTerminate = true;

}

int ThreadNid::getStatut()
{

	int ret = 0;

	switch (statut) {

		case  Etat::ERREUR  :  ret = -1 ; break;
		case  Etat::SOMMEIL :  ret = 0  ; break;
		case  Etat::MARCHE  :  ret = 1  ; break;

	}

	return ret;

}

const char* ThreadNid::getError()
{

	return sError.c_str();

}

int ThreadNid::getNbOeuf()
{

	return nid->getNbOeuf();

}

int ThreadNid::getPontes(char ***pontes)
{

	std::list< std::list<std::string> > allPontes;

	int nbColonne;
	int nbLigne;

	int i;
	int j;

	int ret;

	ret = nid->getPontes(&allPontes);

	if(ret <=0) exit(0);

	nbLigne = allPontes.size();
	nbColonne = 3;

	pontes = malloc( nbLigne * (**pontes) );    // Allocation mémoire

	for(i = 0; i < nbLigne; i++)    
	{

		pontes[i] = malloc( nbLigne * sizeof(*pontes) );

		for(j = 0; j < nbColonne; j++)
			pontes[i][j] = malloc( sizeof( (std::string) allPontes[i][j].length ) );

    }

	for(i = 0; i < nbLigne; i++)               // Remplissage tableau
	{

		for(j = 0; j < nbColonne; j++)
			pontes[i][j] = (std::string) allPontes[i][j].c_str();

    }
	

	return ret;

}