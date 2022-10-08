#include<stdio.h>

int main()
{
    FILE *fptr;
    char str[100];
    if(fptr=fopen("file.txt","r"))
    {
        printf("File Content : \n");
        printf("%s",fgets(str,50,fptr));
    }
    else
    {
        printf("file Content does not exist");
    }
    fclose(fptr);
 return 0;   
}