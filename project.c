/*program to implement hatch or catch*/

#include "main.h"
#include<stdio.h>
#include<GL/glut.h>

GLdouble width,height;
int wd;
int xc,yc;
int count;//to stop the after ten minutes
//variables for the eggs
int eggs[10]={0};
int egg_pos[10][2];
int egg_flag[10]={0};
int pos_pos[3];
int egg_color[10];

int bask_x=300;
int score=0;
int game_state=0;  
void display(void)
{
  
  int i;
  //int x;
  //x=glutGet(GLUT_WINDOW_WIDTH);
  //printf("%d\n",x);
  glClearColor(0.0,0.0,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0,0.0,0.0);
  glPointSize(2.0);
  draw(650,630);
  draw(100,630);
  draw(1200,630);
  //draw_ellipse(xc,yc,255,255,0);
  /*for(i=0;i<10;i++)
  {
    if(eggs[i]!=0)
    draw_ellipse(egg_pos[i][0],egg_pos[i][1],1,0,0);
  }*/
  if(game_state==0||game_state==1)
  {
  draw_score_board(score);
  draw_time_board();
  dEllipse();
  draw_basket();
  }
  else
      if(game_state==2)
        last_display();
  glutSwapBuffers();
  glFlush();
}


void reshape(int w,int h)
{
    width=(GLdouble) w;
    height=(GLdouble) h;
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,width,0.0,height);
}



void main(int argc, char *argv[])
{
    //width=1280.00;
    //height=800.00;
    width=136;
    height=786;
    xc=500;
    yc=500;
    init();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize((int) width,(int)height);
    wd = glutCreateWindow("Catch or Hatch" /* title */ );
    glutFullScreen();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(key_board);
    glutPassiveMotionFunc(mouse_passive);
    glutSpecialUpFunc(keyboard_mov);
    glutTimerFunc(10,timer_func,0);
    glutTimerFunc(10,timer_egg_func,0);
    glutMainLoop();
    return;
}
