#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "higureader.h"

int main(int argc, char *argv[])
{
	if(argc == 2)
	{	
		print_title(argv[1]);

		strcpy(identifier_1, "Line_");
		strcpy(identifier_2, "GetGlobalFlag(GLinemodeSp)");
		
		//seventh_mod = false;
		
		if(!ReadFile(argv))
		{
			printf("Invalid file\n");
			free(CurrentFile);
			return 0;
		}
		printf("\n");
		
		free(CurrentFile);
	}
	else if(argc < 1)
		printf("Error! No arguments!\n"
				"Usage: ./<HiguReader executable> filename.txt\n");
	else
		printf("Error! Too many arguments!\n"
				"Usage: ./<HiguReader executable> filename.txt\n");
}



void *reverse_str(char *str)
{
    char *p1, *p2;

    if (!str || !*str)
    {
        printf("No string passed into reverse function.");
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
}

char *extract_text(const char *const string, const char *const start, const char *const end)
{
    char  *head;
    char  *tail;
    size_t length;
    char  *result;

    if ((string == NULL) || (start == NULL) || (end == NULL))
        return NULL;
	
    length = strlen(start);
    head   = strstr(string, start);
    if (head == NULL)
        return NULL;
	
    head += length;
    tail  = strstr(head, end);
    if (tail == NULL)
        return tail;
	
    length = tail - head;
    result = malloc(1 + length);
    if (result == NULL)
        return NULL;
	
    result[length] = '\0';
    memcpy(result, head, length);
	
		//printf("%s\n", result); //prints unformatted string(for debugging)
	
    return result;
}



void print_title(char *fname)
{
	int title_num; 

	if(strstr(fname, "onik"))
	{
		if(strstr(fname, "_op.txt"))
			printf("\n\n[Onikakushi Prologue]\n\n");
		else if(!strstr(fname, "tips"))
		{
			if(strstr(fname, "000"))
				title_num = 0;
			else if(strstr(fname, "001"))
				title_num = 1;
			else if(strstr(fname, "002"))
				title_num = 2;
			else if(strstr(fname, "003"))
				title_num = 3;
			else if(strstr(fname, "004"))
				title_num = 4;
			else if(strstr(fname, "005"))
				title_num = 5;
			else if( (strstr(fname, "009") && !strstr(fname, "02")) || strstr(fname, "009_00") )
				title_num = 6;
			else if(strstr(fname, "009_02"))
				title_num = 7;
			else if(strstr(fname, "010"))
				title_num = 8;
			else if(strstr(fname, "011"))
				title_num = 9;
			else if(strstr(fname, "012"))
				title_num = 10;
			else if(strstr(fname, "013"))
				title_num = 11;
			else if( (strstr(fname, "014") && !strstr(fname, "02")) || strstr(fname, "014_00") )
				title_num = 12;
			else if(strstr(fname, "014_02"))
				title_num = 13;
			else if( (strstr(fname, "015") && !strstr(fname, "02") && !strstr(fname, "03")) || strstr(fname, "015_00") )
				title_num = 14;
			else if(strstr(fname, "015_02"))
				title_num = 15;
			else if(strstr(fname, "015_03"))
				title_num = 16;
			
			printf("\n\n[Onikakushi Ch.%d]\n\n", title_num);
		}
		else if(strstr(fname, "tips"))
		{
			printf("\n\n[Onikakushi tip - %s]\n", extract_text(fname, "tips_", ".txt"));
		}
	}
	//else(strstr(h_argv[1], ""))
	//{

	//}
}

bool ReadFile(char **g_argv)
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



void CharacterValidation(char *currentLine)
{
  char name[100] = "";
	char *reverse_extract_text;
	bool hasName = false;

	if( strstr(currentLine, "OutputLine(\"<color=") && strstr(currentLine, "</color>\", NULL, NULL, NULL, Line_ContinueAfterTyping") )
		return;
	else if( strstr(currentLine,"GADVMode") && strstr(currentLine, "\"<color=") )
	{
		//Todo - Improve this area
		reverse_str(currentLine);//reverse currentline
		reverse_extract_text = extract_text(currentLine, "_eniL ,LLUN ,\">roloc/<", ">");
		reverse_str(reverse_extract_text);//extract name from reversed line
		reverse_str(currentLine);//turn currentline back to normal
		
		strcat(name, reverse_extract_text);
		
		hasName = true;
		seventh_mod = true;
	}
	else if( (!seventh_mod) && strstr(currentLine,"DrawBustshot") )
  {
    if(strstr(currentLine,"\"me_"))
    {
      strcat(name, "Mion");
      hasName=true;
    }
		else if(strstr(currentLine,"\"oi_")||strstr(currentLine,"\"oisi"))
    {
      strcat(name, "Ooishi");
      hasName=true;
    }
		else if(strstr(currentLine,"\"oni_"))
    {
      strcat(name, "Dark Rena");
      hasName=true;
    }
		else if(strstr(currentLine,"\"re_"))
    {
      strcat(name, "Rena");
      hasName=true;
    }
		else if(strstr(currentLine,"\"ri_"))
    {
      strcat(name, "Rika");
      hasName=true;
    }
		else if(strstr(currentLine,"\"sa_"))
    {
      strcat(name, "Satoko");
      hasName=true;
    }
		else if(strstr(currentLine,"\"ta_"))
    {
      strcat(name, "Takano");
      hasName=true;
    }
		else if(strstr(currentLine,"\"tm_")||strstr(currentLine,"\"tomi"))
    {
      strcat(name, "Tomitake");
      hasName=true;
    }
		else if(strstr(currentLine,"\"si_"))
    {
      strcat(name, "Shion");
      hasName=true;
    }
		else if(strstr(currentLine,"\"wata_mion"))
    {
      strcat(name, "Dark Mion");
      hasName=true;
    }
		else if(strstr(currentLine,"\"wata_rena"))
    {
      strcat(name, "Depressed Rena");
      hasName=true;
    }
		else if(strstr(currentLine,"\"ir_"))
    {
      strcat(name, "Irie");
      hasName=true;
    }
		else if(strstr(currentLine,"\"ti_")||strstr(currentLine,"\"tie"))
    {
      strcat(name, "Chie");
      hasName=true;
    }
		else if(strstr(currentLine,"\"aka_"))
    {
      strcat(name, "Akane");
      hasName=true;
    }
		else if(strstr(currentLine,"\"kasa"))
    {
      strcat(name, "Kasai");
      hasName=true;
    }
		else if(strstr(currentLine,"\"ke"))
    {
      strcat(name, "Negative Ooishi");
      hasName=true;
    }
		else if(strstr(currentLine,"\"kei_"))
    {
      strcat(name, "Keiichi");
      hasName=true;
    }
		else if(strstr(currentLine,"\"sato"))
    {
      strcat(name, "Satoshi");
      hasName=true;
    }
		else if(strstr(currentLine,"\"tetu"))
    {
      strcat(name, "Teppei");
      hasName=true;
    }
		else if(strstr(currentLine,"\"aks_"))
    {
      strcat(name, "Akasaka");
      hasName=true;
    }
		else if(strstr(currentLine,"\"ha_"))
    {
      strcat(name, "Hanyuu");
      hasName=true;
    }
		else if(strstr(currentLine,"\"rina_"))
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
  //printf("%d\n", seventh_mod);
}

void LineValidation(char *currentLine)
{
  if( (strstr(currentLine,identifier_1) && (!strstr(currentLine, "GADVMode"))) || strstr(currentLine, identifier_2) || strstr(currentLine,"Line_Normal"))
  {
		//Todo - Improve this area

    int i, len;
		char subLine[500];
		char *open = "NULL, \"";//string starting with |NULL, "|
		char *end = "\",";//string ending with |",|
		
		currentLine = extract_text(currentLine, open, end);//finds out a string that starts with |NULL, "| and ends with |",|
		len = strlen(currentLine);
	
    for (i=0;i<len;i++)
    { 
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