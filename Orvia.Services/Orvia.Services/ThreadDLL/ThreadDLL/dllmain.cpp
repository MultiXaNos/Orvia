// dllmain.cpp : Définit le point d'entrée de l'application DLL.

#include "pch.h"

__declspec(dllexport) ThreadNid* CreateThread(     std::string _port           ,
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

void __declspec(dllexport) KillThread(ThreadNid* threadNid)
{

    threadNid->Terminate();
    delete threadNid;

}

int __declspec(dllexport) WakeUpThread(ThreadNid* threadNid)
{

    return threadNid->WakeUpThread();

}

int __declspec(dllexport) getStatut(ThreadNid* threadNid)
{

    return threadNid->getStatut();

}

__declspec(dllexport) const char* getError(ThreadNid* threadNid)
{

    return threadNid->getError();

}

int __declspec(dllexport) getNbOeuf(ThreadNid* threadNid)
{

    return threadNid->getNbOeuf();

}

int __declspec(dllexport) getPontes(ThreadNid* threadNid, char ***pontes)
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

