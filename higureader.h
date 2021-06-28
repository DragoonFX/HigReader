#ifndef HigReaderHeader
#define HigReaderHeader

FILE *CurrentFile;
FILE *CurrentSubFile;

char identifier_1[19] = "";
char identifier_2[30] = "";
bool seventh_mod = false;

//void *reverse_str(char *str);
char *extract_text(const char *const string, const char *const start, const char *const end);

void print_title(char *fname);
bool ReadFile(char *file_name);

void CharacterValidation(char *currentLine);
void LineValidation(char *currentLine);
void call_script(char script_name[50], char script_section[50]);

#endif

