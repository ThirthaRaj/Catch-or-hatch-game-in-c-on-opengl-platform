#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.14
#include "main.h"
//code to draw the broken ellipse
//void draw_broken_ellipse(void)
void draw_broken_ellipse(GLfloat x,GLfloat y,float r,float g,float bl)
{
  /*GLfloat x=200;
  GLfloat y=300;
  float r=1.0;
  float g=0.0;
  float bl=0.0;*/

//	glPointSize(10.0);
	///glColor3f( 0 ,0, 1);
	
//	glBegin(GL_POINTS);
  
	//	glVertex2f(100.0,105.0) ;
//	glEnd();


	


  int i;
  GLfloat radius=10;
  int triangleAmount = 20; //# of triangles used to draw circle

  glColor3f(r,g,bl);
  //GLfloat radius = 0.8f; //radius
  GLfloat twicePi = 2.0f * PI;
  glPushMatrix();
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x+10, y+40); // center of circle
  for(i = 0; i<= triangleAmount;i++) 
  {  
	
	if(i>6 && i<15)
	{
		//if(y + (2*radius * sin(i * twicePi / triangleAmount))<100.0)
		{
    	glVertex2f(
        	 x + (radius * cos(i * twicePi / triangleAmount)),
        	 y + (2*radius * sin(i * twicePi / triangleAmount))
        	      );}
		
  	}
  }
	
	  for(i = 0; i<= triangleAmount;i++) 
  {  
	
	if(i>6 && i<15)
	{
		//if(y + (2*radius * sin(i * twicePi / triangleAmount))<100.0)
		{
    	glVertex2f(
        	 x - (radius * cos(i * twicePi / triangleAmount)),
        	 y + (2*radius * sin(i * twicePi / triangleAmount))
        	      );}
		
  	}
  }
	for(i = 0; i<= triangleAmount;i++) 
  {  
	
	if(i>10)
	{
		//if(y + (2*radius * sin(i * twicePi / triangleAmount))<100.0)
		{
    	glVertex2f(
        	 x + (radius * cos(i * twicePi / triangleAmount)),
        	 y + (2*radius * sin(i * twicePi / triangleAmount))
        	      );}
		
  	}
  }
  glEnd();
  glPopMatrix();
  
}
