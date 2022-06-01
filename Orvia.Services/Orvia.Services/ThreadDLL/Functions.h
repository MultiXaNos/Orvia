#pragma once

#include <fstream>
#include <string>

#include <time.h>
#include <stdio.h>

//____________________________
// ::: Utilities Functions :::

// Write into Debug file
int WriteInDebugFile(std::string _line, std::string _pathDebugFile);

// Get time of day (Windows)
int _gettimeofday(struct timeval* p, void* tz);