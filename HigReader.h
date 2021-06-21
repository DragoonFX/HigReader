#ifndef HigReaderHeader
#define HigReaderHeader

FILE *CurrentFile;
char identifier[19];

bool ReadFile(int g_argc, char **g_argv);
char *extract(const char *const string, const char *const left, const char *const right);
void LineValidation(char *currentLine);
void CharacterValidation(char *currentLine);

#endif

