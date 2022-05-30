#include "pch.h"
#include "Periph.h"

Periph::Periph(std::wstring _port, int _baud, int _nbDataBits, int _parity, int _nbStopBits, std::string _SN, int _debug, std::string _pathDebugFile) {

	comRS.Open(LPCTSTR(&_port[0]));

	comRS.Setup(   CSerial::EBaudrate(_baud)           ,
		           CSerial::EDataBits(_nbDataBits)     ,
				   CSerial::EParity(NOPARITY)          ,
				   CSerial::EStopBits(_nbStopBits)     );

	comRS.SetupHandshaking(CSerial::EHandshakeHardware);
	comRS.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);

	SN            = _SN;
	debugMode     = _debug;
	pathDebugFile = _pathDebugFile;

	if (debugMode == 1) WriteInDebugFile("*********** CONSTRUCTION PERIPH ***********");

}

Periph::~Periph() {

	comRS.Close();

	if (debugMode == 1) WriteInDebugFile("*********** DESTRUCTION PERIPH ***********");

}

int Periph::getTrame(std::string* trame) {

	int res;

	BYTE  BufferTrame[BUFFER_SIZE];
	DWORD dwBytesRead;

	*trame = "";

	do {

		comRS.Read(BufferTrame, sizeof(BufferTrame), &dwBytesRead);

		if (dwBytesRead > 0) trame->append(reinterpret_cast<char*>(BufferTrame));

	} while (dwBytesRead == sizeof(BufferTrame));

	if (trame->size() > 0)
		res = 1;
	else
		res = -1;

	if (debugMode == 1) {

		char* logGet = (char*) malloc(sizeof(char) * STR_SIZE);

		snprintf(logGet, STR_SIZE, "Periph::getTrame trame = %s", trame->c_str());

		WriteInDebugFile(logGet);

	}

	return res;

}

int Periph::WriteInDebugFile(std::string _line) {

	std::ofstream FileDebug;

	try {FileDebug.open(pathDebugFile);} catch(int e) {exit(-1);}

	FileDebug << _line + '\n';

	FileDebug.close();

	return 1;

}
