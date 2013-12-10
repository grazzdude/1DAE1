#pragma once
//-----------------------------------------------------
// Name:
// First name:
// Group: 1DAE.
//-----------------------------------------------------

//-----------------------------------------------------
// Include Files
//-----------------------------------------------------
#include "GameEngine.h"

//-----------------------------------------------------
// Balls Class									
//-----------------------------------------------------
class Balls
{
public:
	Balls();				// Constructor
	virtual ~Balls();		// Destructor

	//-------------------------------------------------
	// Methods - Member functions							
	//-------------------------------------------------
	void DrawBall(POINT Position, int Size=10);
	POINT CalculateMovementBall(POINT Position, POINT Displacement, POINT Sense);
	POINT BallLost(POINT PaddlePosition, POINT PaddleSize,POINT BallPosition, POINT BallSense, int Size=10);
	POINT ReflectionWalls(POINT Position, POINT Sense, int Size=10);
	POINT ReflectionPaddle(POINT PaddlePosition, POINT PaddleSize,POINT BallPosition, POINT BallSense, int BallSize=10);
	void DrawPaddle(POINT Position, POINT Size,COLOR Color = COLOR(255,150,0));
	POINT CalculateMovementPaddle(POINT Position, POINT PaddleSize);

private: 
	// -------------------------
	// Datamembers
	// -------------------------
	//COLOR m_BallsColor;
	
	// -------------------------
	// Disabling default copy constructor and default 
	// assignment operator.
	// -------------------------
	Balls(const Balls& yRef);									
	Balls& operator=(const Balls& yRef);	
};

 
