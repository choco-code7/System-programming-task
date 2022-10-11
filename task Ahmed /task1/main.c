#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
  
  FILE *file1_read;
  FILE *file1_write;

  FILE *file2_write;




  file1_read = fopen("input.txt", "r");
  file1_write = fopen("input.txt", "r+");
  file2_write = fopen("output.txt", "w");



  if (file1_read == NULL || file1_write == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  int c;
  

  int count = 0;


  while (true)
  {
    c = fgetc(file1_read);

    if (feof(file1_read) || ferror(file1_read))
      break;

     if (c % 2 != 0)
    {
      fputc(c, file1_write);
      count++;
    }
    else{
      fputc(c, file2_write);
      count++;
    }

  }

  if (truncate("input.txt", count) == -1)
  {
    printf("Error truncating file.\n");
    return 1;
  }

  return 0;
}