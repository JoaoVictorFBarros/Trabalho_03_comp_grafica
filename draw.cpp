#include "draw.hpp"
#include "colors.hpp"

void drawcube(GLuint id, float s)
{
	float d = s / 2;

	vec3 v1(-d, d, d);
	vec3 v2(-d, -d, d);
	vec3 v3(d, -d, d);
	vec3 v4(d, d, d);
	vec3 v5(d, d, -d);
	vec3 v6(d, -d, -d);
	vec3 v7(-d, -d, -d);
	vec3 v8(-d, d, -d);

	glNewList(id, GL_COMPILE);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	paint(v1, v2, v3, v4,v5, v6, v7, v8); 
	glEndList();
}

void draw(Camera camera, unsigned int cuboID[3])
{
	glLoadIdentity();

	camera.ativar();	
	
	glPushMatrix();
	glTranslatef(-0.0, 0.0, -80.0);
	glRotatef(angulo, 1.0, 1.0, 0.0);
	glCallList(cuboID[0]);
	glPopMatrix();

	angulo += 1.0;
	if (angulo >= 360.0)
		angulo = 0.0;
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);

	float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
}
