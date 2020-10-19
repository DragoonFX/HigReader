#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "HigReader.h"

void main()
  {

    GetFileName();

    if (IsEnglish)
    {
      strcpy(identifier, "Line_WaitForInput");
    }
    else
    {
      strcpy(identifier, "OutputLine(");
    }

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
  printf("Choose language, 0 for Japanese, 1 for English\n");
  int temp;
  scanf("%d",&temp);
  if (temp != 0 && temp != 1)
  {
    exit(1);
  }
  IsEnglish=temp;

  printf("Input file name\n");
  scanf("%s",FileName);
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
    CharacterValidation(currentLine);
    LineValidation(currentLine);
  }
  free(currentLine);
  return true;
}

void LineValidation(char *currentLine)
{
  if(strstr(currentLine,identifier)
  || (IsEnglish && strstr(currentLine,"Line_Normal")))
  {
    char subLine[500];
    int len = strlen(currentLine);
    int i;
    if (IsEnglish)
    {i=11;}
    else
    {i=16;}
    for (i;i<len;i++)
    {
      //Check if line has ended, in some cases line is empty
      if (currentLine[i] == 'L' && currentLine[i+1] == 'i' && currentLine[i+2] == 'n' &&currentLine[i+3] == 'e')
      {break;}
      //Filter out special characters
      if(currentLine[i] != '\"' && currentLine[i] != '\n' && currentLine[i] != '\\' && currentLine[i] != ',')
      {
        strncat(subLine, &currentLine[i], 1);
      }
    }
    printf("%s\n",subLine);
    strcpy(subLine, "");
  }
}

void CharacterValidation(char *currentLine)
{
  char name[100];
  bool hasName=false;
  if(strstr(currentLine,"DrawBustshot"))
  {
    strcat(name,"Characters in scene ");
    if(strstr(currentLine,"\"me_"))
    {
      strcat(name, "Mion ");
      hasName=true;
    }
    if(strstr(currentLine,"\"oi_")||strstr(currentLine,"\"oisi"))
    {
      strcat(name, "Ooishi ");
      hasName=true;
    }
    if(strstr(currentLine,"\"oni_"))
    {
      strcat(name, "Dark Rena ");
      hasName=true;
    }
    if(strstr(currentLine,"\"re_"))
    {
      strcat(name, "Rena ");
      hasName=true;
    }
    if(strstr(currentLine,"\"ri_"))
    {
      strcat(name, "Rika ");
      hasName=true;
    }
    if(strstr(currentLine,"\"sa_"))
    {
      strcat(name, "Satoko ");
      hasName=true;
    }
    if(strstr(currentLine,"\"ta_"))
    {
      strcat(name, "Takano ");
      hasName=true;
    }
    if(strstr(currentLine,"\"tm_")||strstr(currentLine,"\"tomi"))
    {
      strcat(name, "Tomitake ");
      hasName=true;
    }
    if(strstr(currentLine,"\"si_"))
    {
      strcat(name, "Shion ");
      hasName=true;
    }
    if(strstr(currentLine,"\"wata_mion"))
    {
      strcat(name, "Dark Mion ");
      hasName=true;
    }
    if(strstr(currentLine,"\"wata_rena"))
    {
      strcat(name, "Depressed Rena ");
      hasName=true;
    }
    if(strstr(currentLine,"\"ir_"))
    {
      strcat(name, "Irie ");
      hasName=true;
    }
    if(strstr(currentLine,"\"ti_")||strstr(currentLine,"\"tie"))
    {
      strcat(name, "Chie ");
      hasName=true;
    }
    if(strstr(currentLine,"\"aka_"))
    {
      strcat(name, "Akane ");
      hasName=true;
    }
    if(strstr(currentLine,"\"kasa"))
    {
      strcat(name, "Kasai ");
      hasName=true;
    }
    if(strstr(currentLine,"\"ke"))
    {
      strcat(name, "Negative Ooishi ");
      hasName=true;
    }
    if(strstr(currentLine,"\"kei_"))
    {
      strcat(name, "Keiichi ");
      hasName=true;
    }
    if(strstr(currentLine,"\"sato"))
    {
      strcat(name, "Satoshi ");
      hasName=true;
    }
    if(strstr(currentLine,"\"tetu"))
    {
      strcat(name, "Teppei ");
      hasName=true;
    }
    if(strstr(currentLine,"\"aks_"))
    {
      strcat(name, "Akasaka ");
      hasName=true;
    }
    if(strstr(currentLine,"\"ha_"))
    {
      strcat(name, "Hanyuu ");
      hasName=true;
    }
    if(strstr(currentLine,"\"rina_"))
    {
      strcat(name, "Rina ");
      hasName=true;
    }
    strcat(name,"\n");
  }
  if(hasName)
  {
    printf("%s", name);
  }
  strcpy(name, "");
}
