#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <unistd.h>

int create_file(const char *filename, char *text_content);

#endif /* _MAIN_H_ */
