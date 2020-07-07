#include<process.h>
#include<dir.h>
void fldr(void);

void fldr(void)
{
int check=0;
char *dirr="Divider-";
clrscr();
printf("Written By:SUDO-HERO\nDate:7/5/2020\n\n\n\n\n\n\n\n");
check=mkdir(dirr);
if(check==-1)
{
printf("\t\t\t\tFolder is not Created");
getch();
}
else
{
printf("\n[+]Folder id Created\n");
getch();
}
}












