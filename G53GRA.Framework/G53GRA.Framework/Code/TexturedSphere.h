#pragma once

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#include <string>
// Rate of rotation around y (18 degrees per second)
#define _ROTV 18.0f
// Pointer index for vertex 0
#define _VERTEX0 0
// Pointer index for vertex 1
#define _VERTEX1 3
// Pointer index for vertex 2
#define _VERTEX2 6
// Pointer index for vertex 3
#define _VERTEX3 9
// Pointer index for vertex 4
#define _VERTEX4 12
// Pointer index for vertex 5
#define _VERTEX5 15
// Cap subdivisons at 7
#define _MAX_RES 7

#define M_PI 3.14159265

class TexturedSphere :
	public DisplayableObject,
	public Animation,
	public Input
{
public:
	TexturedSphere(GLint texId1, GLint texId2);
	~TexturedSphere(){}
	
	void Display();
	void Update(const double& deltaTime);
	void HandleKey(unsigned char key, int state, int mx, int my);

	// Manually set resolution
	inline void SetResolution(int r) { _resolution = r >= 0 ? (r > _MAX_RES ? _MAX_RES : r) : 0; }
	// Toggle wire frame model
	inline void ToggleWireFrame() { _flagWireFrame = !_flagWireFrame; }
	// Toggle rotation animation
	inline void ToggleAnimation() { _flagAnimation = !_flagAnimation; }

protected:
	void DrawSphere();
	void SubDivide(int p_recurse, float *a, float *b, float *c);
	void DrawFace(float *a, float *b, float *c);
	void FixSeam(float &a, float &b, float &c);

	// ID to bound texture
	int texId1;
	int texId2;
	// recursive resolution (increase for finer mesh)
	int _resolution;
	// Flag for wireframe model
	GLboolean _flagWireFrame;
	// Flag for animation
	GLboolean _flagAnimation;
	// Initial vertices
	float* _initV;
};

