//-----------------------------------------------------------------
// Game File
// C++ Source - Breakout.cpp - version v2_12 jan 2013 
// Copyright Kevin Hoefman - kevin.hoefman@howest.be
// http://www.digitalartsandentertainment.be/
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Breakout.h"																				

//-----------------------------------------------------------------
// Defines
//-----------------------------------------------------------------
#define GAME_ENGINE (GameEngine::GetSingleton())

//-----------------------------------------------------------------
// Breakout methods																				
//-----------------------------------------------------------------

Breakout::Breakout()	:m_BreakBallPtr(nullptr)
{
	// nothing to create
}

Breakout::~Breakout()																						
{
	// nothing to destroy
}

void Breakout::GameInitialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::GameInitialize(hInstance);
	GAME_ENGINE->SetTitle("Breakout - Name First name - group");					
	GAME_ENGINE->RunGameLoop(true);
	
	// Set the optional values
	GAME_ENGINE->SetWidth(640);
	GAME_ENGINE->SetHeight(480);
	//GAME_ENGINE->SetKeyList(String("QSDZ") + (TCHAR) VK_SPACE);
}

void Breakout::GameStart()
{
	m_BreakBallPtr = new Balls();
	//m_BallsColor = COLOR(rand()%255,rand()%255,rand()%255);
	m_BallPosition.x = 50;
	m_BallPosition.y = 150;
	m_BallDisplacement.x = 3;
	m_BallDisplacement.y = 3;
	m_BallSense.x = 1;
	m_BallSense.y = 1;
	
	m_PaddlePosition.x = 270;
	m_PaddlePosition.y = 400;
	m_PaddleSize.x = 100;
	m_PaddleSize.y = 25;
}

void Breakout::GameEnd()
{
	// Insert the code that needs to be executed at the closing of the game
}

void Breakout::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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

void Breakout::MouseMove(int x, int y, WPARAM wParam)
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

void Breakout::CheckKeyboard()
{	
	m_PaddlePosition = m_BreakBallPtr->CalculateMovementPaddle(m_PaddlePosition,m_PaddleSize);
}

void Breakout::KeyPressed(TCHAR cKey)
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

void Breakout::GameTick(double deltaTime)
{
	m_BallPosition = m_BreakBallPtr->BallLost(m_PaddlePosition,m_PaddleSize,m_BallPosition,m_BallSense);
	m_BallPosition = m_BreakBallPtr->CalculateMovementBall(m_BallPosition,m_BallDisplacement,m_BallSense);
	m_BallSense = m_BreakBallPtr->ReflectionWalls(m_BallPosition,m_BallSense);
	m_BallSense = m_BreakBallPtr->ReflectionPaddle(m_PaddlePosition,m_PaddleSize,m_BallPosition,m_BallSense);
}

void Breakout::GamePaint(RECT rect)
{

	m_BreakBallPtr->DrawBall(m_BallPosition);
	m_BreakBallPtr->DrawPaddle(m_PaddlePosition,m_PaddleSize);
}

void Breakout::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}





