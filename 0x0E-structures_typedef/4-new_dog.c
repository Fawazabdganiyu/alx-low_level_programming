#include "dog.h"

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
dog_t *new_dog(char *name, float age, char *owner);

/**
 * _strlen - calculate the string lenght
 * @s: The given string
 *
 * Return: The lenght of the string
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;

	return (i);
}

/**
 * _strcpy -  copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy to
 * @src: string source
 *
 * Return: copied string in dest.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: the name of the new dog
 * @age: the age of the new dog
 * @owner: The owner of the new dog
 *
 * Return: A pointer to the created new dog
 *	NULL if the function fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new;

	new = malloc(sizeof(dog_t));
	if (new == NULL)
		return (NULL);

	new->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (new->name == NULL)
	{
		free(new);
		return (NULL);
	}

	new->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (new->owner == NULL)
	{
		free(new->name);
		free(new);
		return (NULL);
	}

	_strcpy(new->name, name);
	_strcpy(new->owner, owner);

	new->age = age;

	return (new);
}
