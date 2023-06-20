#include "dog.h"

/**
 * free_dog - frees memories allocated for dogs
 * @d: A pointer to dog_t type declaration name
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
