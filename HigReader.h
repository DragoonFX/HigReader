#ifndef HigReaderHeader
#define HigReaderHeader

char FileName[100];
FILE *CurrentFile;

void GetFileName();
bool ReadFile();
void LineValidation(char *currentLine);

#endif
