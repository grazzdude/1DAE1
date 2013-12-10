//-----------------------------------------------------------------
// Game File
// C++ Source - ArraysAdv1Lab.cpp - version v2_12 jan 2013 
// Copyright Kevin Hoefman - kevin.hoefman@howest.be
// http://www.digitalartsandentertainment.be/
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ArraysAdv1Lab.h"																				

//-----------------------------------------------------------------
// Defines
//-----------------------------------------------------------------
#define GAME_ENGINE (GameEngine::GetSingleton())

//-----------------------------------------------------------------
// ArraysAdv1Lab methods																				
//-----------------------------------------------------------------

ArraysAdv1Lab::ArraysAdv1Lab()
{
	for (int i = 0; i < MAX_EVEN; i++)
	{
		m_EvenArr[i] = 0;
	}

	for (int i = 0; i < MAX_RAND; i++)
	{
		m_RandArr[i] = 0;
	}
}

ArraysAdv1Lab::~ArraysAdv1Lab()																						
{
	// nothing to destroy
}

void ArraysAdv1Lab::GameInitialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::GameInitialize(hInstance);
	GAME_ENGINE->SetTitle("ArraysAdv1Lab - Atac Ilyas - 1DAE1");					
	GAME_ENGINE->RunGameLoop(false);
	
	// Set the optional values
	GAME_ENGINE->SetWidth(640);
	GAME_ENGINE->SetHeight(480);
	//GAME_ENGINE->SetKeyList(String("QSDZ") + (TCHAR) VK_SPACE);
}

void ArraysAdv1Lab::GameStart()
{
	
	
	for (int i = 1; i < MAX_RAND; i++)
	{
		m_RandArr[i] = rand()%10;
		m_EvenArr[i] = i*2;
	}
}

void ArraysAdv1Lab::GameEnd()
{
	// Insert the code that needs to be executed at the closing of the game
}

void ArraysAdv1Lab::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse button action

	/* Example:
	if (isLeft == true && isDown == true) // is it a left mouse click?
	{	
		if ( x > 261 && x < 261 + 117 ) // check if click lies within x coordinates of choice
		{
			if ( y > 182 && y < 182 + 33 ) // check if click also lies within y coordinates of choice
			{
				GAME_ENGINE->MessageBox("Clicked.");
			}
		}
	}
	*/
}

void ArraysAdv1Lab::MouseMove(int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the mouse pointer moves across the game window

	/* Example:
	if ( x > 261 && x < 261 + 117 ) // check if mouse position is within x coordinates of choice
	{
		if ( y > 182 && y < 182 + 33 ) // check if mouse position also is within y coordinates of choice
		{
			GAME_ENGINE->MessageBox("Da mouse wuz here.");
		}
	}
	*/

}

void ArraysAdv1Lab::CheckKeyboard()
{	
	// Here you can check if a key of choice is held down
	// Is executed once per frame when the gameloop is running

	/* Example:
	if (GAME_ENGINE->IsKeyDown('K')) xIcon -= xSpeed;
	if (GAME_ENGINE->IsKeyDown('L')) yIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown('M')) xIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown('O')) yIcon -= ySpeed;
	*/
}

void ArraysAdv1Lab::KeyPressed(TCHAR cKey)
{	
	// DO NOT FORGET to use SetKeyList() !!

	// Insert the code that needs to be executed when a key of choice is pressed
	// Is executed as soon as the key is released
	// You first need to specify the keys that the game engine needs to watch by using the SetKeyList() method

	/* Example:
	switch (cKey)
	{
	case 'K': case VK_LEFT:
		MoveBlock(DIR_LEFT);
		break;
	case 'L': case VK_DOWN:
		MoveBlock(DIR_DOWN);
		break;
	case 'M': case VK_RIGHT:
		MoveBlock(DIR_RIGHT);
		break;
	case 'A': case VK_UP:
		RotateBlock();
		break;
	case VK_ESCAPE:
	}
	*/
}

void ArraysAdv1Lab::GameTick(double deltaTime)
{
	// Insert the code that needs to be executed, EXCEPT for paint commands (see next method)

}

void ArraysAdv1Lab::GamePaint(RECT rect)
{
	PrintRow(m_EvenArr,MAX_EVEN,25,25);
	PrintRow(m_RandArr,MAX_RAND,25,60);
}

void ArraysAdv1Lab::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}

void PrintRow(int *numberArr, int size, int x, int y)
{
	String str = String("") + numberArr[0];
	for (int i = 1; i < size; i++)
	{
		str += "," + numberArr[i];
	}
	GAME_ENGINE->DrawString(String(",") + str,x,y);
}



