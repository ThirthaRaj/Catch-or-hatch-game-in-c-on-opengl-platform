//code for the highscore
#include<stdio.h>
#include<stdlib.h>
#include "main.h"
#include<string.h>

 typedef struct{
        char *tag;
        int score;
       }sheet;

int high_score(int m)
{
   int i,x;
      FILE *o_file = fopen("text.txt","r");
      FILE *n_file = fopen("n_text.txt","w");

      int count;
      fscanf(o_file,"%i",&count);
    
     sheet *p = malloc(sizeof(sheet)*count);
     int p_count=0;
    
     for(i=0;i<count;i++)
      {
       int namelen;

       fscanf(o_file,"%i",&namelen);
       char *name=malloc(sizeof(char)*(namelen+1));
       name[namelen]='\0';
       int n;
       fscanf(o_file,"%s %i",name,&n);
        
       if(n<=m)
       {  
          p[p_count].tag=name;
          p[p_count].score=m;
          p_count++;
          x=m;
       }
      else 
        {
           p[p_count].tag=name;
           p[p_count].score=n;
           p_count++;
           x=n;
    
        }
      
       }
        
      fprintf(n_file, "%i\n",count);
      
      for(i=0;i<p_count;i++)
        fprintf(n_file,"%s %i\n",p[i].tag,p[i].score);

      fclose(o_file);
      fclose(n_file);
  
      remove("text.txt");
      rename("n_text.txt","text.txt");
     return x;

}
