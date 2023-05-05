#ifndef _DOG_H_
#define _DOG_H_

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

/**
 * dog_t -typedef for struct dog
 */
typedef struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* _DOG_H_ */