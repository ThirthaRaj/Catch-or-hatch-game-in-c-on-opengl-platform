#include "main.h"
#include<stdio.h>
#include<GL/glut.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14159


/*struct colors
{
 float r;
 float g;
 float b;
 int score;
};*/

struct colors s[16];

void init(void)     //initialising all the data in this function
{
  
  //for(i=0;i<10;i++)
  //eggs[i]=0;
  //initialising the colors
  count=2400;
  s[0].r=255;
  s[0].g=255;
  s[0].b=255;
  s[0].score=1;
  
  s[1].r=255;
  s[1].g=0;
  s[1].b=0;
  s[1].score=5;
  
  s[2].r=0;
  s[2].g=255;
  s[2].b=0;
  s[2].score=10;
  
  s[3].r=255;
  s[3].g=255;
  s[3].b=0;
  s[3].score=50;
  
  s[4].r=0;
  s[4].g=255;
  s[4].b=255;
  s[4].score=-50;
  
  s[5]=s[10]=s[14]=s[13]=s[0];
  s[6]=s[11]=s[15]=s[1];
  s[12]=s[7]=s[2];
  s[8]=s[3];
  s[9]=s[4];
  
  pos_pos[0]=100;
  pos_pos[1]=650;
  pos_pos[2]=1200;
}


//code that calls all draw_ellipse fuction to draw ellipse
void dEllipse(void)
{
  int i;
  for(i=0;i<10;i++)
  {
    if(eggs[i]==1)
    draw_ellipse(egg_pos[i][0],egg_pos[i][1],s[egg_color[i]].r,s[egg_color[i]].g,s[egg_color[i]].b);
    else
      if(eggs[i]<0)
      {
        eggs[i]-=1;
        if(eggs[i]==-20)
        eggs[i]=0;
        draw_broken_ellipse(egg_pos[i][0],egg_pos[i][1],s[egg_color[i]].r,s[egg_color[i]].g,s[egg_color[i]].b);
      }
  }
  
}



//code to draw ducks
void draw(int x,int y)
{
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POLYGON);
  // code for the hexgon at the bottom
     glVertex2f(x-20,y+20);
     glVertex2f(x+20,y+20);
     glVertex2f(x+40,y);
     glVertex2f(x+20,y-20);
     glVertex2f(x-20,y-20);
     glVertex2f(x-40,y);
  glEnd();

  //code for the neck
  glColor3f(1.0,1.0,0.0);
  glBegin(GL_POLYGON);

     glVertex2f(x-20,y+40);
     glVertex2f(x+5,y+40);
     glVertex2f(x-20,y+20);
     glVertex2f(x-40,y);
     glVertex2f(x-50,y+10);
  glEnd();
  //code for the face in yellow color
  glBegin(GL_POLYGON);
     glVertex2f(x-20,y+40);
     glVertex2f(x+5,y+40);
     glVertex2f(x-5,y+60);
  glEnd();
  //code for the face in green color
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glVertex2f(x-5,y+60);
    glVertex2f(x-20,y+60);
    
    glVertex2f(x-40,y+40);

    glVertex2f(x-20,y+40);
  glEnd();
  //code for the eye
  glColor3f(0.0,0.0,0.0);
  glPointSize(6.0);
    glBegin(GL_POINTS);
  glVertex2f(x-12,y+50);
  glEnd();
  //code for the hat
  glPointSize(2.0);
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_LINES);
    glVertex3f(x-7,y+60,0);
    glVertex3f(x,y+70,0);
    glVertex3f(x-7,y+60,0);
    glVertex3f(x-14,y+70,0);
  glEnd();
}


//code to draw the ellipse

void draw_ellipse(GLfloat x, GLfloat y,float r ,float g ,float bl)
{
  int i;
  GLfloat radius=10;
  int triangleAmount = 20; //# of triangles used to draw circle
  glColor3f(r,g,bl);
  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * PI;
  glPushMatrix();
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y); // center of circle
  for(i = 0; i<= triangleAmount;i++) 
  {  
    glVertex2f(
         x + (radius * cos(i * twicePi / triangleAmount)),
         y + (2*radius * sin(i * twicePi / triangleAmount))
              );
  }
  glEnd();
  glPopMatrix();
  //glutSwapBuffers();
}

//code to draw the Basket
void draw_basket(void)
{
  int x,y;
  x=bask_x;
  y=50;
  glColor3f(0.0,1.0,0.0);
  glBegin(GL_POLYGON);
    glVertex2f(x-40,y+40);
    glVertex2f(x+38,y+40);
    glVertex2f(x+20,y-20);
    glVertex2f(x-20,y-20);
  glEnd();
  glPointSize(20.0);
  glBegin(GL_POINTS);
    glVertex2f(x+20,y-20);
    glVertex2f(x-20,y-20);
  glEnd();
}

//code for displaying the end page

void draw_string(char *str)
{
 	glutStrokeString(GLUT_STROKE_ROMAN,str);
    
}
void score_print(long long int score)
{
	long long int tempsc = score;	
     char str[15];
	sprintf(str,"%lld",tempsc);
	draw_string(str);  
}
void last_display()
{
    int i;
    glPushMatrix();
    glTranslatef(1280/2.0-250,600/2.0-250,0);
    glColor3f(0,0,0);
    //glScalef(1.0,0.2,0);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,500);
        glVertex2f(0,500);
    glEnd();
    glLineWidth(3);
    glColor3f(0.3,0.7,0.5);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0,0);
        glVertex2f(500,0);
        glVertex2f(500,500);
        glVertex2f(0,500);
    glEnd();


        glPushMatrix();
        glTranslatef(100,420,0);
        glScalef(0.4,0.4,0);
        glColor3f(207/255.0,46/255.0,240/255.0);
        draw_string("THANK YOU");
        glPopMatrix();


        glPushMatrix();
        glTranslatef(100,350,0);
        glScalef(0.25,0.25,0);
        glColor3f(105/255.0,64/255.0,239/255.0);
        draw_string("Your Score : ");
	   score_print(score);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(100,250,0);
        glScalef(0.25,0.25,0);
        glColor3f(240/255.0,212/255.0,30/255.0);
        draw_string("Highest Score : ");
	   score_print(high_score(score));
        glPopMatrix();
        
    glPopMatrix();
    if(count==0)
    exit(0);
}
