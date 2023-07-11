#ifndef _MAIN_H_
#define _MAIN_H_

#define BUFFER_SIZE 1024

/**
 * struct buffer_s - struct for buffer
 * @buf: Buffer
 * @start: First memory address of buff
 *
 * Description: A temporary buffer for reading file
 */
typedef struct buffer_s
{
	char *buf;
	char *start;
} buffer_t;

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* _MAIN_H_ */
