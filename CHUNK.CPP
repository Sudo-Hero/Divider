/*   This programms Divide a File into Small Chunks

     Date:16-07-20
     Written By:Sudo
			*/
#define OFF 0
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"C:\\turboc3\bin\fldr.h"
main()
  {
    FILE *fs,*ft;
    char fname[20],*str,containr[100],st[100],*ext,extension[]=".txt",fmore[100];
    int count=0,osos,more=2,len=0,counter=0,limitend=0;
    fldr();
    sos:
    clrscr();
    printf("\n\tEnter Name of File To divide into into chunks:\n\t[SUDO-HERO]:");
    scanf("%s",&fname);
    printf("\n\tMaximun Number of Words(or numbers) Each Line:\n");
    printf("\t(Maximum limit is 32766 and Default is 0)\n\t[SUDO-HERO]:");
    scanf("%d",&limitend);
    printf("\n\tProcessing Request for %s ...\n",fname);
    fs=fopen(fname,"r+");
     if(fs==0)
      {
	clrscr();
	printf("\n\t\t\nUnable To Open %s\n\nPress Any Key To Go Back...",fname);
	getch();
	goto sos;
      }

    ft=fopen("File%'er.txt","w+");

    while(fscanf(fs,"%s",&containr)!=EOF)//-------------------------Starting Point For Programme-------------------------------------------------------------
      {
	 //*******************Copies Form Provided File***********************************
	++count;
       ++counter;
	 if(count==1) //------Coppies First line of fname in to a Temporary BUFFER--------------------------
	   {
	     strcpy(st,containr);
	   }//----------------------End----------------------------------

	 if(count==limitend)//-------Coppies Last line of fname-------------------------Count=Satisfied----------------------------
/* if*/	   {
	     printf("\t[+]Total Done %d Saving File....\n",counter);
	     fprintf(ft,"%s\n",containr);
	     str=&containr[0];
	     len=strlen(st);
	     st[len]='-';
	     count=len;

/* while*/   while(1)//-------------------------Coppies Last Line Of Fname---------------
	      {
		if(*str!='\0')
		{
		  st[++count]=*str;
		  str++;
		  continue;
		}

		break;

/* while*/    }//--------------------------------Coppied Last Line Of fname----------------------

		ext=&extension[0];

		while(*ext!='\0')//------------Setting Entension For File---------------
		{
		  st[++count]=*ext;
		  ++ext;
		  continue;
		}//-----------------------------Extension Setting Done----------------------

		//------------Saving File By Renaming.Orignal File Will Not Be Lost

		fclose(ft);
		rename("File%'er.txt",st);
		remove("File%'er.txt");
		printf("\t[+]File Saved Sucess Fully..");
		ft=fopen("File%'er.txt","w+");
		printf("As %s\n",st);
		count=-1;

/* Count=2 */	      }//---------Count=2 Ending Reached-------------------------------



/* This is Where Checking For Other Files Starts
   This Determines To Keep Running or Stop */

	    if(count==-1)
	      {
		 if(fscanf(fs,"%s",&fmore)==EOF)//*------------------*Checks if there is more or not
		 {
		   more=0;
		 }
		 else
		   more=1;

		 if(more==0)
		 {
		   break;
		 }


		 if(more==1)
		 {
		   printf("\t[*]Getting Ready For Next File....\n");
		   count=1;
		   more=2;
		   strcpy(containr,fmore);
		   strcpy(st,containr);
		   ++counter;
		 }

	       // printf("\ncontainr:%s\n",containr);
	     }/* while(algorithm)*/
	    fprintf(ft,"%s\n",containr);
	  }
     fclose(fs);
     fclose(ft);
     len=strlen(containr);
     len--;
     ext=&extension[0];
     while(*ext!='\0')
     {
       containr[++len]=*ext;
       ext++;
     }
    if(counter%2==0)
     {
      remove(containr);
      goto osos;
     }

     printf("\t[+]Total Done %d Saving File....\n\t[*]Files Not Met Requirement Stored at \"Divider-\" Folder\n",counter);
     rename("File%'er.txt","Divider-/extra.txt");
     printf("\t[*]Dividing File Completed....");
     remove("File%'er.txt");
     osos:
     printf("\n\nFollow me for more Tools:https:https://github.com/Sudo-Hero");
     getch();
     return 0;
  }
