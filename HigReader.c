#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "HigReader.h"

void main()
  {

    GetFileName();

    if(!ReadFile())
    {
      printf("Invalid file\n");
      free(CurrentFile);
      return;
    }
    printf("Success\n");


    free(CurrentFile);
  }

void GetFileName()
{
  printf("Input file name with path\n");
  gets(FileName);
}

bool ReadFile()
{
  //Can we retrieve file?
  if ((CurrentFile=fopen(FileName,"r")) == NULL)
  {
    exit(1);
  }

  //Okay we could! Now to read it
  char *currentLine = NULL;
  size_t length = 0;
  ssize_t read;
  while ((read=getline(&currentLine, &length, CurrentFile)) != -1)
  {
    printf("%s", currentLine);
  }
  free(currentLine);
  return true;
}

void LineValidation(char *currentLine)
{
  
}
