#include <stdlib.h>
#include "main.h"

/**
 * *_realloc - raeallocates a memory block using malloc and free
 * @ptr: pointers to the memory previsouly allocated by malloc
 * @old_size: sizee of the allocated memory for ptr
 * @new_size: nnew size of the new memory block
 *
 * Return: ppointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr1;
	char *old_ptr;
	unsigned int nn;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	if (!ptr)
		return (malloc(new_size));

	ptr1 = malloc(new_size);
	if (!ptr1)
		return (NULL);

	old_ptr = ptr;

	if (new_size < old_size)
	{
		for (nn = 0; nn < new_size; nn++)
			ptr1[nn] = old_ptr[nn];
	}

	if (new_size > old_size)
	{
		for (nn = 0; nn < old_size; nn++)
			ptr1[nn] = old_ptr[nn];
	}

	free(ptr);
	return (ptr1);
}
