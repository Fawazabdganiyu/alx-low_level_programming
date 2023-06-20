#ifndef _DOG_H_
#define _DOG_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * dog_t -typedef for struct dog
 */
typedef struct dog dog_t;

/**
 * struct dog - Struct name
 * @name: The first member
 * @age: The second member.
 * @owner: The third member
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif /* _DOG_H_ */
