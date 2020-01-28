
#include <GL/glut.h>  
#include <stdio.h>


void initGL() {
  
   glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
 

float x1=0,x2=0,y1=0,y2=8;
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

int count=0;
 for(int j=0;j<=8;j++)
 {
    
     x=x1+j;
    // y=y1+j;
     y=y1;
     count++;
    for(int i=0;i<=steps;i++)
    {
          
          if((i+count)%2==0)
          glColor3f(1,1,1);
          else
             glColor3f(0,0,0);

         glPointSize(25);
         glBegin(GL_POINTS);
         glVertex2f(x,y);
         glEnd();

         x=x+x_increment;
         y=y+y_increment;     

    }

   
  }

//////////////////////











 glFlush(); 
}
 

void reshape(GLsizei width, GLsizei height) {  
  
   if (height == 0) height = 1;               
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   
   glViewport(0, 0, width, height);
 
   
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();           
      gluOrtho2D(-10 * aspect, 10 * aspect, -10, 10);
   
}
 

int main(int argc, char** argv) {
   glutInit(&argc, argv);     

 //scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
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