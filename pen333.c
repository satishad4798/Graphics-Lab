#include <stdio.h>
#include <GL/glut.h>
int xc=0, yc = 0;
int r;
float x0 , y0 , x2 , y2;
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void display(){
  glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(4);


   // circle 1
  int x =0,y=r;
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

  
  x0=0;x2=0;y0=r;y2=4*r;
  int dx ,dy;float X, Y, p;
    dx = x2 - x0;
    dy = y2 - y0;
    X = x0;
    Y = y0;
    p = 2*dx -dy;
    while(Y<=y2)
    {
      glBegin(GL_POINTS);
   //     glColor3f(0,1,0);
        glPointSize(4);
        glVertex2i(X,Y);
        glEnd();
      if(p>=0)
      {
        X=X+1;
        p=p+2*dx-2*dy;
      }
      else
      {
        p=p+2*dx;
      }
    Y=Y+1;
  }


//second circle
   glTranslatef(0,2*r,0);
  xc =3*r, yc =0;
  x =0,y=r/2;
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
  x0=3*r;x2=3*r;y0=r/2;y2=2*r;
    dx = x2 - x0;
    dy = y2 - y0;
    X = x0;
    Y = y0;
    p = 2*dx -dy;
    while(Y<=y2)
    {
      glBegin(GL_POINTS);
      //  glColor3f(0,1,0);
        glPointSize(4);
        glVertex2i(X,Y);
        glEnd();
      if(p>=0)
      {
        X=X+1;
        p=p+2*dx-2*dy;
      }
      else
      {
        p=p+2*dx;
      }
    Y=Y+1;
  }

//third circle
  xc=-3*r,yc=0;
   x =0,y=r/2;
   d;
  d = 3-r;
  while(y>=x){
    x++;
    if(d>=0){
      y--;  
      d = d + 4 * (x - y) + 10; 
    } 
    else
      d = d + 4 * x + 6;

  //glColor3f(0.1,0.5,0);
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
  x0=-3*r;x2=-3*r;y0=r/2;y2=2*r;
    dx = x2 - x0;
    dy = y2 - y0;
    X = x0;
    Y = y0;
    p = 2*dx -dy;
    while(Y<=y2)
    {
      glBegin(GL_POINTS);
    //    glColor3f(0,1,0);
        glPointSize(4);
        glVertex2i(X,Y);
        glEnd();
      if(p>=0)
      {
        X=X+1;
        p=p+2*dx-2*dy;
      }
      else
      {
        p=p+2*dx;
      }
    Y=Y+1;
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
   
    scanf("%d",&r);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("circle");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    initGL();
    glutMainLoop();
    return 0;
}