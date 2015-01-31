/*
 * file.h
 * Ferdinand Saufler <mail@saufler.de>
 * 06.11.2014
 */
 
int file_exists(const char *path);
void get_format_size(unsigned long size, char* buf);
int directory_exists(const char* path);
int count_words(const char *sentence);
