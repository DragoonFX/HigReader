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
		
		if(!ReadFile(argv[1]))
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
	int title_num, flag;
	
	flag = 1;

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
	else if(strstr(fname, "wata"))
	{
		if(!strstr(fname, "tips") && !strstr(fname, "_ep_"))
		{
			if(strstr(fname, "001"))
				title_num = 1;
			else if(strstr(fname, "002"))
				title_num = 2;
			else if(strstr(fname, "003"))
				title_num = 3;
			else if(strstr(fname, "004"))
				title_num = 4;
			else if(strstr(fname, "005"))
				title_num = 5;
			else if(strstr(fname, "006"))
				title_num = 6;
			else if(strstr(fname, "007"))
				title_num = 7;
			else if(strstr(fname, "008"))
				title_num = 8;
			else if( (strstr(fname, "009") && !strstr(fname, "02")) || strstr(fname, "009_00") )
				title_num = 9;
			else if(strstr(fname, "009_02"))
				title_num = 10;
			else if( (strstr(fname, "010") && !strstr(fname, "02") && !strstr(fname, "03") && !strstr(fname, "04")) || strstr(fname, "010_00") )
				title_num = 11;
			else if(strstr(fname, "010_02"))
				title_num = 12;
			else if(strstr(fname, "010_03"))
				title_num = 13;
			else if(strstr(fname, "010_04"))
				title_num = 14;
			else if( (strstr(fname, "011") && !strstr(fname, "02")) || strstr(fname, "011_00") )
				title_num = 15;
			else if(strstr(fname, "011_02"))
				title_num = 16;
			else if( (strstr(fname, "012") && !strstr(fname, "02") && !strstr(fname, "03")) || strstr(fname, "012_00") )
				title_num = 17;
			else if(strstr(fname, "012_02"))
				title_num = 18;
			else if(strstr(fname, "012_03"))
				title_num = 19;
			
			printf("\n\n[Watanagashi Ch.%d]\n\n", title_num);
		}
		else if(strstr(fname, "_ep_"))
		{
			if(strstr(fname, "_ep_01"))
				printf("\n\n[Watanagashi Epilogue 1]\n\n");
			else 
				printf("\n\n[Watanagashi Epilogue 2]\n\n");
		}
		else if(strstr(fname, "tips"))
		{
			printf("\n\n[Watanagashi tip - %s]\n", extract_text(fname, "tips_", ".txt"));
		}
	}
	else if(strstr(fname, "tata"))
	{
		if(!strstr(fname, "tips") && !strstr(fname, "_ep"))
		{
			if(strstr(fname, "001"))
				title_num = 1;
			else if(strstr(fname, "002"))
				title_num = 2;
			else if(strstr(fname, "003"))
				title_num = 3;
			else if(strstr(fname, "004"))
				title_num = 4;
			else if(strstr(fname, "005"))
				title_num = 5;
			else if( (strstr(fname, "008") && !strstr(fname, "02")) || strstr(fname, "008_00") )
				title_num = 6;
			else if(strstr(fname, "008_02"))
				title_num = 7;
			else if( (strstr(fname, "009") && !strstr(fname, "02")) || strstr(fname, "009_00") )
				title_num = 8;
			else if(strstr(fname, "009_02"))
				title_num = 9;
			else if( (strstr(fname, "010") && !strstr(fname, "02") && !strstr(fname, "03") && !strstr(fname, "04")) || strstr(fname, "010_00") )
				title_num = 10;
			else if(strstr(fname, "010_02"))
				title_num = 11;
			else if(strstr(fname, "010_03"))
				title_num = 12;
			else if(strstr(fname, "010_04"))
				title_num = 13;
			else if( (strstr(fname, "011") && !strstr(fname, "02") && !strstr(fname, "03")) || strstr(fname, "011_00") )
				title_num = 14;
			else if(strstr(fname, "011_02"))
				title_num = 15;
			else if(strstr(fname, "011_03"))
				title_num = 16;
			else if(strstr(fname, "012"))
				title_num = 17;
			else if( (strstr(fname, "013") && !strstr(fname, "02")) || strstr(fname, "013_00") )
				title_num = 18;
			else if(strstr(fname, "013_02"))
				title_num = 19;
			else if(strstr(fname, "014"))
				title_num = 20;
			
			printf("\n\n[Tatarigoroshi Ch.%d]\n\n", title_num);
		}
		else if(strstr(fname, "_ep"))
		{
			if(strstr(fname, "_ep01"))
				printf("\n\n[Tatarigoroshi Epilogue 1]\n\n");
			else 
				printf("\n\n[Tatarigoroshi Epilogue 2]\n\n");
		}
		else if(strstr(fname, "tips"))
		{
			printf("\n\n[Tatarigoroshi tip - %s]\n", extract_text(fname, "tips_", ".txt"));
		}
	}
	else if(strstr(fname, "hima"))
	{
		if(!strstr(fname, "tips"))
		{
			if(strstr(fname, "001"))
				title_num = 1;
			else if( (strstr(fname, "002") && !strstr(fname, "_02") && !strstr(fname, "03")) || strstr(fname, "002_00") )
				title_num = 2;
			else if(strstr(fname, "002_02"))
				title_num = 3;
			else if(strstr(fname, "002_03"))
				title_num = 4;
			else if( (strstr(fname, "003") && !strstr(fname, "02") && !strstr(fname, "_03") && !strstr(fname, "03a") && !strstr(fname, "04") && !strstr(fname, "05")) || strstr(fname, "003_00") )
				title_num = 5;
			else if(strstr(fname, "003_02"))
				title_num = 6;
			else if(strstr(fname, "003_03") && !strstr(fname, "03a"))
				title_num = 7;
			else if(strstr(fname, "003_03a"))
			{
				printf("\n\n[Himatsubushi Ch.7-1]\n\n");
				flag = 0;
			}
			else if(strstr(fname, "003_04"))
				title_num = 8;
			else if(strstr(fname, "003_05"))
				title_num = 9;
			else if(strstr(fname, "004"))
				title_num = 10;
			else if(strstr(fname, "badend"))
			{
				printf("\n\n[Himatsubushi Bad-End]\n\n");
				flag = 0;
			}
			
			if(flag)
				printf("\n\n[Himatsubushi Ch.%d]\n\n", title_num);
		}
		else if(strstr(fname, "tips"))
		{
			printf("\n\n[Himatsubushi tip - %s]\n", extract_text(fname, "tips_", ".txt"));
		}
	}
}

