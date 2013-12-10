//-----------------------------------------------------------------
// Game Engine WinMain Function
// C++ Source - GameWinMain.cpp - version v2_12 jan 2013 
// Copyright Kevin Hoefman, Bart Uyttenhove, Peter Verswyvelen
// http://www.digitalartsandentertainment.be/
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "GameWinMain.h"
#include "GameEngine.h"


#include "Breakout.h"	
	
//-----------------------------------------------------------------
// Defines
//-----------------------------------------------------------------

#define GAME_ENGINE (GameEngine::GetSingleton())

//-----------------------------------------------------------------
// Windows Functions
//-----------------------------------------------------------------
int _tmain()
{
       WinMain(GetModuleHandle(0), 0, 0, SW_SHOW);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{

	// Enable run-time memory leak check for debug builds.
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

		//_CrtSetBreakAlloc(111);
	#endif
		


	/////////////////////////////////////////////////////
	if (GAME_ENGINE == nullptr) return FALSE; // create the game engine and exit if it fails

	GAME_ENGINE->SetGame(new Breakout());	

	bool returnValue =  GAME_ENGINE->Run(hInstance, iCmdShow); // run the game engine and return the result
	/////////////////////////////////////////////////////

	return returnValue;

}
