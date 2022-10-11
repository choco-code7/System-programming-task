#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
  FILE* file1_read;
  FILE* file2_write;

  file1_read = fopen("input.txt", "r");
  file2_write = fopen("putput.txt", "w");
  char symbole = fgetc(file1_read);

  int height = 4;
  
  for (int i = 1; i <= height; i++)
  {

    int starCount = (i * 2) - 1;
    int spaceCount = height - i + 1;
    
    // print out the spaces
    for (int j = 0; j < spaceCount; j++)
    fputc(' ', file2_write);
    
    // print out the stars
    for (int j = 0; j < starCount; j++)
    fputc(symbole, file2_write);
    
    // print new line
    fputc('\n', file2_write);
}
fclose(file2_write);
return 0;
}