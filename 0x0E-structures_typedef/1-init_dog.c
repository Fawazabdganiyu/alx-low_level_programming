#include "dog.h"

/**
 * init_dog - Initialize a variable of type struct dog
 * @d: The struct declaration name.
 * @name: The first Varable.
 * @age: The second variable.
 * @owner: The third variable.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
