
#include <GL/glut.h>  
#include <stdio.h>

int refreshMills = 30;
int m=0,n=0;
int up=1,down=0;
void initGL() {
  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
 
void Timer(int value) {
   glutPostRedisplay();      
   glutTimerFunc(refreshMills, Timer, 0); 
}

float radius=10;


void display() {
     
      if(up)   
       {
           if(n<(100-radius))
           {
                n++;
                m++;
           }
           
            else
            {
                up=0;
                down=1;
            }
            
       }

        if(down)
        {
            if(n>(-100+radius))
              {
                   n--;
                   m--;
              }
             else
             {
                 down=0;
                 up=1;
             }
             


        }
        

      glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer
      glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
      glLoadIdentity();
        glTranslatef(m,n,0);   
     float x=0,y=radius;

     float d= 3-2*radius;

   while(x<=y)
    {
          
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
   
  scanf("%f",&radius);

   glutInitWindowSize(640, 480);  
   glutInitWindowPosition(50, 50);
   glutCreateWindow("dda"); 
   glutDisplayFunc(display);    
   glutReshapeFunc(reshape);   
    glutTimerFunc(0, Timer, 0);       
   initGL();                     
   glutMainLoop();               
   return 0;
}