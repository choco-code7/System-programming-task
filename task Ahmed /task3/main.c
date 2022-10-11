
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINES 10
#define MAX_LEN 5


int *concat(int *a1, size_t len1, int *a2, size_t len2);
void sort(int a[], int length);

int main(void)
{
  int array1[MAX_LINES][MAX_LEN];
  FILE *file1;
  file1 = fopen("file1.txt", "r");

  int array2[MAX_LINES][MAX_LEN];
  FILE *file2;
  file2 = fopen("file2.txt", "r");

  FILE *file3;
  file3 = fopen("file3.txt", "w");

// get data from file1 into array1
  if (file1 == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  int f1_line = 0;

  while (!feof(file1) && !ferror(file1))
    if (fgets(array1[f1_line], MAX_LEN, file1) != NULL)
      f1_line++;
  

// get data from file2 into array2
    if (file2 == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }
  int f2_line = 0;

  while (!feof(file2) && !ferror(file2))
    if (fgets(array2[f2_line], MAX_LEN, file2) != NULL)
      f2_line++;



  ///////////////////////////////////
    // concat the two arrays
  int *array3 = concat(array1, 10, array2, 10);
  for (int i = 0; i < 10; i++)


  // sort the concated array
  sort(array3, 10);
  for (int i = 0; i < 10; i++){
    fputc(array3[i],file3);

  }

  free(array3);
  
  fclose(file1);
  fclose(file2);
  return 0;
}

int *concat(int *a1, size_t len1, int *a2, size_t len2)
{
     int i, j;
     int *new_array = malloc(sizeof(int) * (len1 + len2));

     for (i = 0; i < len1; i++)
     {
          new_array[i] = a1[i];
    }
       for (i = 0, j = len1;
         j < len1+len2 && i < len2; i++, j++) {
        new_array[j] = a2[i];
    }
  

  return new_array;
}
void sort(int a[], int length)
{
  bool swapped = false;
  int i = 0;
  do 
  {
    swapped = false;
    for (int j = 0; j < (length - 1 - i); j++)
    {
      if (a[j] > a[j + 1])
      {

        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        swapped = true;
      } 
    }
    i++;
  } while (swapped);
}