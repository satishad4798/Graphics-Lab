

#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#include<GL/glut.h>
int flag=0;

int xc=0,yc=0;
int angle=0;
int hh=400,ww=400;
float sc=1;
void init()
{
 
glClearColor(0,0,0,0);
glColor3f(1,1,1);
glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);



}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

 //   
//   glColor3f(0,1,0);
//    glBegin(GL_LINES);
//    glVertex2f(100,0);
//    glVertex2f(-100,0);
//    glVertex2f(0,100);
//    glVertex2f(0,-100);
//    glEnd();


   // glViewport(, 0, w, h);
    glTranslatef(xc, yc, 0);

    glScalef(sc, sc, 0);

    int x = 10;

    {
     
         glPushMatrix();
   //      glTranslatef(xc, yc, 0);
         glBegin(GL_POLYGON);
         glColor3f(1, 0, 0);
         glVertex2f(x, x);
         glVertex2f(-x, x);
         glVertex2f(-x, -x);
         glVertex2f(x, -x);
         glEnd();
         glPopMatrix();
     }

        
     {
       
         x = x + 20;
         glColor3f(0, 0, 1);
         glPushMatrix();
      //   glRotatef(angle,0,0,1);
         glBegin(GL_POLYGON);
         glColor3f(1, 0, 0);
         glVertex2f(x, x);
         glVertex2f(-x, x);
         glVertex2f(-x, -x);
         glVertex2f(x, -x);
         glEnd();
         glPopMatrix();
     }



     glutSwapBuffers();




}
void reshape(int w,int h)
{
       ww=w;
       hh=h;
     glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glOrtho(-100.0 * aspect, 100.0 * aspect, -100.0, 100.0, -100.0, 100.0);
    //	 gluOrtho(-100 * aspect, 100 * aspect, -100, 100);
    // gluOrtho2D(-100 * aspect, 100 * aspect, -100, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void timer(int value)
{

glutTimerFunc(1000,timer,0);
  xc=xc+5;
  angle=angle+5;
     
     glutPostRedisplay();
 
}

void mykeyboardfunc(unsigned char key,int x,int y)
{
  if(key=='a')
    { 
        xc=xc+2;
     //   yc=yc+2;
      
        cout<<"("<<xc<<" "<<yc<<")\n";
     }
   if(key=='d')
       {
         //  xc = xc + 5;
           xc=xc-2;
       }
       if (key == 'w')
       {
         sc=sc+.2;
           
       }
       if(key=='s')
      {
          sc=sc-.2;
      }
           
       glutPostRedisplay();



}
void mymousefunc(int button, int state, int x, int y)
{
    
    if(GLUT_LEFT_BUTTON==button and state==GLUT_DOWN)
      {
          int s=ww/200;
          int t=hh/200;
          xc = x /s- 100;
          yc =-( y /t - 100);
         // flag = 1;
          cout << "(" << xc << " " << yc << ")\n";
      }
      glutPostRedisplay();

}
int main(int argc,char **argv)
{

//ALL are glut___
glutInit( &argc,argv);

glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
glutInitWindowSize(400,400);
glutInitWindowPosition(0,0);
glutCreateWindow("testing");

glutDisplayFunc(display);
glutReshapeFunc(reshape);

//glutTimerFunc(0,timer,0);
init();
glutKeyboardFunc(mykeyboardfunc);
glutMouseFunc(mymousefunc);




glutMainLoop();







}