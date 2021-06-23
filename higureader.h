#ifndef HigReaderHeader
#define HigReaderHeader

FILE *CurrentFile;
char identifier_1[19];
char identifier_2[30];

void print_title(char *fname);
bool ReadFile(char **g_argv);

void *reverse_str(char *str);
char *extract_text(const char *const string, const char *const start, const char *const end);


void CharacterValidation(char *currentLine);
void LineValidation(char *currentLine);

#endif

