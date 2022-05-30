// dllmain.cpp : Définit le point d'entrée de l'application DLL.

#include "pch.h"

__declspec(dllexport) ThreadNid*  CreateThread(     const char* _portBalance    ,
                                                    const char* _portRFID       ,
						                            int			_baud           ,
					                                int			_nbDataBits     ,
						                            int			_parity         ,        
						                            int			_nbStopBits     ,

						                            char* _SNAntenne      ,
						                            char* _SNBalance      ,

						                            double      _minPoidsOeuf   ,
						                            double      _maxPoidsOeuf   ,
						                            double      _minPoidsPoule  ,
						                            double      _maxPoidsPoule  ,  

						                            int			_debug          ,
						                            char* _pathDebugFile			)
{

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    std::wstring portBalance = converter.from_bytes(_portBalance);
    std::wstring portRFID = converter.from_bytes(_portRFID);

    ThreadNid *threadNid = new ThreadNid(   portBalance, portRFID, _baud, _nbDataBits, _parity, _nbStopBits, _SNAntenne, _SNBalance,
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

