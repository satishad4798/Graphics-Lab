
#include <GL/glut.h>  
#include <stdio.h>


void initGL() {
  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
 
 void timer(int values)
 {
    glutPostRedisplay();
   
    glutTimerFunc(30,timer,0);
    
 }

int angle=0;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW); // To operate on Model-View matrix
   glLoadIdentity();
  //  glTranslatef(0,-25,0);
  // glRotatef(45, 0, 0, 1);

  

   glBegin(GL_LINES);
   glColor3f(0, 1, 0);
   glVertex3f(0, 100, 0);
   glVertex3f(0, -100, 0);
   glVertex3f(100, 0, 0);
   glVertex3f(-100, 0, 0);
   glEnd();

   glTranslatef(-50,50,0);
   glRotatef(angle, 0, 0, 1);
 angle+=5;
      //   if(angle>360);
      //    angle=0;
   glBegin(GL_QUADS);
   glColor3f(1, 0, 0);
   glVertex3f(10, 10, 0);
   glVertex3f(-10, 10, 0);
   glVertex3f(-10, -10, 0);
   glVertex3f(10, -10, 0);

   glEnd();

   glFlush(); 
}
 



void reshape(GLsizei width, GLsizei height) {  
  
   if (height == 0) height = 1;               
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   
   glViewport(0, 0, width, height);
 
   
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();           
      gluOrtho2D(-100 * aspect, 100 * aspect, -100, 100);
   
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);     

 //scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
   
 // scanf("%f",&radius);

   glutInitWindowSize(640, 480);  
   glutInitWindowPosition(50, 50);
   glutCreateWindow("dda"); 
   glutDisplayFunc(display);    
   glutReshapeFunc(reshape);    
   glutTimerFunc(0,timer,0);   
   initGL();                     
   glutMainLoop();               
   return 0;
}