bool ReadFile(char *file_name)
{
  //Can we retrieve file?
  if ((CurrentFile=fopen(file_name,"r")) == NULL)
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
	char *extract_name_0 = "";
	char *extract_name_1 = "";
	bool hasName = false;

	if( strstr(currentLine, "OutputLine(\"<color=") && strstr(currentLine, "</color>\", NULL, NULL, NULL, Line_ContinueAfterTyping") )
		return;
	else if( strstr(currentLine,"OutputLine(NULL, NULL, ") && strstr(currentLine, "</color>\", NULL, Line_") )
	{
		extract_name_0 = extract_text(currentLine, ">", "</color>\", NULL, Line_");
		
		strcat(name, extract_name_0);
		
		hasName = true;
		seventh_mod = true;
	}
	else if( strstr(currentLine,"GADVMode") && strstr(currentLine, "\"<color=") )
	{
		extract_name_0 = extract_text(currentLine, "</color>\", NULL, \"<color=", "ine_");
		//printf("%s\n", reverse_extract_text_0); //for debugging
		extract_name_1 = extract_text(extract_name_0, ">", "</color>");
		//printf("%s\n", reverse_extract_text_1); //for debugging
		
		strcat(name, extract_name_1);
		
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
    //printf("\n[%s]\n", name); //for ddebugging
  }
  
  strcpy(name, "");
  //printf("%d\n", seventh_mod); //for debugging
}

void LineValidation(char *currentLine)
{
  if( (strstr(currentLine,identifier_1) && (!strstr(currentLine, "GADVMode"))) || strstr(currentLine, identifier_2) || strstr(currentLine,"Line_Normal"))
  {
		//Todo - Improve this area

    int i, len;
		char subLine[500];
		char *currentLine_2 = currentLine;
		char *open = "NULL, \"";//string starting with |NULL, "|
		char *end = "\",";//string ending with |",|
		
		currentLine_2 = extract_text(currentLine_2, open, end);//finds out a string that starts with |NULL, "| and ends with |",|
		len = strlen(currentLine_2);
	
    for(i=0;i<len;i++)
    { 
	  	if(currentLine_2[0] == '\\' && currentLine_2[1] == 'n')
      {
				break;
	  	}
      //Filter out special characters
	  	if(currentLine_2[i] != '\n' && currentLine_2[i] != '\\')
	  	{
				strncat(subLine, &currentLine_2[i], 1);
	  	}
    }
	
    printf("%s\n", subLine);
    strcpy(subLine, "");
  }
  
  if( strstr(currentLine, "ModCallScriptSection") && strstr(currentLine, "0x") )
  {
		char *main_script_name, *main_script_section;
		
		main_script_name = extract_text(currentLine, "(\"", "\",");
		main_script_section = extract_text(currentLine, ",\"", "\")");
		
		//printf("%s %s\n", main_script_name, main_script_section); //for debugging
		
		call_script(main_script_name, main_script_section);
	}
}

void call_script(char script_name[50], char script_section[50])
{
	char script_full_dir[50] = "script/";
	bool ending_flag = false;
	bool script_section_found = false;
	
  strcat(script_full_dir, script_name);
  strcat(script_full_dir, ".txt");
  
	//printf("%s | %s\n", script_full_dir, script_section); //for debugging
	
	if( (CurrentSubFile=fopen(script_full_dir,"r")) == NULL )
  {
    exit(1);
  }
  
  char *script_currentLine = NULL;
  size_t len = 0;
  size_t script_len = 0;
  ssize_t read;
  
  
  while(!ending_flag)
  {
		while( (read = getline(&script_currentLine, &len, CurrentSubFile)) != EOF )
		{
			if(strstr(script_currentLine, script_section))
				script_section_found = true;
			
			if(script_section_found)
			{
				script_len = strlen(script_currentLine);
				
				CharacterValidation(script_currentLine);
				LineValidation(script_currentLine);
				
				if( (script_len == 2) && strstr(script_currentLine, "}") )
				{
					ending_flag = true;
					break;
				}
			}
		}
	}
	free(script_currentLine);
}
