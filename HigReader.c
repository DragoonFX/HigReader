#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "HigReader.h"

void main(int argc, char *argv[])
{
	int f_name_length;
	
	if (argc == 2)
	{	
		//printf("Filename: %s\n", *(argv + 1));
		
		f_name_length = strlen(argv[1]);
		
		if(f_name_length <= 12)
		{
			printf("\n[%c%c]\n", argv[1][6], argv[1][7]);
		}
		else 
			printf("\n[%c%c%c%c%c]\n", argv[1][6], argv[1][7], argv[1][8], argv[1][9], argv[1][10]);
		
		strcpy(identifier, "Line_");
		
		if(!ReadFile(argc, argv))
		{
			printf("Invalid file\n");
			free(CurrentFile);
			return;
		}
		printf("\n");
		
		free(CurrentFile);
	}
	else
		printf("Error! Too many arguments!\n");
}

bool ReadFile(int g_argc, char **g_argv)
{
  //Can we retrieve file?
  if ((CurrentFile=fopen(g_argv[1],"r")) == NULL)
  {
    exit(1);
  }

  //Okay we could! Now to read it
  char *currentLine = NULL;
  size_t length = 0;
  ssize_t read;

  while ((read=getline(&currentLine, &length, CurrentFile)) != EOF)
  {
    CharacterValidation(currentLine);
    LineValidation(currentLine);
  }
  free(currentLine);
  
  return true;
}

char *extract(const char *const string, const char *const left, const char *const right)
{
    char  *head;
    char  *tail;
    size_t length;
    char  *result;

    if ((string == NULL) || (left == NULL) || (right == NULL))
        return NULL;
	
    length = strlen(left);
    head   = strstr(string, left);
    if (head == NULL)
        return NULL;
	
    head += length;
    tail  = strstr(head, right);
    if (tail == NULL)
        return tail;
	
    length = tail - head;
    result = malloc(1 + length);
    if (result == NULL)
        return NULL;
	
    result[length] = '\0';
    memcpy(result, head, length);
	
	//printf("%s\n", result);//prints unformatted string(for debugging)
	
    return result;
}

void LineValidation(char *currentLine)
{
  if(strstr(currentLine,identifier) || strstr(currentLine,"Line_Normal"))
  {
    int i, len;
		char subLine[500];
		char *open = "NULL, \"";//string starting with |NULL, "|
		char *end = "\",";//string ending with |",|
		
		currentLine = extract(currentLine, open, end);//finds out a string that starts with |NULL, "| and ends with |",|
		len = strlen(currentLine);
	
    for (i=0;i<len;i++)
    { 
      //Skip if the line has ended, in some cases line is empty
      if (currentLine[i] == 'L' && currentLine[i+1] == 'i' && currentLine[i+2] == 'n' && currentLine[i+3] == 'e')
      {
			break;
	  	}
	  	//Skips if the line is OutputLineAll
	  	if (currentLine[0] == '\\' && currentLine[1] == 'n')
      {
			break;
	  	}
      //Filter out special characters
	  	if (currentLine[i] != '\n' && currentLine[i] != '\\')
	  	{
			strncat(subLine, &currentLine[i], 1);
	  	}
    }
	
    printf("%s\n", subLine);
    strcpy(subLine, "");
  }
}

void CharacterValidation(char *currentLine)
{
  char name[100];
  bool hasName=false;
  
  if(strstr(currentLine,"DrawBustshot"))
  {
    if(strstr(currentLine,"\"me_"))
    {
      strcat(name, "Mion");
      hasName=true;
    }
    if(strstr(currentLine,"\"oi_")||strstr(currentLine,"\"oisi"))
    {
      strcat(name, "Ooishi");
      hasName=true;
    }
    if(strstr(currentLine,"\"oni_"))
    {
      strcat(name, "Dark Rena");
      hasName=true;
    }
    if(strstr(currentLine,"\"re_"))
    {
      strcat(name, "Rena");
      hasName=true;
    }
    if(strstr(currentLine,"\"ri_"))
    {
      strcat(name, "Rika");
      hasName=true;
    }
    if(strstr(currentLine,"\"sa_"))
    {
      strcat(name, "Satoko");
      hasName=true;
    }
    if(strstr(currentLine,"\"ta_"))
    {
      strcat(name, "Takano");
      hasName=true;
    }
    if(strstr(currentLine,"\"tm_")||strstr(currentLine,"\"tomi"))
    {
      strcat(name, "Tomitake");
      hasName=true;
    }
    if(strstr(currentLine,"\"si_"))
    {
      strcat(name, "Shion");
      hasName=true;
    }
    if(strstr(currentLine,"\"wata_mion"))
    {
      strcat(name, "Dark Mion");
      hasName=true;
    }
    if(strstr(currentLine,"\"wata_rena"))
    {
      strcat(name, "Depressed Rena");
      hasName=true;
    }
    if(strstr(currentLine,"\"ir_"))
    {
      strcat(name, "Irie");
      hasName=true;
    }
    if(strstr(currentLine,"\"ti_")||strstr(currentLine,"\"tie"))
    {
      strcat(name, "Chie");
      hasName=true;
    }
    if(strstr(currentLine,"\"aka_"))
    {
      strcat(name, "Akane");
      hasName=true;
    }
    if(strstr(currentLine,"\"kasa"))
    {
      strcat(name, "Kasai");
      hasName=true;
    }
    if(strstr(currentLine,"\"ke"))
    {
      strcat(name, "Negative Ooishi");
      hasName=true;
    }
    if(strstr(currentLine,"\"kei_"))
    {
      strcat(name, "Keiichi");
      hasName=true;
    }
    if(strstr(currentLine,"\"sato"))
    {
      strcat(name, "Satoshi");
      hasName=true;
    }
    if(strstr(currentLine,"\"tetu"))
    {
      strcat(name, "Teppei");
      hasName=true;
    }
    if(strstr(currentLine,"\"aks_"))
    {
      strcat(name, "Akasaka");
      hasName=true;
    }
    if(strstr(currentLine,"\"ha_"))
    {
      strcat(name, "Hanyuu");
      hasName=true;
    }
    if(strstr(currentLine,"\"rina_"))
    {
      strcat(name, "Rina");
      hasName=true;
    }
  }
  
  if(hasName)
  {
    printf("\n[%s]\n", name);
  }
  
  strcpy(name, "");
}
