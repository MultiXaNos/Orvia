// dllmain.cpp : Définit le point d'entrée de l'application DLL.

#include "pch.h"

__declspec(dllexport) ThreadNid*  CreateThread(     std::string _port           ,
						                            int			_baud           ,
					                                int			_nbDataBits     ,
						                            int			_parity         ,        
						                            int			_nbStopBits     ,

						                            std::string _SNAntenne      ,
						                            std::string _SNBalance      ,

						                            double      _minPoidsOeuf   ,
						                            double      _maxPoidsOeuf   ,
						                            double      _minPoidsPoule  ,
						                            double      _maxPoidsPoule  ,  

						                            int			_debug          ,
						                            std::string _pathDebugFile			)
{

    ThreadNid *threadNid = new ThreadNid(   _port, _baud, _nbDataBits, _parity, _nbStopBits, _SNAntenne, _SNBalance,
                                            _minPoidsOeuf, _maxPoidsOeuf, _minPoidsPoule, _maxPoidsPoule,
                                            _debug, _pathDebugFile                                                  );

    return threadNid;

}

__declspec(dllexport) void KillThread(ThreadNid* threadNid)
{

    threadNid->Terminate();

}

__declspec(dllexport) int WakeUpThread(ThreadNid* threadNid)
{

    return threadNid->WakeUpThread();

}

__declspec(dllexport) int getStatut(ThreadNid* threadNid)
{

    return threadNid->getStatut();

}

__declspec(dllexport) const char* getError(ThreadNid* threadNid)
{

    return threadNid->getError();

}

__declspec(dllexport) int getNbOeuf(ThreadNid* threadNid)
{

    return threadNid->getNbOeuf();

}

__declspec(dllexport) int getPontes(ThreadNid* threadNid, char ***pontes)
{

    int ret;

    ret = threadNid->getPontes(pontes);

    return ret; 

}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

