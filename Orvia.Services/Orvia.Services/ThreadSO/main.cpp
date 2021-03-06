
#include "ThreadNid.h"

// **********************************************************************************************************
//  Functions to export
// **********************************************************************************************************

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// CreateThread /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

ThreadNid*                        CreateThread(     char*       _deviceBalance  ,
                                                    char*       _deviceRFID     ,

						                            int			_baud           ,
					                                int			_nbDataBits     ,
						                            int			_parity         ,        
						                            int			_nbStopBits     ,

						                            char*       _SNAntenne      ,
						                            char*       _SNBalance      ,

						                            double      _minPoidsOeuf   ,
						                            double      _maxPoidsOeuf   ,
						                            double      _minPoidsPoule  ,
						                            double      _maxPoidsPoule  ,  

						                            int			_debug          ,
						                            char*       _pathDebugFile		)
{

    ThreadNid *threadNid = new ThreadNid(   _deviceBalance, _deviceRFID, _baud, _nbDataBits, _parity, _nbStopBits, _SNAntenne, _SNBalance,
                                            _minPoidsOeuf, _maxPoidsOeuf, _minPoidsPoule, _maxPoidsPoule,
                                            _debug, _pathDebugFile                                                                           );

    return threadNid;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// KillThread /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


void KillThread(ThreadNid* threadNid)
{

    threadNid->Terminate();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// WakeUpThread /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int WakeUpThread(ThreadNid* threadNid)
{

    return threadNid->WakeUpThread();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// getStatut /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


int getStatut(ThreadNid* threadNid)
{

    return threadNid->getStatut();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// getError /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


const char* getError(ThreadNid* threadNid)
{

    return threadNid->getError();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// getNbOeuf /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


int getNbOeuf(ThreadNid* threadNid)
{

    return threadNid->getNbOeuf();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// getPontes /////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


int getPontes(ThreadNid* threadNid, char ***pontes)
{

    int ret;

    ret = threadNid->getPontes(pontes);

    return ret; 

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
