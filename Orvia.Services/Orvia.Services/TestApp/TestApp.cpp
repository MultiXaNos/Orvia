// TestApp.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "../ThreadDLL/pch.h"
#include <locale>
#include <codecvt>
#include <string>

int main()
{

    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    const char* COM1 = (char*) malloc(sizeof(char) * 5);
    const char* COM3 = (char*) malloc(sizeof(char) * 5);

    std::string myStr = "COM1";
    std::string myStr2 = "COM3";

    COM1 = myStr.c_str();
    COM3 = myStr2.c_str();

    std::wstring portBalance = converter.from_bytes(COM1);
    std::wstring portRFID = converter.from_bytes(COM3);

    std::string SNAntenne = "SNAntenne";
    std::string SNBalance = "SNBalance";
    std::string PathDebugFile = "C:\\Users\\proje\\Desktop\\Logs.txt";
    ThreadNid* thread = new ThreadNid(portBalance, portRFID, 9600, 8, 0, 1, SNAntenne, SNBalance, 50, 60, 300, 400, 1, PathDebugFile);

    thread->WakeUpThread();
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
