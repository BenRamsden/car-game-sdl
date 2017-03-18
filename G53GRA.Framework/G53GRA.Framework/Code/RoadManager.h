#pragma once
#include "DisplayableObject.h"
#include "Animation.h"
#include "RoadSquare.h"
#define MAXROADS 25

class RoadManager :
	public DisplayableObject,
	public Animation
{
public:
	RoadManager(const int roadCount);
	virtual ~RoadManager();

	virtual void Display();
	virtual void Update(const double& deltaTime);

private:
	int roadCount;
	int renderCount;
	RoadSquare* roadSquares[MAXROADS];

};
