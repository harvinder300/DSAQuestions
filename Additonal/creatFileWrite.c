#include<stdio.h>

int main()
{
    FILE *fptr;
    char str[100];
    printf("Enter content to write : ");
    gets(str);
    if(fptr=fopen("fileTwo.txt","w"))
    {
        fprintf(fptr,"%s\n",str);
        printf("File has been created ");
    }
    else
    {
        printf("file Content does not exist");
    }
    fclose(fptr);
 return 0;   
}