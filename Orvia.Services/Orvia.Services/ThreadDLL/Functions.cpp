#include "pch.h"

int WriteInDebugFile(std::string _line, std::string _pathDebugFile) {

	std::ofstream FileDebug;

	try { FileDebug.open(_pathDebugFile); }
	catch (const int e) { exit(-1); }

	FileDebug << _line + '\n';

	FileDebug.close();

	return 1;

}

int _gettimeofday(struct timeval* p, void* tz) {

    ULARGE_INTEGER ul; // As specified on MSDN.
    FILETIME ft;

    // Returns a 64-bit value representing the number of
    // 100-nanosecond intervals since January 1, 1601 (UTC).
    GetSystemTimeAsFileTime(&ft);

    // Fill ULARGE_INTEGER low and high parts.
    ul.LowPart = ft.dwLowDateTime;
    ul.HighPart = ft.dwHighDateTime;
    // Convert to microseconds.
    ul.QuadPart /= 10ULL;
    // Remove Windows to UNIX Epoch delta.
    ul.QuadPart -= 11644473600000000ULL;
    // Modulo to retrieve the microseconds.
    p->tv_usec = (long)(ul.QuadPart % 1000000LL);
    // Divide to retrieve the seconds.
    p->tv_sec = (long)(ul.QuadPart / 1000000LL);

    return 0;

}