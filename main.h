/*#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>*/
struct colors
{
 float r;
 float g;
 float b;
 int score;
};

#include<GL/glut.h>
extern int xc,yc,wd,count;
extern int eggs[10];
extern int pos_pos[3];
extern int egg_pos[10][2];
extern int egg_color[10];
extern bask_x;
extern score;
extern game_state;
extern struct colors s[16];
//extern struct colors s[3];


void draw_ellipse(GLfloat x, GLfloat y,float r ,float g ,float bl);
//void draw_ellipse(int xc,int yc,float r,float g,float bl);
void draw(int x,int y);       //function to draw the ducks
void timer_func(int v);       //function in which all the changes have been made repeatedly
void init(void);              //functio to initialize the data
void timer_egg_func(int v);   //function to check and change status of the eggs
void draw_basket(void);//function to draw the basket
void draw_score_board(long long int score);  //for score board
void last_display();           //for end page
void draw_time_board();        //for timer
void key_board(unsigned char key,int x,int y);
void mouse_passive(int x,int y); //function for the mouse passive motion
void keyboard_mov(int key,int x,int y);  //function keyboard movement of ship
int high_score(int m);

void draw_broken_ellipse(GLfloat x,GLfloat y,float r,float g ,float bl);
