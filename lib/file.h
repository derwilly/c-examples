/* file.h
 * Ferdinand Saufler
 * 06.11.2014
 */

int file_exists(const char *path);
int directory_exists(const char* path);
unsigned long get_filesize(const char *path);
void get_format_size(unsigned long size, char* buf);
