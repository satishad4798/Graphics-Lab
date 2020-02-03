#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int flag = 0;
float dist1 = -1.0, dist2 = 1.0, angle = 0, sc = 1;
GLfloat ballRadius = 0.5f;
int count=0;
void reshape(int w, int h)
 {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	GLfloat aspect = (GLfloat)w / (GLfloat)h;
	glOrtho(-100.0*aspect, 100.0*aspect, -100.0, 100.0, -100.0, 100.0);
	//	 gluOrtho(-100 * aspect, 100 * aspect, -100, 100);
	// gluOrtho2D(-100 * aspect, 100 * aspect, -100, 100);

	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
}

void init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void circle(int r)
{
	glPushMatrix();
	glBegin(GL_POINTS);
	for (int i = 0; i < 1000; ++i)
	{
		glVertex3f((cos(2 * 3.14159 * i / 1000.0) * r), (sin(2 * 3.14159 * i / 1000.0) * r), 0);
	}
	glEnd();
	glPopMatrix();
}
void Csmiley()
 {


      int r=50;
	  int temp=r;

	  glColor3f(1,0,0);
	   
	   circle(r);	
       
	   //smile
	   r=r/2;

	   glPushMatrix();
	   glBegin(GL_POINTS);
	   for (int i =2300; i <3200; ++i)
	   {
		   glVertex3f((cos(2 * 3.14159 * i / 3600.0) * r), (sin(2 * 3.14159 * i / 3600.0) * r), 0);
	   }
	   glEnd();
	   glPopMatrix();
        
		r=temp;
	  glTranslatef(r/2,r/2,0);
	
	    circle(r/7);

	

		glTranslatef(0,-(r/7-(r/15)),0);
	
		circle(r/15);

		glTranslatef(-r / 2, -r / 2, 0);
		glTranslatef(0, (r / 7 - (r / 15)), 0);
		glTranslatef(-r / 2, r / 2, 0);
		circle(r / 7);
			glRotatef(angle, 0, 0, 1);
		glTranslatef(0,- (r / 7 - (r / 15)), 0);
		circle(r/15);	
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
             

	
	glTranslatef(dist1, 0, 0);
	
	glTranslatef(dist2, 0, 0);

	glScalef(sc, sc, 0);

	glPushMatrix();


	glColor3f(0, 1, 0);

	{
		glPushMatrix();
		Csmiley();

		glPopMatrix();
	}

	glPopMatrix();

	glFlush();
}

void timer(int value)
{
	

	if(count<500 && value!=0)
	{
		glutTimerFunc(20,timer,value--);
	angle++;
	count++;
	}

	glutPostRedisplay();

}


void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	
	case 'd':
	
		dist2 = dist2 + 2;
		break;
	case 'a':
		
		dist2 = dist2 - 2;
		break;
	case 'w':
		sc = sc-.2;
	//	glScalef(sc, sc,0);
		break;
	case 's':
		sc = sc+.2 ;
	//	glScalef(sc, sc,0);
		break;

	case 'r':
	 count=0;
	     timer(1);
		 break;	
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Prac2");
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,timer,0);
	init();
	glutMainLoop();
	return 0;
}