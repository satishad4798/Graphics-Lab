#include <stdio.h>
#include <GL/glut.h>
 #include<math.h>

int xc=0, yc = 0,mx=0,my=0;
int choice;
float ro_x,ro_y;
int angle=0;

int line_x0,line_y0,line_x1,line_y1;
int r;
float  x2 , y2;

int no_of_sides;
int array[20][2];



void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void display(){
  glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(4);


   // circle 1
   if(choice==1)
            { int x =0,y=r;
            int d;
            d = 3-2*r;
            while(y>=x){
                x++;
                if(d>=0){
                y--;  
                d = d + 4 * (x - y) + 10; 
                } 
                else
                d = d + 4 * x + 6;

            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            glVertex2i(xc+x,yc+y);
            glVertex2i(xc-x,yc+y);
            glVertex2i(xc+x,yc-y);
            glVertex2i(xc-x,yc-y);
            glVertex2i(xc+y,yc+x);
            glVertex2i(xc-y,yc+x);
            glVertex2i(xc+y,yc-x);
            glVertex2i(xc-y,yc-x);
            glEnd();
            }

            //second circle
           
               

            // xc =r, yc =0;
            x =0,y=r;
            d = 3-r;
            while(y>=x){
                x++;
                if(d>=0){
                y--;  
                d = d + 4 * (x - y) + 10; 
                } 
                else
                d = d + 4 * x + 6;

            // glColor3f(0.1,0.5,0);
               
               int tempx=x;
               int tempy=y;
               float x= x*cos(angle)+y*sin(angle);
               float y=-x*sin(angle)+y*cos(angle);

            glBegin(GL_POINTS);
            glVertex2i(xc+x,yc+y);
            glVertex2i(xc-x,yc+y);
            glVertex2i(xc+x,yc-y);
            glVertex2i(xc-x,yc-y);
            glVertex2i(xc+y,yc+x);
            glVertex2i(xc-y,yc+x);
            glVertex2i(xc+y,yc-x);
            glVertex2i(xc-y,yc-x);
            glEnd();

             x=tempx;
             y=tempy;


            }



            }

if(choice==2)
    { 



    glBegin(GL_LINES);
    glVertex3f(line_x0,line_y0,0);
    glVertex3f(line_x1,line_y1,0);
    glEnd(); 
      
    
   
     // glrotatef(angle,0,0,1);
     glColor3f(1,0,0);
    float x,y;
    x=line_x0;
    y=line_y0;

   int x22= x*cos(angle)+y*sin(angle);
          int     y22=-x*sin(angle)+y*cos(angle);


    glBegin(GL_LINES);
    glVertex3f(x22,y22,0);

    x=line_x1;
    y=line_y1;

    x22= x*cos(angle)+y*sin(angle);
  y22=-x*sin(angle)+y*cos(angle);

    glVertex3f(x22,y22,0);
    glEnd(); 
    
}

if(choice==3)
{
      glBegin(GL_POLYGON);
   
      for(int i=0;i<no_of_sides;i++)
         {
             glVertex2f(array[i][0],array[i][1]);
         }


glEnd();
     
   





 glColor3f(1,0,0);
  
glBegin(GL_POLYGON);
   
      for(int i=0;i<no_of_sides;i++)
         {
               ro_x=array[i][0];
               ro_y=array[i][1];

      float    ro_x1= ro_x*cos(angle)+ro_y*sin(angle);
        float  ro_y1=-ro_x*sin(angle)+ro_y*cos(angle);

             glVertex2f(ro_x1,ro_y1);
         }


glEnd();
     








}


  glFlush();
}

void reshape(GLsizei width, GLsizei height) {  
   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (width >= height) {
      gluOrtho2D(-500.0 * aspect, 500.0 * aspect, -500.0, 500.0);
   } else {
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    

  printf(" 2.line 3.polygon");
 scanf("%d",&choice);

     if(choice==1)
        { 
            printf("enter radics of circle");
             scanf("%d",&r);
        }
   


     if(choice==2)
       {

      printf("enter line points x0 y0 x1 y1");
       scanf("%d %d %d %d",&line_x0,&line_y0,&line_x1,&line_y1);
      
       }

      if(choice==3)
      {

          printf("enter number of polygons");
          scanf("%d",&no_of_sides);

          for(int i=0;i<no_of_sides;i++)
          {
              scanf("%d %d",&array[i][0],&array[i][1]);
          }
      }


    printf("enter origin");
    scanf("%d %d",&xc,&yc);
 

    printf("enter rotation angle");
    scanf("%d",&angle);

    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("circle");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}