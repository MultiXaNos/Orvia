#include "pch.h"

Nid::Nid	(std::string _deviceBalance		,
			std::string  _deviceRFID		,
			int          _baud				,
			int          _nbDataBits		,
			int          _parity			,
			int          _nbStopBits		,

			std::string  _SNBalance			,
			std::string  _SNAntenne			,

			double       _minPoidsOeuf	    ,
			double       _maxPoidsOeuf   	,
			double       _minPoidsPoule		,
			double       _maxPoidsPoule		,

			int          _debug				,
			std::string  _pathDebugFile			)
{

	periphBalance = new PeriphBalance( _SNBalance, _debug, _pathDebugFile, _deviceBalance, _baud, _nbDataBits, _parity, _nbStopBits);
	periphRFID    = new PeriphRFID(	_SNAntenne, _debug, _pathDebugFile , _deviceRFID, _baud, _nbDataBits, _parity, _nbStopBits);

	minPoidsOeuf  = _minPoidsOeuf;
	maxPoidsOeuf  = _maxPoidsOeuf;

	minPoidsPoule = _minPoidsPoule;
	maxPoidsPoule = _maxPoidsPoule;
	
	nbOeufs = 0;

}

Nid::~Nid()
{

	delete periphBalance;
	delete periphRFID;

}

int  Nid::PalmiOnBalance(std::string * sError)
{

	int ret;

	std::string SNAntenne = "";
	std::string tagRFID   = "";

	double poids = -1;

	ret = periphRFID->getTags(&SNAntenne, &tagRFID);
	if (ret == -1) *sError = "Erreur : Communication avec l'antenne" ; ret = -1;

	ret = periphBalance->getPoids(&poids);
	if (ret == -1) *sError = "Erreur : Communication avec la balance"; ret = -1;


	if (ret > -1) {

		if (tagRFID == "") {

			ret = 0;

			if (poids < nbOeufs * minPoidsOeuf) reset();  // On regarde si les �ventuels oeufs enregistr�s ont �t� retir�s

		}
		else
			if (poids > nbOeufs * maxPoidsOeuf) ret = 1; else ret = 0;

	}

	return ret;

}

int  Nid::refresh(std::string* sError)
{

	int ret = 1;

	double poids              = 0;

	double poidsOeufTotalMin  = 0;
	double poidsOeufTotalMax  = 0;

	double poidsPouleTotalMin = 0;
	double poidsPouleTotalMax = 0;

	double poidsTotalMin      = 0;
	double poidsTotalMax      = 0;

	std::string SNAntenne    = "";
	std::string firstTagRFID = "";
	std::string tagRFID      = "";

	std::list<std::string> tagsRFID;

	ret = periphRFID->getTags(&SNAntenne, &firstTagRFID);
	if (ret == -1) *sError = "Erreur : Communication avec l'antenne"; tagsRFID.clear(); exit(-1);

	if (firstTagRFID == "") exit(0);
	else {

		tagsRFID.push_back(firstTagRFID);

		while ((tagRFID != firstTagRFID) and (ret > -1)) {

			if (tagRFID != "") tagsRFID.push_back(tagRFID);

			Sleep(500);

			ret = periphRFID->getTags(&SNAntenne, &tagRFID);

			if (ret == -1) *sError = "Erreur : Communication avec l'antenne"; tagsRFID.clear(); exit(-1);

		}

	}

	Sleep(50);

	ret = periphBalance->getPoids(&poids);
	if (ret == -1) *sError = "Erreur : Communication avec la balance"; exit(-1);

	poidsOeufTotalMin  = nbOeufs * minPoidsOeuf;
	poidsOeufTotalMax  = nbOeufs * maxPoidsOeuf;

	poidsPouleTotalMin = tagsRFID.size() * minPoidsPoule;
	poidsPouleTotalMax = tagsRFID.size() * maxPoidsPoule;

	poidsTotalMin      = poidsOeufTotalMin + poidsPouleTotalMin;
	poidsTotalMax      = poidsOeufTotalMax + poidsPouleTotalMax;

	if ( (poids >= poidsTotalMin + minPoidsOeuf) && (poids <= poidsTotalMin + maxPoidsOeuf) )  // On a un oeuf en plus
		nbOeufs += 1;

	if (tagsRFID.size() == 1)             // On a qu'une poule sur la balance, on est s�r de la provenance de la ponte
		addPonte(&firstTagRFID, &pontes);
	else {                                // Plusieurs tags, on ne sait pas quel palmi a pondu 

		for (std::list<std::string>::iterator it = tagsRFID.begin(); it != tagsRFID.end(); it++) {

			addPonte((std::string *) &it, &pontesPotentielles);

		}

	}

	tagsRFID.clear();

	return ret;

}

void Nid::reset()
{

	nbOeufs = 0;

	pontes.clear();
	pontesPotentielles.clear();

}

void Nid::addPonte(std::string* tagRFID, std::map<std::string, int>* pontes)
{

	if( pontes->find(*tagRFID) == pontes->end() )        // trouv�
		pontes->at(*tagRFID) = pontes->at(*tagRFID) + 1;
	else 
		pontes->insert(std::pair<std::string, int>(*tagRFID, 1));

}

int Nid::getPontes(std::list< std::list<std::string> > *allPontes)
{

	int ret = 1;

	std::list<std::string> ponte;

	std::map<std::string, int>::iterator it;

	allPontes->clear();

	if (pontes.size() <= 0 && pontesPotentielles.size() <= 0) ret = 0;

	if (ret < 1)
	{

		for (it = pontes.begin(); it != pontes.end(); ++it)  
		{

			if ( pontesPotentielles.find(it->first) == pontesPotentielles.end() )        // trouv�
			{

				ponte.push_back(it->first);
				ponte.push_back( std::to_string( (int) it->second + pontesPotentielles.at(it->first) ) );
				ponte.push_back( std::to_string( pontesPotentielles.at(it->first) ) );

			}
			else
			{

				ponte.push_back(it->first);
				ponte.push_back( std::to_string( (int) it->second ) );
				ponte.push_back( std::to_string(0) );

			}

			allPontes->push_back(ponte);

			pontes.clear();

		}

		for (it = pontesPotentielles.begin(); it != pontesPotentielles.end(); ++it)
		{

			if (pontes.find(it->first) != pontes.end())        // pas trouv�
			{

				ponte.push_back(it->first);
				ponte.push_back( std::to_string( (int) it->second ) );
				ponte.push_back( std::to_string( (int) it->second ) );

			}

			allPontes->push_back(ponte);

			pontes.clear();

		}

	}

	return ret;

}

int  Nid::getNbOeuf()
{

	return nbOeufs;

}