#include <stdio.h>

int main()
{
  FILE *fptr;
  char str[200];
  if (fptr = fopen("fromCopy.txt", "r"))
  {
    printf("Data of first file :-");
    printf("%s\n", fgets(str, 200, fptr));
    fclose(fptr);
    fptr = fopen("toCopy.txt", "w");
    fprintf(fptr, "%s", str);
    printf("File has been created \n");
    printf("Data is copied");
    fclose(fptr);
  }
  else
  {
    printf("File does not exist");
  }
  return 0;
}