#include "main.h"
#pragma comment(lib, "psapi.lib")

int main()
{
	std::cout << "[ ## ] hSonic Bypass demo - By harakirinox, JYam, and mistree @ UnknownCheats.me" << std::endl;
	std::cout << "[ ?? ] Internals: Outruns kernel notification routines with job objects (using method from PcaSvc)" << std::endl;
	std::cout << std::endl;
	std::cout << "[ !! ] Requires to know the parent of target process (e.g. Steam.exe for steam games, explorer for some others ...)" << std::endl;
	std::cout << "[ !! ] Use Process Hacker or Process Explorer to find parent processes easily" << std::endl;
	std::cout << std::endl;

	/* Prompts user for the process name to get a handle on and its parent */
	std::string szProcessName = "";
	std::cout << "[ -- ] Process name to get a handle on (e.g. Game.exe):" << std::endl;
	std::cout << "[ >> ] ";
	std::getline(std::cin, szProcessName);
	std::transform(szProcessName.begin(), szProcessName.end(), szProcessName.begin(), tolower);

	std::string szParentName = "";
	std::cout << "[ -- ] Enter parent name (e.g. Steam.exe, leave blank to use explorer.exe):" << std::endl;
	std::cout << "[ >> ] ";
	std::getline(std::cin, szParentName);
	std::transform(szParentName.begin(), szParentName.end(), szParentName.begin(), tolower);

	std::cout << "[ !! ] Ready to get handle, please start target program." << std::endl;

	HANDLE hGame = GetSonicHandle(szParentName, szProcessName, PROCESS_ALL_ACCESS, FALSE);
	//HANDLE hGame = GetSonicHandle("Steam.exe", "Game.exe", PROCESS_ALL_ACCESS, FALSE); // Only use this in your cheat

	std::cout << "[ :) ] Got Handle ID: 0x" << std::hex << hGame << std::endl;
	std::cout << "[ .. ] Press ENTER to exit when you are done verifying handle (e.g. with Process Hacker or Process Explorer)" << std::endl;
	std::cin.get();

	return EXIT_SUCCESS;
}

