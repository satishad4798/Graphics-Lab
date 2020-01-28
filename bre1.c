
#include <GL/glut.h>  
#include <stdio.h>


void initGL() {
  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
 

float x1=0,x2=100,y1=0,y2=0;


void display() {
   glClear(GL_COLOR_BUFFER_BIT);  
     

      // glBegin(GL_LINES);
      //  glVertex2f(-10,0);
      //  glVertex2f(10,0);

      //  glVertex2f(0,10);
      //  glVertex2f(0,-10);

      // glEnd();

       
    int dx=x2-x1; //0
    int dy=y2-y1;//30


 


    float x=x1;
    float y=y1;

 float p=2*dx-dy;

   while(y1<=y2)
    {
          
          glColor3f(1,0,0);
         glPointSize(4);
         glBegin(GL_POINTS);
         glVertex2f(x,y);
         glEnd();

        y++;

        if(p<0)
           p+=2*dx;

        else
        {
          p=p+2*dx-2*dy;
          x++;
        }      

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