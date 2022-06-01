#pragma once

// **********************************************************************************************************
//  Enum Class Periph
// **********************************************************************************************************

//__________________________
// ::: State thread nest :::
// -1 : Error
// 0  : Sleep
// 1  : ON

enum class Etat {

	ERREUR  = -1,
	SOMMEIL = 0,
	MARCHE  = 1

};