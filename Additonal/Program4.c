#include <stdio.h>
#include <stdlib.h>

int compareFile(FILE *fPtr1, FILE *fPtr2, int *line, int *col)
{
    char ch1, ch2;

    *line = 1;
    *col = 0;
    do
    {
        ch1 = fgetc(fPtr1);
        ch2 = fgetc(fPtr2);

        if (ch1 == '\n')
        {
            *line += 1;
            *col = 0;
        }

        if (ch1 != ch2)
            return -1;

        *col += 1;

    } while (ch1 != EOF && ch2 != EOF);

    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}
void merge()
{
    FILE *fp1 = fopen("file.txt", "r");
    FILE *fp2 = fopen("fileTwo.txt", "r");

    FILE *fp3 = fopen("file3.txt", "w");
    char c;

    while ((c = fgetc(fp1)) != EOF)
        fputc(c, fp3);

    
    while ((c = fgetc(fp2)) != EOF)
        fputc(c, fp3);
    printf("\n");
    printf("Merged file1 and file2 into new file");

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
int main()
{
    FILE *fPtr1;
    FILE *fPtr2;
   
    char path1[100];
    char path2[100];
   
    int diff;
    int line, col;
    printf("Enter path of first file: ");
    scanf("%s", path1);
    printf("Enter path of second file: ");
    scanf("%s", path2);
    fPtr1 = fopen(path1, "r");
    fPtr2 = fopen(path2, "r");
    if (fPtr1 == NULL || fPtr2 == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
    diff = compareFile(fPtr1, fPtr2, &line, &col);
    if (diff == 0)
        printf("\nBoth files are equal.");
    else
    {
        printf("\nFiles are not equal.\n");
        merge();
    }
    fclose(fPtr1);
    fclose(fPtr2);
    return 0;
}
