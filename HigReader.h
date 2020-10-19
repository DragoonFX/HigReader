#ifndef HigReaderHeader
#define HigReaderHeader

char FileName[100];
FILE *CurrentFile;
bool IsEnglish;
char identifier[19];

void GetFileName();
bool ReadFile();
void LineValidation(char *currentLine);
void CharacterValidation(char *currentLine);

#endif

