#pragma once

// pch.h : Il s'agit d'un fichier d'en-tête précompilé.
// Les fichiers listés ci-dessous sont compilés une seule fois, ce qui améliore les performances de génération des futures builds.
// Cela affecte également les performances d'IntelliSense, notamment la complétion du code et de nombreuses fonctionnalités de navigation du code.
// Toutefois, les fichiers listés ici sont TOUS recompilés si l'un d'entre eux est mis à jour entre les builds.
// N'ajoutez pas de fichiers fréquemment mis à jour ici, car cela annule les gains de performance.

#ifndef PCH_H
#define PCH_H

#if defined (_WIN32) || defined( _WIN64)
    #include "framework.h"
#endif

#include "serialib.h"

#include "Periph.h"
#include "Periph_Balance.h"
#include "Periph_RFID.h"

#include "Nid.h"
#include "ThreadNid.h"

#include "Etat.h"

#include "Functions.h"

#endif //PCH_H
