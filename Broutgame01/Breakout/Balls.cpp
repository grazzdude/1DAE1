//---------------------------
// Includes
//---------------------------
#include "Balls.h"

//---------------------------
// Defines
//---------------------------
#define GAME_ENGINE (GameEngine::GetSingleton())

//---------------------------
// Constructor & Destructor
//---------------------------
Balls::Balls()
{
	// nothing to create
}

Balls::~Balls()
{
	// nothing to destroy
}

//---------------------------
// Methods - Member functions
//---------------------------

POINT Balls::CalculateMovementBall(POINT Position, POINT Displacement, POINT Sense)
{
	Position.x = Position.x + Displacement.x * Sense.x;
	Position.y = Position.y + Displacement.y * Sense.y;

	return Position;
}

void Balls::DrawBall(POINT Position, int Size)
{
	GAME_ENGINE->FillEllipse(Position.x,Position.y,Size,Size);
}

POINT Balls::ReflectionWalls(POINT Position, POINT Sense, int Size)
{
	if (Position.x >= GAME_ENGINE->GetWidth()-Size && Sense.x > 0)
	{
		Sense.x = Sense.x * -1;
	}

	if (Position.y <= Size && Sense.y < 0)
	{
		Sense.y = Sense.y * -1;
	}

	if (Position.x <= Size && Sense.x < 0)
	{
		Sense.x = Sense.x * -1;
	}

	return Sense;
}

void Balls::DrawPaddle(POINT Position, POINT Size,COLOR Color)
{
	GAME_ENGINE->SetColor(Color);
	GAME_ENGINE->FillRoundedRect(Position.x,Position.y,Position.x+Size.x,Position.y + Size.y,10,10);
	GAME_ENGINE->SetColor(COLOR(0,0,0));
}

POINT Balls::CalculateMovementPaddle(POINT Position, POINT PaddleSize)
{
	if (GAME_ENGINE->IsKeyDown('A') && Position.x>0) Position.x = Position.x + 10 * -1;
	if (GAME_ENGINE->IsKeyDown('D') && GAME_ENGINE->GetWidth() > Position.x+PaddleSize.x) Position.x = Position.x + 10 * 1;
	return Position;
}

POINT Balls::ReflectionPaddle(POINT PaddlePosition, POINT PaddleSize,POINT BallPosition, POINT BallSense, int BallSize)
{
	if (BallPosition.y == PaddlePosition.y-BallSize && BallPosition.x > PaddlePosition.x-BallSize && BallPosition.x < PaddlePosition.x+PaddleSize.x)
	{
		BallSense.y = BallSense.y * -1;
	}

	if (BallPosition.y == PaddlePosition.y+PaddleSize.y+BallSize && BallPosition.x > PaddlePosition.x-BallSize && BallPosition.x < PaddlePosition.x+PaddleSize.x)
	{
		BallSense.y = BallSense.y * -1;
	}

	if (BallPosition.x+BallSize == PaddlePosition.x && BallPosition.y > PaddlePosition.y && BallPosition.y < PaddlePosition.y+PaddleSize.y)
	{
		BallSense.x = BallSense.x * -1;
	}

	if (BallPosition.x-BallSize == PaddlePosition.x+PaddleSize.x && BallPosition.y > PaddlePosition.y && BallPosition.y < PaddlePosition.y+PaddleSize.y)
	{
		BallSense.x = BallSense.x * -1;
	}

	return BallSense;
}

POINT Balls::BallLost(POINT PaddlePosition, POINT PaddleSize,POINT BallPosition, POINT BallSense, int Size)
{
	if (BallPosition.y >= GAME_ENGINE->GetHeight()-Size && BallSense.y > 0)
	{
		GAME_ENGINE->MessageBox("lost a life");
		BallPosition.x = PaddlePosition.x + PaddleSize.x/2;
		BallPosition.y = PaddlePosition.y - Size*4;
	}
	return BallPosition;
}



