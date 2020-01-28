
#include <GL/glut.h>  
#include <stdio.h>


void initGL() {
  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
 


float radius=10;
float x1=0,y1=50 ,x2=0,y2=100;
int xc=0,yc=0;

void display() {
   glClear(GL_COLOR_BUFFER_BIT);  
     
 int dx=x2-x1;
 int dy=y2-y1;

    float x=x1;
    float y=y1;


   float p=2*dx-dy;

//    while(y<=y2)
//     {
          
//           glColor3f(1,0,0);
//          glPointSize(4);
//          glBegin(GL_POINTS);
//          glVertex2f(x,y);
//          glEnd();

//         y++;

//         if(p<0)
//            p+=2*dx;

//         else
//         {
//           p=p+2*dx-2*dy;
//           x++;
//         }      

//     }

// ///////////circle


      x=0,y=radius;

     float d= 3-2*radius;

   while(x<=y)
    {
          
          int tempx=x,tempy=y;
            x=x+xc;
            y=y+yc;
          glColor3f(1,0,0);
         glPointSize(4);
         glBegin(GL_POINTS);
         glVertex2f(x,y);
         glVertex2f(-x,-y);
         glVertex2f(-x,y);
         glVertex2f(x,-y);
         
         glVertex2f(y,x);
         glVertex2f(-y,-x);
         glVertex2f(-y,x);
         glVertex2f(y,-x);
 glEnd();



        glTranslatef(-10,0,0);   

       //  glColor3f(1,0,0);
         glPointSize(4);
        glBegin(GL_POINTS);
         glVertex2f(x,y);
         glVertex2f(-x,-y);
         glVertex2f(-x,y);
         glVertex2f(x,-y);
         
         glVertex2f(y,x);
         glVertex2f(-y,-x);
         glVertex2f(-y,x);
         glVertex2f(y,-x);



  glTranslatef(+10,0,0); 
         

         glEnd();

            x=tempx;
            y=tempy;
            
        if(d<=0)
        {
         d=d+(4*x)+6;
        }  
        else
        {
            d=d+4*(x-y)+10;
            y=y-1;
            
        }
        x=x+1;

    }

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
   initGL();                     
   glutMainLoop();               
   return 0;
}