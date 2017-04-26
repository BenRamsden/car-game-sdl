#include "RoadSquare.h"

RoadSquare::RoadSquare(GLint texId, float block_size)
{
	this->texId = texId;
	this->block_size = block_size;

	offset_size = block_size / 2;
}


RoadSquare::~RoadSquare()
{
}

void RoadSquare::Display()
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	// Enable Texturing
	glEnable(GL_TEXTURE_2D);

	// Enable setting the colour of the material the cube is made from
	// as well as the material for blending.
	//glEnable(GL_COLOR_MATERIAL);

	// Tell openGL which texture buffer to use
	glBindTexture(GL_TEXTURE_2D, texId);

	glPushMatrix();

	glBegin(GL_QUADS);

	glNormal3f(0, 1, 0);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3d(-offset_size, 0, -offset_size);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3d(-offset_size, 0, offset_size);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3d(offset_size, 0, offset_size);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3d(offset_size, 0, -offset_size);

	glEnd();

	glPopMatrix();

	// Stop blending textures and colours
	//glDisable(GL_COLOR_MATERIAL);

	// Bind to the blank buffer to stop ourselves accidentaly
	// using the wrong texture in the next draw call
	glBindTexture(GL_TEXTURE_2D, 0);
	// Stop performing texturing
	glDisable(GL_TEXTURE_2D);

	glPopAttrib();
}
