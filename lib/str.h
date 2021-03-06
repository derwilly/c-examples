/* str.h
 * Ferdinand Saufler
 * 05.02.2014
 */

int starts_with(char* pattern, char* str);
void to_upper(char *str);
void to_lower(char *str);
void print_bits(int value);
char *remove_blanks(char *str);
void remove_newline(char *str);
unsigned count_char(char *str, const char c);
unsigned long count_words(const char *sentence);
unsigned long strlength(const char *str);
