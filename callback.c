#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "main.h"

void check_collision(void)
{
  int i;
  
  for(i=0;i<10;i++)
  {
    if(egg_pos[i][0]<=(bask_x+25)&&egg_pos[i][0]>=(bask_x-30)&&egg_pos[i][1]<95&&egg_pos[i][1]>80&&eggs[i]==1)
    {
      eggs[i]=0;
      score+=s[egg_color[i]].score;
      printf("%d \n",score);
      draw_score_board(score);
      //score+=eggs
    }
    else
     {
       if(egg_pos[i][1]<50&&egg_pos[i][1]>0&&eggs[i]==1)
       {
        eggs[i]=-1;
       }
     }
  }
  /*for(i=0;i<10;i++)
  {
    if(eggs[i]==1&&egg_pos[i][1]<80)
    crack(i);
  }*/
}


//timer funcion which will be called repeatedly
void timer_func(int v)
{
  if(game_state==2)
  {
    if (count==0)
    exit(0);
    else
     count--;
  }
  if(game_state==0)
  {
    count--;
    if(count==0)
    {
     game_state=2;
     count=100;
     
    }
    
    else
    {
     int i;
     //yc-=3;
     for(i=0;i<10;i++)
     {
       if(eggs[i]==1)
       {
         egg_pos[i][1]-=10;
         //printf("\nyvu");
       }
     }
     draw_basket();
     check_collision();
    }
   }
   else
     if(game_state==1)
     {
        draw_basket();
        check_collision();
     
     }
   glutPostRedisplay();
  
   glutTimerFunc(50, timer_func, v);
}



//timer function for the eggs
void timer_egg_func(int v)
{
 int i,p;
 if(game_state==0)
 {
   for(i=0;i<10;i++)
   {
    if(eggs[i]==0)
    {
     p=rand()%3;
     eggs[i]=1;
     egg_pos[i][0]=pos_pos[p];
     egg_pos[i][1]=630;
     p=rand()%16;
     egg_color[i]=p;
     //printf("\n %d %d",egg_pos[i][0],egg_pos[i][1]);
     break;
    }
   }
 }
 for(i=0;i<10;i++)
 {
   if((eggs[i]==1)&&(egg_pos[i][1]<=0))
   {
       eggs[i]=0;
   }
 }
       
 glutTimerFunc(1000, timer_egg_func, v);
 
}

//code for mouse function
void mouse_passive(int x,int y)
{
  bask_x=x;
}
//code for keyboard
void keyboard_mov(int key,int x,int y)
{
  switch(key)
  {
    case GLUT_KEY_LEFT: if(bask_x>=30)
                        bask_x-=20;
                        break;
    case GLUT_KEY_RIGHT:if(bask_x<=(glutGet(GLUT_WINDOW_WIDTH)-30))
                        bask_x+=20;
                        break;
   }
}

void key_board(unsigned char key,int x,int y)
{
  switch(key)
  {
    case 'q':
    case 'Q':game_state=2;
             count=100;
             glutPostRedisplay();
             break;
    case 'p':
    case 'P':game_state=(game_state+1)%2;
             break;
  }
}

