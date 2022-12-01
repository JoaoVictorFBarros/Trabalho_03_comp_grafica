#include "depedencies.hpp"
#include "colors.hpp"

typedef float color[3];

color red = {1,0,0};
color green = {0,1,0};
color blue = {0,0,1};
color yellow = {1,1,0};
color turq = {0,1,1};
color mag = {1,0,1};
color black = {0,0,0};

void paint(vec3 p1, vec3 p2, vec3 p3, vec3 p4,vec3 p5, vec3 p6, vec3 p7, vec3 p8)
{
	glColor3fv(black);
	glBegin(GL_QUADS);
	glVertex3fv(&p1.x);

	glColor3fv(green);
	glVertex3fv(&p2.x);

	glColor3fv(yellow);
	glVertex3fv(&p3.x);

	glColor3fv(red);
	glVertex3fv(&p4.x);


	glColor3fv(mag);
	glVertex3fv(&p5.x);

	glColor3fv(black);
	glVertex3fv(&p6.x);

	glColor3fv(turq);
	glVertex3fv(&p7.x);

	glColor3fv(blue);
	glVertex3fv(&p8.x);


	glColor3fv(black);
	glVertex3fv(&p1.x);

	glColor3fv(green);
	glVertex3fv(&p2.x);

	glColor3fv(turq);
	glVertex3fv(&p7.x);

	glColor3fv(blue);
	glVertex3fv(&p8.x);

	
	glColor3fv(yellow);
	glVertex3fv(&p3.x);

	glColor3fv(red);
	glVertex3fv(&p4.x);

	glColor3fv(mag);
	glVertex3fv(&p5.x);

	glColor3fv(black);
	glVertex3fv(&p6.x);


	glColor3fv(black);
	glVertex3fv(&p1.x);

	glColor3fv(red);
	glVertex3fv(&p4.x);

	glColor3fv(mag);
	glVertex3fv(&p5.x);

	glColor3fv(blue);
	glVertex3fv(&p8.x);


	glColor3fv(green);
	glVertex3fv(&p2.x);

	glColor3fv(yellow);
	glVertex3fv(&p3.x);

	glColor3fv(black);
	glVertex3fv(&p6.x);

	glColor3fv(turq);
	glVertex3fv(&p7.x);

	glEnd();
}