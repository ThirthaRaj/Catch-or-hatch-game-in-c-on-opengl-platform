#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include "main.h"
#define SCORE_BOARD_HEIGHT 36
#define SCORE_BOARD_WIDTH 220
#define SCORE_BOARD_PADDING 150

GLdouble width, height;   /* window width and height */
int wd;                   /* GLUT window handle */
long long int curr_score=-108;//this is the score that is printed on screen
void draw_score(long long int score)
{
	long long int tempsc = score;	
     char str[15];
	sprintf(str,"%lld",tempsc);
	glutStrokeString(GLUT_STROKE_ROMAN,"SCORE : ");
	glutStrokeString(GLUT_STROKE_ROMAN,str);
}
void draw_score_board(long long int score)
{
    curr_score=score;
    glPushMatrix();
    glTranslatef(SCORE_BOARD_PADDING, height - SCORE_BOARD_HEIGHT - 20, 0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(SCORE_BOARD_WIDTH, 0);
        glVertex2f(SCORE_BOARD_WIDTH, SCORE_BOARD_HEIGHT);
        glVertex2f(0, SCORE_BOARD_HEIGHT);
    glEnd();
    glLineWidth(5);
    glColor3f(0,0,1);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0, 0);
        glVertex2f(SCORE_BOARD_WIDTH, 0);
        glVertex2f(SCORE_BOARD_WIDTH, SCORE_BOARD_HEIGHT);
        glVertex2f(0, SCORE_BOARD_HEIGHT);
        glVertex2f(0,0);
    glEnd();
    glLineWidth(1);
    glColor3f(1,0.98,0);
        glPushMatrix();
            glTranslatef(8,8,0);
            glScalef(0.2,0.2,1);
            draw_score(curr_score);
        glPopMatrix();
    glPopMatrix();
}




//code for showing the timer

void draw_time(int time)
{
	int tempt = time;
	tempt/=1000;
	int tmin=tempt/60;
	int tsec=tempt%60;	
     char str1[15],str2[15];
	sprintf(str1,"%d",tmin);
	sprintf(str2,"%d",tsec);
	glutStrokeString(GLUT_STROKE_ROMAN,"Time ");
	glutStrokeString(GLUT_STROKE_ROMAN,str1);
	glutStrokeString(GLUT_STROKE_ROMAN,":");
     if(tsec/10==0)
	{
		glutStrokeString(GLUT_STROKE_ROMAN,"0");	
		glutStrokeString(GLUT_STROKE_ROMAN,str2);
     }
	else
		glutStrokeString(GLUT_STROKE_ROMAN,str2);
	
}
void draw_time_board()
{
    glPushMatrix();
    glTranslatef(1000, 770 - 36 - 20, 0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(0, 0);
        glVertex2f(150, 0);
        glVertex2f(150, 36);
        glVertex2f(0, 36);
    glEnd();
    glLineWidth(5);
    glColor3f(0,0,1);
    glBegin(GL_LINE_STRIP);
        glVertex2f(0, 0);
        glVertex2f(150, 0);
        glVertex2f(150,36);
        glVertex2f(0, 36);
        glVertex2f(0,0);
    glEnd();
    glLineWidth(1);
    glColor3f(1,0.98,0);
        glPushMatrix();
            glTranslatef(8,8,0);
            glScalef(0.2,0.2,1);
            draw_time(count*50);
        glPopMatrix();
    glPopMatrix();
}
