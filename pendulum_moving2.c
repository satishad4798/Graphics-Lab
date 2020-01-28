
#include <GL/glut.h>  
#include <stdio.h>


void initGL() {
  
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void timer(int values)
{
   glutPostRedisplay();

   glutTimerFunc(60, timer, 0);
}

int angle = 5;
int flag = 1;
float radius=50;



void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW); // To operate on Model-View matrix
   glLoadIdentity();
   float x1 = 0, y1 = radius, x2 = 0, y2 = 100;

   glColor3f(0, 0, 0);
   glTranslatef(0,100, 0);
  
   glRotatef(angle, 0, 0, 1);
  
   if(angle<75 && flag==1)
      {
         angle += 5;
         
      }
      else
      {
         flag=0;
      }
      

  if(angle>=-75 && (flag==0))
    {
       angle=angle-5;

    }
    else
    {
       flag=1;
    }
    

      glTranslatef(0,-90,0);
   int dx = x2 - x1;
   int dy = y2 - y1;

   float x = x1;
   float y = y1;


   float p=2*dx-dy;

   while(y<=y2)
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

///////////circle


      x=0,y=radius;

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
    printf("enter radius");
  scanf("%f",&radius);

   glutInitWindowSize(640, 480);  
   glutInitWindowPosition(50, 50);
   glutCreateWindow("dda"); 
   glutDisplayFunc(display);    
   glutReshapeFunc(reshape);
   glutTimerFunc(0, timer, 0);
   initGL();                     
   glutMainLoop();               
   return 0;
}