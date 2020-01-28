
#include <GL/glut.h>  
#include <stdio.h>


void initGL() {
  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
 

float x1=4,x2=25,y1=2,y2=50;
int steps;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);  
     

      // glBegin(GL_LINES);
      //  glVertex2f(-10,0);
      //  glVertex2f(10,0);

      //  glVertex2f(0,10);
      //  glVertex2f(0,-10);

      // glEnd();

       
    int dx=x2-x1;
    int dy=y2-y1;


 if( abs(dx)>abs(dy))
 {
    steps=abs(dx);
 }
 else
   steps=abs(dy);

   float x_increment=dx/(float)steps;
   float y_increment=dy/(float)steps;

    
    float x=x1;
    float y=y1;


    for(int i=0;i<steps;i++)
    {
          
          glColor3f(1,0,0);
         glPointSize(4);
         glBegin(GL_POINTS);
         glVertex2f(x,y);
         glEnd();

         x=x+x_increment;
         y=y+y_increment;     

    }

 glFlush(); 
}
 

void reshape(GLsizei width, GLsizei height) {  
  
   if (height == 0) height = 1;               
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   
   glViewport(0, 0, width, height);
 
   
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();           
      gluOrtho2D(-50 * aspect, 50 * aspect, -50, 50);
   
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);     
 printf("enter x1,y1,x2,y2\n");
 scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
 //cin>>x1>>y1>>x2>>y2;

   glutInitWindowSize(640, 480);  
   glutInitWindowPosition(50, 50);
   glutCreateWindow("dda"); 
   glutDisplayFunc(display);    
   glutReshapeFunc(reshape);       
   initGL();                     
   glutMainLoop();               
   return 0;
}