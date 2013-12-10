//-----------------------------------------------------------------
// Game File
// C++ Header - ArraysAdv1Lab.h - version version v2_12 jan 2013 
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

//-----------------------------------------------------------------
// ArraysAdv1Lab Class																
//-----------------------------------------------------------------
class ArraysAdv1Lab : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s)
	//---------------------------
	ArraysAdv1Lab();

	//---------------------------
	// Destructor
	//---------------------------
	virtual ~ArraysAdv1Lab();

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
	void PrintRow(int *numberArr, int size, int x, int y);
	// -------------------------
	// Datamembers
	// -------------------------
	static const int MAX_EVEN=10;
	static const int MAX_RAND=15;

	int m_EvenArr[MAX_EVEN],m_RandArr[MAX_RAND];

	// -------------------------
	// Disabling default copy constructor and default assignment operator.
	// If you get a linker error from one of these functions, your class is internally trying to use them. This is
	// an error in your class, these declarations are deliberately made without implementation because they should never be used.
	// -------------------------
	ArraysAdv1Lab(const ArraysAdv1Lab& tRef);
	ArraysAdv1Lab& operator=(const ArraysAdv1Lab& tRef);
};
