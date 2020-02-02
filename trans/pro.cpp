#include <GL/glut.h>

#include <math.h>

#include <iostream>
using namespace std;

struct Point {
	GLint x;
	GLint y;
};
int r=30;
float s_x=1.0,s_y=1.0,s_z=1.0;
Point p1, p2;
	int tempx=0,tempy=0;

bool mid=false;
void draw_dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;

	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;

	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(float i = 1; i <= step; i++) {
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
	glEnd();
	glFlush();
}


// Plot eight points using circle's symmetrical property
void plot_point(int x, int y,int xc,int yc)
 {
// if(mid)
//  { 
//  	glScalef(2.0,2.0,0.5);
//  	mid=false;
//  }
  glBegin(GL_POINTS);

  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r,int xc,int yc)
{
  int x=0,y=r;
  float pk=3.0-r;
glClear(GL_COLOR_BUFFER_BIT);
 
  /* Plot the points */
  /* Plot the first point */
  plot_point(x,y,xc,yc);
  int k;
 
  /* Find all vertices till x=y */
  glBegin(GL_POLYGON);

  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 4*x+6;
    else
    {
      y = y - 1;
      pk = pk + 4*(x - y) + 10;
    }
    plot_point(x,y,xc,yc);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(x,y);
  }
  glEnd();
  glutSwapBuffers();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		p1.x = x;
		p1.y = 480 - y;
		tempx=x;
		tempy=y;
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		p2.x = x;
		p2.y = 480 - y;
		draw_dda(p1, p2);
		tempx=x;
		tempy=y;

	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
	{   
	    tempx=x;
		tempy=480-y;
		r=10;
		 bresenham_circle(r,tempx,tempy);
	

	}
	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
	{
		s_x+=1.0;
		s_y+=1.0;
		s_z+=1.0;
	   mid=true;
	   if(tempx&&tempy)
	   {
	   	r=2*r;
	    bresenham_circle(r,tempx,tempy);
	     }
    	else
		 { r=r/2;
		 	bresenham_circle(r,x,y);
		 }

	}

}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display(void) {}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Mouse Func");
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	init();
	glutMainLoop();

	return 0;
}