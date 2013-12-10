//-----------------------------------------------------------------
// Game File
// C++ Header - Breakout.h - version version v2_12 jan 2013 
// Copyright Kevin Hoefman - kevin.hoefman@howest.be
// http://www.digitalartsandentertainment.be/
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Student data
// Name:
// Group:
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"
#include "Balls.h"

//-----------------------------------------------------------------
// Breakout Class																
//-----------------------------------------------------------------
class Breakout : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s)
	//---------------------------
	Breakout();

	//---------------------------
	// Destructor
	//---------------------------
	virtual ~Breakout();

	//---------------------------
	// General Methods
	//---------------------------

	void GameInitialize(HINSTANCE hInstance);
	void GameStart();				
	void GameEnd();
	void MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam);
	void MouseMove(int x, int y, WPARAM wParam);
	void CheckKeyboard();
	void KeyPressed(TCHAR cKey);
	void GameTick(double deltaTime);
	void GamePaint(RECT rect);

	void CallAction(Caller* callerPtr);

	// -------------------------
	// Member functions
	// -------------------------

private:
	// -------------------------
	// Member functions
	// -------------------------

	// -------------------------
	// Datamembers
	// -------------------------

	Balls * m_BreakBallPtr;
	//COLOR m_BallsColor;
	POINT m_BallPosition,m_BallDisplacement,m_BallSense;
	POINT m_PaddlePosition,m_PaddleSize;
	static const int BallsAmount = 5;

	// -------------------------
	// Disabling default copy constructor and default assignment operator.
	// If you get a linker error from one of these functions, your class is internally trying to use them. This is
	// an error in your class, these declarations are deliberately made without implementation because they should never be used.
	// -------------------------
	Breakout(const Breakout& tRef);
	Breakout& operator=(const Breakout& tRef);
};
